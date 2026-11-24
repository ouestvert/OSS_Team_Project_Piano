#include "raylib.h"
#include "recording.h"

int RecordingKey = -1;


static bool isRecording= false;
static int noteCount =0;
static double startTime = 0.0;
static NoteEvent notes[MAX_NOTE];

void RecordingStart(void){
    isRecording = true;
    noteCount = 0;
    startTime = GetTime();
}

void RecordingStop(void){
    isRecording = false;
}
void RecordingInput(int key)
{
    RecordingKey = key;

    if(!isRecording) return;
    if(noteCount >= MAX_NOTE) return;

    double currentTime = GetTime()- startTime;

    notes[noteCount].note =key;
    notes[noteCount].time = currentTime;
    notes[noteCount].duration = 0.0;

    if(noteCount > 0){
        notes[noteCount-1].duration = currentTime - notes[noteCount-1].time;

    }
    noteCount++;
}
bool IsRecording(void){
    return isRecording;
}
