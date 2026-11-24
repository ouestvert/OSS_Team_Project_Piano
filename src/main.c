#include "raylib.h"
#include "note_io.h"
#include "ui.h"

int main(void)
{
    InitWindow(1000, 600, "Team Piano - raylib Test");
    SetTargetFPS(60);

    Keypress();
    
    while (!WindowShouldClose()) 
    {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawPianoUI();
        EndDrawing();
    }

    
    CloseWindow();
    return 0;
}