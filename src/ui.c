#include "raylib.h"
#include "ui.h"

#define WHITE_KEY_COUNT 7
#define WHITE_W 70
#define WHITE_H 130
#define BLACK_W 42
#define BLACK_H 80


static const int  WHITE_NOTE[WHITE_KEY_COUNT]  = { 0, 2, 4, 5, 7, 9, 11 };
static const char *WHITE_NAME[WHITE_KEY_COUNT] = { "C", "D", "E", "F", "G", "A", "B" };


static const int BLACK_NOTE[5]        = { 1, 3, 6, 8, 10 };
static const int BLACK_AFTER_WHITE[5] = { 0, 1, 3, 4, 5 };

void DrawPianoUI(const bool pressed[12])
{
    const Color pressedColor = (Color){ 150, 100, 255, 255 };


    int startX = (GetScreenWidth() - WHITE_KEY_COUNT * WHITE_W) / 2;
    int startY = GetScreenHeight() - WHITE_H - 10;


    for (int i = 0; i < WHITE_KEY_COUNT; i++)
    {
        int x = startX + i * WHITE_W;
        Color c = WHITE;
         if (pressed[WHITE_NOTE[i]])
        {
        c = pressedColor;}

        DrawRectangle(x, startY, WHITE_W, WHITE_H, c);
        DrawRectangleLines(x, startY, WHITE_W, WHITE_H, BLACK);

        int tw = MeasureText(WHITE_NAME[i], 20);
        DrawText(WHITE_NAME[i], x + (WHITE_W - tw) / 2, startY + WHITE_H - 30, 20, BLACK);
    }

    
    for (int i = 0; i < 5; i++)
    {
        int x = startX + (BLACK_AFTER_WHITE[i] + 1) * WHITE_W - BLACK_W / 2;
        Color c = (Color){ 20, 20, 20, 255 };
        if (pressed[BLACK_NOTE[i]])
        {
            c = pressedColor;
        }

        DrawRectangle(x, startY, BLACK_W, BLACK_H, c);
        DrawRectangleLines(x, startY, BLACK_W, BLACK_H, BLACK);
    }
}