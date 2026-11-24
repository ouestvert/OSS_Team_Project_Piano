#include "raylib.h"
#include "recording.h"

int RecordingKey = -1;

void RecordingInput(int key)
{
    RecordingKey = key;
}