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
    PianoSound();
    ReadWav();
    while (!WindowShouldClose()) 
    {   
       

        int key = Keypress();
       
        
        UIInput(key);
        RecordingInput(key);
        
        

        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawPianoUI();
        DrawRecording();
        DrawPlaying();
        EndDrawing();
        
    }

    
    CloseAudioDevice();
    CloseWindow();
    return 0;
}