#include"Header.h"
#include "cMenu.h"
#include "cConsole.h"
#include "cMap.h"

//#pragma pack(pop)
int WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd) {
	
	srand(static_cast<unsigned int>(std::time(0)));
	ShowCursor(TRUE);
	// Create Window Class
	WNDCLASS window_class = {};
	window_class.style = CS_HREDRAW | CS_VREDRAW;
	window_class.lpszClassName = "Game Window Class";
	window_class.lpfnWndProc = window_callback;
	// Register Class
	RegisterClass(&window_class);
	// Create Window
	HWND window = CreateWindow(window_class.lpszClassName, "Pong - Tutorial", WS_OVERLAPPEDWINDOW | WS_VISIBLE, CW_USEDEFAULT, CW_USEDEFAULT, 1350, 940, 0, 0, hInstance, 0);
	HDC hdc = GetDC(window);
	cConsole console;
	Input input = {};
	Sleep(2000);
	cMenu a;
BEGIN:

	console.textColor(15);
	system("cls");
	int check = a.runMenu(&hdc, &render_state, &input, &window);
	if (check == 1) {// chọn new game
		
		cMap start;
		start.output(1, &hdc, &render_state, &input, &window); //start
		if (start.checkFlagMenu() == true) goto BEGIN;
	}
	if (check == 2) {// chọn load game
		cMap start;
		system("cls");
		if (start.checkFlagMenu() == true) goto BEGIN;
	}
	if (check == 5) {
	
		return 0;
	}
	if (check == 3)//setting
	{
		goto BEGIN;
	}
	if (check == 4)//highscore
	{
		goto BEGIN;
	}
}
	

