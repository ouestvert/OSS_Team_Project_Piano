#include "raylib.h"
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


int UpdateSound(void)
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

}

