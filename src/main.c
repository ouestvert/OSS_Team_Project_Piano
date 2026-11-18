#include "raylib.h"
#include "note_io.h"
#include "ui.h"
#include "recording.h"
#include "audio_engine.h"

int main(void)
{
    InitWindow(1000, 600, "Team Piano - raylib Test");
    SetTargetFPS(60);
    InitAudioDevice();
    if (!InitNoteIO())
    {
    CloseAudioDevice();
    CloseWindow();
    return 1;
    }
    ReadNote();
    while (!WindowShouldClose()) 
    {
        UpdateNoteIO();
        
        int keyMap[12] = 
        { //key mapping for the 12 notes
            KEY_A, KEY_W, KEY_S, KEY_E, KEY_D, KEY_F,
            KEY_T, KEY_G, KEY_Y, KEY_H, KEY_U, KEY_J
        };

   
        bool pressed[12]={false};

        // R 키: 녹음 켜기/끄기, P 키:재생
        if(IsKeyPressed(KEY_R)){
            if(isRecording()) RecordingStop();
            else RecordingStart();
        }

        if(IsKeyPressed(KEY_P)) PlaybackStart();

         for (int i = 0; i < 12; i++)
        {   
            if(IsKeyPressed(keyMap[i])) RecordingAdd(i);
            if (IsKeyDown(keyMap[i]))
            {
                pressed[i] = true;
            }
        }

        PlaybackUpdate(pressed);

        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawPianoUI(pressed);
        EndDrawing();
    }

    UnloadNoteIO();
    CloseAudioDevice();
    CloseWindow();
    return 0;
}