#include "raylib.h"
#include "ui.h"

int CurrentKey = -1;

static double pressedUntil[13] = { 0 };                
static const int whiteNote[7] = { 0, 2, 4, 5, 7, 9, 11 }; 
static const int blackNote[7] = { 1, 3, -1, 6, 8, 10, -1 };
static const char *whiteName[7]={"C", "D", "E", "F", "G", "A", "B"};

void UIInput(int key)
{
    CurrentKey = key;

    if (key >= 0 && key < 13)                     
    {
        pressedUntil[key] = GetTime() + 0.2;
    }
}

void DrawPianoUI(void)
{
    int startX = 220;
    int startY = 400;
    int keyWidth = 80;
    int keyHeight = 200;

    for (int i = 0; i < 7; i++)
    {
        int x = startX + i * keyWidth;

        Color keyColor = WHITE;                        
        if (GetTime() < pressedUntil[whiteNote[i]])
        {
            keyColor = SKYBLUE;
        }

        DrawRectangle(x, startY, keyWidth, keyHeight, keyColor); 
        DrawRectangleLines(x, startY, keyWidth, keyHeight, BLACK);
        
        
        int textWidth = MeasureText(whiteName[i], 24);
        DrawText(whiteName[i], x + (keyWidth - textWidth) / 2, startY + keyHeight - 40, 24, BLACK);
   
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