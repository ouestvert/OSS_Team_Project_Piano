#include "raylib.h"
#include "ui.h"

int CurrentKey = -1;

void UIInput(int key)
{
    CurrentKey = key;
}