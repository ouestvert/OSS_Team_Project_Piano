#include "raylib.h"
#include "ui.h"

int main(void)
{
    InitWindow(640, 360, "Team Piano - raylib Test");
    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        bool pressed[12]={false};
        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawText("Hello, raylib!", 32, 32, 32, DARKBLUE);
        DrawPianoUI(pressed);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}