#include "raylib.h"
#include "audio_engine.h"

int main(void)
{
    InitWindow(1000, 600, "Team Piano - raylib Test");
    SetTargetFPS(60);
    ReadWav();
    while (!WindowShouldClose()) 
    {
        
    }

    
    CloseWindow();
    return 0;
}