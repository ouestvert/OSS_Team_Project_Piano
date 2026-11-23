#include "raylib.h"
#include "note_io.h"

int main(void)
{
    InitWindow(1000, 600, "Team Piano - raylib Test");
    SetTargetFPS(60);

    Keypress();
    
    while (!WindowShouldClose()) 
    {
        
    }

    
    CloseWindow();
    return 0;
}