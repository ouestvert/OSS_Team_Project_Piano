#include "raylib.h"
#ifndef RECORDING_H
#define RECORDING_H

void RecordingInput(int key);

#include <stdbool.h>

#define MAX_NOTE 500

typedef struct NoteEvent {
    int note;
    float time;
    float duration;
}NoteEvent;

void RecordingInput(int key);

void RecordingStart(void);
void RecordingStop(void);

bool IsRecording(void);

int RecordingGetCount(void);
#endif