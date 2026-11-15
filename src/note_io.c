#include "raylib.h"

#include "note_io.h"

#define NOTE_COUNT 13

static const char *notePaths[NOTE_COUNT] = {
    "asset/note/C4.wav",
    "asset/note/C#4.wav",
    "asset/note/D4.wav",
    "asset/note/D#4.wav",
    "asset/note/E4.wav",
    "asset/note/F4.wav",
    "asset/note/F#4.wav",
    "asset/note/G4.wav",
    "asset/note/G#4.wav",
    "asset/note/A4.wav",
    "asset/note/A#4.wav",
    "asset/note/B4.wav",
    "asset/note/C5.wav"
};

static Sound notes[NOTE_COUNT];

bool InitNoteIO(void)
{
    for (int i = 0; i < NOTE_COUNT; i++)
    {
        notes[i] = LoadSound(notePaths[i]);

        if (notes[i].frameCount == 0)
        {
            TraceLog(LOG_ERROR, "Failed to load: %s", notePaths[i]);

            for (int j = 0; j < i; j++)
            {
                UnloadSound(notes[j]);
            }

            return false;
        }
    }

    return true;
}

void UpdateNoteIO(void)
{
    // Keyboard input will be implemented next.
}

void UnloadNoteIO(void)
{
    for (int i = 0; i < NOTE_COUNT; i++)
    {
        UnloadSound(notes[i]);
    }
}



