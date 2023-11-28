#pragma once
#include "cConsole.h"
#include"Input.h"
#include"Header.h"

using namespace std;
class cMenu
{
    
public:
    int runMenu(HDC* hdc, Render_State* a, Input* input, HWND* window);
    void playMusic();
    void stopMusic();
};


