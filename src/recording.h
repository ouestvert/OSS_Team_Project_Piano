#ifndef RECORDING_H
#define RECORDING_H

#include <stdbool.h>

#define MAX_EVENTS 1024

typedef struct{
    int note;
    float time;
    bool pressed;
}NonteEvent;

void RecordingStart(void);
void RecordingStop(void);
void RecordingAdd(int note, bool pressed);
void PlaybackStart(void);
void PlaybackUpdate(bool pressed[12]);
bool isRecording(void);
bool isPlaying(void);

#endif