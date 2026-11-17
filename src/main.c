#include "raylib.h"
#include "ui.h"

int main(void)
{
    InitWindow(1000, 600, "Team Piano - raylib Test");
    SetTargetFPS(60);
    int keyMap[12] = { //임시 키 설정
        KEY_A, KEY_W, KEY_S, KEY_E, KEY_D, KEY_F,
        KEY_T, KEY_G, KEY_Y, KEY_H, KEY_U, KEY_J
    };

    while (!WindowShouldClose()) {
        bool pressed[12]={false};

         for (int i = 0; i < 12; i++)
        {
            if (IsKeyDown(keyMap[i]))
            {
                pressed[i] = true;
            }
        }
        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawPianoUI(pressed);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}