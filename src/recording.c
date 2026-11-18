#include "raylib.h"
#include "recording.h"

#define HIGHLIGHT_TIME 0.15f 

static NoteEvent events[MAX_EVENTS];
static int eventCount = 0;
static bool recording = false;
static bool playing = false;
static double startTime = 0.0;
static int playIndex = 0;
static float highlightUntil[NOTE_COUNT] = {0};

void RecordingStart(void){
    eventCount = 0;
    recording = true;
    playing = false;
    startTime = GetTime();
}

void RecordingStop(void){
    recording = false;
}

void RecordingAdd(int note){
    if(!recording) return;
    if(note < 0 || note >= NOTE_COUNT) return;
    if(eventCount >= MAX_EVENTS) return;
    float now = (float)(GetTime()- startTime);
    //앞 음표 듀레이션 업데이트 = 이 음표까지의 거리
    if(eventCount > 0){
        events[eventCount - 1].duration = now - events[eventCount - 1].time;
    }

    events[eventCount].note = note;
    events[eventCount].time = now;
    events[eventCount].duration = 0.0f;
    eventCount++;
}

void PlaybackStart(void){
   if(recording || eventCount == 0) return;
   playing = true;
   playIndex = 0;
   startTime = GetTime();
   for(int i = 0; i < NOTE_COUNT; i++) highlightUntil[i] = 0.0f; 
}

void PlaybackUpdate(bool pressed[NOTE_COUNT]){
    if(!playing) return;

    float now = (float)(GetTime()- startTime);

    while(playIndex < eventCount && events[playIndex].time <= now){
        highlightUntil[events[playIndex].note] = events[playIndex].time +HIGHLIGHT_TIME;
        playIndex++;
    
    }
    for(int i = 0; i < NOTE_COUNT; i++){
        if(now < highlightUntil[i]) pressed[i] = true;
    }
    //방송 종료하고 조명 시간 종료하다
    if(playIndex >= eventCount && now > events[eventCount - 1].time + HIGHLIGHT_TIME) playing = false;
}

bool isRecording(void){
    return recording;
}

bool isPlaying(void){
    return playing;
}

int RecordingGetCount(void){
    return eventCount;
}