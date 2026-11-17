#ifndef RECORDING_H
#define RECORDING_H

#include <stdbool.h>

#define MAX_EVENTS 1024
#define NOTE_COUNT 12


typedef struct{
    int note;
    float time;
    float duration;
}NoteEvent;

void RecordingStart(void);
void RecordingStop(void);
void RecordingAdd(int note);
void PlaybackStart(void);
void PlaybackUpdate(bool pressed[NOTE_COUNT]);
bool isRecording(void);
bool isPlaying(void);
int RecordingGetCount(void);

#endif