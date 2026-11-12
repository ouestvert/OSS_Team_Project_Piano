#include "raylib.h"

int main(void)
{
    InitWindow(640, 360, "Team Piano - raylib Test");
    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawText("Hello, raylib!", 32, 32, 32, DARKBLUE);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}