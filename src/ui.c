#include "raylib.h"
#include "ui.h"
#include "recording.h"
#define RX 220
#define RY 60
#define RW 560
#define RH 28

int CurrentKey = -1;

static double pressedUntil[13] = { 0 };                
static const int whiteNote[7] = { 0, 2, 4, 5, 7, 9, 11 }; 
static const int blackNote[7] = { 1, 3, -1, 6, 8, 10, -1 };
static const char *whiteName[7]={"C", "D", "E", "F", "G", "A", "B"};
static const char *noteName[12] = { "C4", "C#4", "D4", "D#4", "E4", "F4", "F#4", "G4", "G#4", "A4", "A#4", "B4" };
static const int isSharp[12] = { 0, 1, 0, 1, 0, 0, 1, 0, 1, 0, 1, 0 };


void UIInput(int key)
{
    CurrentKey = key;
    
    if (key >= 0 && key < 13)       
    {
        pressedUntil[key] = GetTime() + 0.2;
    }
}

static void DrawNoteGrid(void)                                                
{
    for (int n = 0; n < 12; n++)
    {
        int y = RY + (11 - n) * RH;

        Color rowColor = WHITE;
        if (isSharp[n])
        {
            rowColor = LIGHTGRAY;
        }

        DrawRectangle(RX, y, RW, RH, rowColor);
        DrawRectangleLines(RX, y, RW, RH, GRAY);
        DrawText(noteName[n], RX - 50, y + (RH - 14) / 2, 14, BLACK);
    }
}

void DrawRecording(){
    if(CurrentKey==13) {
            if(IsRecording()) {
                RecordingStop();
                
            }
            else {
                RecordingStart();
                
            }
            
    }
    if(IsRecording())  DrawText("Record", 100 , 0, 30, RED);



}

void DrawPlaying(){
    if(CurrentKey == 14){
        DrawText("Play", 250, 0, 30, GREEN);
    }
}
void DrawPianoUI(void)
{
    DrawNoteGrid();


    int startX = RX;
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