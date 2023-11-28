#include "cMenu.h"
using namespace std;

int cMenu::runMenu(HDC* hdc, Render_State* a, Input* input, HWND* window) {
    string stringChoice = "new";
    /*---------- CHOOSE MENU ----------*/



    while (true) {
        MSG message;

        for (int i = 0; i < BUTTON_COUNT; i++) {
            (*input).buttons[i].changed = false;
        }

        while (PeekMessage(&message, *window, 0, 0, PM_REMOVE)) {

            switch (message.message) {
            case WM_KEYUP:
            case WM_KEYDOWN: {
                u32 vk_code = (u32)message.wParam;
                bool is_down = ((message.lParam & (1 << 31)) == 0);

#define process_button(b, vk)\
case vk: {\
(*input).buttons[b].changed = is_down != (*input).buttons[b].is_down;\
(*input).buttons[b].is_down = is_down;\
} break;

                switch (vk_code) {
                    process_button(BUTTON_UP, VK_UP);
                    process_button(BUTTON_DOWN, VK_DOWN);
                    process_button(BUTTON_W, 'W');
                    process_button(BUTTON_S, 'S');
                    process_button(BUTTON_LEFT, VK_LEFT);
                    process_button(BUTTON_RIGHT, VK_RIGHT);
                    process_button(BUTTON_ENTER, VK_RETURN);
                }
            } break;

            default: {
                TranslateMessage(&message);
                DispatchMessage(&message);
            }
            }
        }
        loadImage("MainMenu.bmp", *&a, 0, 0);
        if (pressed(BUTTON_ENTER)) {
            break;
        }
        StretchDIBits(*hdc, 0, 0, a->width, a->height, 0, 0, a->width, a->height, a->memory, &a->bitmap_info, DIB_RGB_COLORS, SRCCOPY);
    }
    while (true)
    {
        // bam nut
        MSG message;

        for (int i = 0; i < BUTTON_COUNT; i++) {
            (*input).buttons[i].changed = false;
        }

        while (PeekMessage(&message, *window, 0, 0, PM_REMOVE)) {

            switch (message.message) {
            case WM_KEYUP:
            case WM_KEYDOWN: {
                u32 vk_code = (u32)message.wParam;
                bool is_down = ((message.lParam & (1 << 31)) == 0);

#define process_button(b, vk)\
case vk: {\
(*input).buttons[b].changed = is_down != (*input).buttons[b].is_down;\
(*input).buttons[b].is_down = is_down;\
} break;

                switch (vk_code) {
                    process_button(BUTTON_UP, VK_UP);
                    process_button(BUTTON_DOWN, VK_DOWN);
                    process_button(BUTTON_W, 'W');
                    process_button(BUTTON_S, 'S');
                    process_button(BUTTON_LEFT, VK_LEFT);
                    process_button(BUTTON_RIGHT, VK_RIGHT);
                    process_button(BUTTON_ENTER, VK_RETURN);
                }
            } break;

            default: {
                TranslateMessage(&message);
                DispatchMessage(&message);
            }
            }

        }

        if (pressed(BUTTON_DOWN)) // mui ten xuong 
        {
            if (stringChoice == "new") // neu tu new game bam xuong duoi -> settings
            {
                stringChoice = "load";
            }
            else if (stringChoice == "load") // neu tu load game bam xuong duoi -> leaderboard
            {
                stringChoice = "setting";
            }
            else if (stringChoice == "setting") // neu tu load game bam xuong duoi -> leaderboard
            {
                stringChoice = "leaderboard";
            }
            else if (stringChoice == "help") // neu tu load game bam xuong duoi -> leaderboard
            {
                stringChoice = "credit";
            }
            else if (stringChoice == "leaderboard") // neu tu load game bam xuong duoi -> leaderboard
            {
                stringChoice = "help";
            }
            else if (stringChoice == "credit") // neu tu load game bam xuong duoi -> leaderboard
            {
                stringChoice = "exit";
            }
        }
        else if (pressed(BUTTON_UP)) // mui ten len
        {
            if (stringChoice == "exit") // neu tu settings bam len -> new game
            {
                stringChoice = "credit";
            }
            else if (stringChoice == "credit") // neu tu leaderboard bam len -> load game
            {
                stringChoice = "help";
            }
            else if (stringChoice == "help") // new tu exit bam len -> load game
            {
                stringChoice = "leaderboard";
            }
            else if (stringChoice == "leaderboard") // new tu exit bam len -> load game
            {
                stringChoice = "setting";
            }
            else if (stringChoice == "setting") // new tu exit bam len -> load game
            {
                stringChoice = "load";
            }
            else if (stringChoice == "load") // new tu exit bam len -> load game
            {
                stringChoice = "new";
            }
        }
        else if (pressed(BUTTON_ENTER)) {
            if (stringChoice == "new") return 1;
            if (stringChoice == "load") return 2;
            if (stringChoice == "setting") return 3;
            if (stringChoice == "leaderboard") return 4;
            if (stringChoice == "exit") return 5;
            if (stringChoice == "help") return 6;
            if (stringChoice == "credit") return 7;
        }
        if (stringChoice == "new") {
            loadImage("NewGame.bmp", *&a, 0, 0);

            //   StretchDIBits(*hdc, 0, 0, a->width, a->height, 0, 0, a->width, a->height, a->memory, &a->bitmap_info, DIB_RGB_COLORS, SRCCOPY);
        }
        if (stringChoice == "load") {
            loadImage("LoadGame.bmp", *&a, 0, 0);
            //  StretchDIBits(*hdc, 0, 0, a->width, a->height, 0, 0, a->width, a->height, a->memory, &a->bitmap_info, DIB_RGB_COLORS, SRCCOPY);
        }
        if (stringChoice == "setting") {
            loadImage("Setting.bmp", *&a, 0, 0);
            //   StretchDIBits(*hdc, 0, 0, a->width, a->height, 0, 0, a->width, a->height, a->memory, &a->bitmap_info, DIB_RGB_COLORS, SRCCOPY);
        }
        if (stringChoice == "leaderboard") {
            loadImage("Leaderboard.bmp", *&a, 0, 0);
            //   StretchDIBits(*hdc, 0, 0, a->width, a->height, 0, 0, a->width, a->height, a->memory, &a->bitmap_info, DIB_RGB_COLORS, SRCCOPY);
        }
        if (stringChoice == "help") {
            loadImage("Help.bmp", *&a, 0, 0);
            //  StretchDIBits(*hdc, 0, 0, a->width, a->height, 0, 0, a->width, a->height, a->memory, &a->bitmap_info, DIB_RGB_COLORS, SRCCOPY);
        }
        if (stringChoice == "credit") {
            loadImage("Credit.bmp", *&a, 0, 0);
            //   StretchDIBits(*hdc, 0, 0, a->width, a->height, 0, 0, a->width, a->height, a->memory, &a->bitmap_info, DIB_RGB_COLORS, SRCCOPY);
        }
        if (stringChoice == "exit") {
            loadImage("Exit.bmp", *&a, 0, 0);
            // StretchDIBits(*hdc, 0, 0, a->width, a->height, 0, 0, a->width, a->height, a->memory, &a->bitmap_info, DIB_RGB_COLORS, SRCCOPY);
        }

        StretchDIBits(*hdc, 0, 0, a->width, a->height, 0, 0, a->width, a->height, a->memory, &a->bitmap_info, DIB_RGB_COLORS, SRCCOPY);
    }
}

void cMenu::playMusic() {
    PlaySound(TEXT("sounds\\bg.wav"), NULL, SND_LOOP || SND_ASYNC);
}
void cMenu::stopMusic() {
    //PlaySound(NULL, NULL, NULL);
}
