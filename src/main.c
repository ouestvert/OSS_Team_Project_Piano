#include "raylib.h"
#include "note_io.h"
#include "ui.h"
#include "recording.h"


int main(void)
{
    InitWindow(1000, 600, "Team Piano - raylib Test");
    SetTargetFPS(60);

    InitAudioDevice();
    PianoSound();
    
    while (!WindowShouldClose()) 
    {   if(IsKeyPressed(KEY_P)) RecordingStart();
        if(IsKeyPressed(KEY_T)) RecordingStop();

        int key = Keypress();

        
        UIInput(key);
        RecordingInput(key);

        BeginDrawing();
        ClearBackground(RAYWHITE);
        EndDrawing();
        
    }

    
    CloseAudioDevice();
    CloseWindow();
    return 0;
}