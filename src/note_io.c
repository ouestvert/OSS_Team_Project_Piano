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
    if (IsKeyPressed(KEY_A)) PlaySound(notes[0]);   // C4 도
    if (IsKeyPressed(KEY_W)) PlaySound(notes[1]);   // C#4
    if (IsKeyPressed(KEY_S)) PlaySound(notes[2]);   // D4 레
    if (IsKeyPressed(KEY_E)) PlaySound(notes[3]);   // D#4
    if (IsKeyPressed(KEY_D)) PlaySound(notes[4]);   // E4 미
    if (IsKeyPressed(KEY_F)) PlaySound(notes[5]);   // F4 파
    if (IsKeyPressed(KEY_T)) PlaySound(notes[6]);   // F#4
    if (IsKeyPressed(KEY_G)) PlaySound(notes[7]);   // G4 솔
    if (IsKeyPressed(KEY_Y)) PlaySound(notes[8]);   // G#4
    if (IsKeyPressed(KEY_H)) PlaySound(notes[9]);   // A4 라
    if (IsKeyPressed(KEY_U)) PlaySound(notes[10]);  // A#4
    if (IsKeyPressed(KEY_J)) PlaySound(notes[11]);  // B4 시
}

void UnloadNoteIO(void)
{
    for (int i = 0; i < NOTE_COUNT; i++)
    {
        UnloadSound(notes[i]);
    }
}



