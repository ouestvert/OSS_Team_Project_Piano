#include "raylib.h"
#include "note_io.h"

int main(void)
{
    InitWindow(640, 360, "Team Piano - raylib Test");
    SetTargetFPS(60);
    InitAudioDevice();
    if (!InitNoteIO())
{
    CloseAudioDevice();
    CloseWindow();
    return 1;
}

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawText("Hello, raylib!", 32, 32, 32, DARKBLUE);
        EndDrawing();
    }

    UnloadNoteIO();
    CloseAudioDevice();
    CloseWindow();
    return 0;
}