#include "raylib.h"
#include "note_io.h"
#define Note_Count 13

char NotePaths[Note_Count][50];
Sound Note[Note_Count];

char NotePaths[Note_Count][50]=
{
    "asset/note/C4.wav",
    "asset/note/C#4.wav",
    "asset/note/D4.wav",
    "asset/note/D#4.wav",
    "asset/note/E4.wav",
    "asset/note/F4.wav",
    "asset/note/F#4.wav",
    "asset/note/G4.wav",
    "asset/note/G#4.wav",
    "asset/note/A4.wav",
    "asset/note/A#4.wav",
    "asset/note/B4.wav",
    "asset/note/C5.wav",

};


int PianoSound(void)
{

    for(int i=0;i<Note_Count;i++)
    {
        Note[i]=LoadSound(NotePaths[i]);

        if(Note[i]. frameCount==0)
        {
            return 0;
        }
    }

    return 1;

};

int Keypress()
{
    InitAudioDevice();
    PianoSound();

    while(!WindowShouldClose())
    {
        if(IsKeyPressed(KEY_A))
        {
            PlaySound(Note[0]);
        }
        if(IsKeyPressed(KEY_W))
        {
            PlaySound(Note[1]);
        }
        if(IsKeyPressed(KEY_S))
        {
            PlaySound(Note[2]);
        }
        if(IsKeyPressed(KEY_E))
        {
            PlaySound(Note[3]);
        }
        if(IsKeyPressed(KEY_D))
        {
            PlaySound(Note[4]);
        }
        if(IsKeyPressed(KEY_F))
        {
            PlaySound(Note[5]);
        }
        if(IsKeyPressed(KEY_T))
        {
            PlaySound(Note[6]);
        }
        if(IsKeyPressed(KEY_G))
        {
            PlaySound(Note[7]);
        }
        if(IsKeyPressed(KEY_Y))
        {
            PlaySound(Note[8]);
        }
        if(IsKeyPressed(KEY_H))
        {
            PlaySound(Note[9]);
        }
        if(IsKeyPressed(KEY_U))
        {
            PlaySound(Note[10]);
        }
        if(IsKeyPressed(KEY_J))
        {
            PlaySound(Note[11]);
        }
        if(IsKeyPressed(KEY_K))
        {
            PlaySound(Note[12]);
        }

        BeginDrawing();
        ClearBackground(RAYWHITE);
        EndDrawing();
    }

    return 0;
}