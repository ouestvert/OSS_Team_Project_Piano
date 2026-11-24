#include "raylib.h"
#include "ui.h"


int CurrentKey = -1;

void UIInput(int key)
{
    CurrentKey = key;
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
        DrawRectangle(x, startY, keyWidth, keyHeight, WHITE);
        DrawRectangleLines(x, startY, keyWidth, keyHeight, BLACK);
    }

    int blackWidth = 40;
    int blackHeight = 100;

    for (int i = 0; i < 7; i++)
    {
        if (i != 2 && i != 6)
        {
            int x = startX + (i + 1) * keyWidth - blackWidth / 2;
            DrawRectangle(x, startY, blackWidth, blackHeight, BLACK);
        }
    }
}