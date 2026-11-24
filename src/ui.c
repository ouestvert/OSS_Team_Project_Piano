#include "raylib.h"
#include "ui.h"

int CurrentKey = -1;

static double pressedUntil[13] = { 0 };                  // ← 추가
static const int whiteNote[7] = { 0, 2, 4, 5, 7, 9, 11 };  // ← 추가
static const int blackNote[7] = { 1, 3, -1, 6, 8, 10, -1 };

void UIInput(int key)
{
    CurrentKey = key;

    if (key >= 0 && key < 13)                            // ← 추가
    {
        pressedUntil[key] = GetTime() + 0.2;
    }
}

void DrawPianoUI(void)
{
    int startX = 100;
    int startY = 80;
    int keyWidth = 80;
    int keyHeight = 200;

    for (int i = 0; i < 7; i++)
    {
        int x = startX + i * keyWidth;

        Color keyColor = WHITE;                          // ← 추가
        if (GetTime() < pressedUntil[whiteNote[i]])
        {
            keyColor = SKYBLUE;
        }

        DrawRectangle(x, startY, keyWidth, keyHeight, keyColor);  // ← 변경 (WHITE → keyColor)
        DrawRectangleLines(x, startY, keyWidth, keyHeight, BLACK);
    }

    int blackWidth = 40;
    int blackHeight = 100;

    for (int i = 0; i < 7; i++)
    {
        if (blackNote[i] != -1)
        {
            int x = startX + (i + 1) * keyWidth - blackWidth / 2;

            Color blackColor = BLACK;
            if (GetTime() < pressedUntil[blackNote[i]])
            {
                blackColor = BLUE;
            }

            DrawRectangle(x, startY, blackWidth, blackHeight, blackColor);
        }
    }
}