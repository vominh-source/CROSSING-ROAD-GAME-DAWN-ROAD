#pragma once
#include "cConsole.h"
#include "cPeople.h"
#include "cListObject.h"
#include "time.h"
#include"Header.h"
#include"cListLane.h"
#include "cBridge.h"
#include "Input.h"
class cMap
{
private:
	cPeople people;
	static int level, score;
	vector<cObject*> listObject;
	bool flagMove = false;
	int flagHighScore = 0;
	static int speed;
	static bool flagMenu;
	static bool flagLoad;
	static bool flagSave;
	static int flagStop;
	string playerName;
	int sign[4] = { 1 };
	clock_t start, end;
	double timeUse = 0;
	static bool flagCreateObject;
	static cListObject temp;

	static cListLane temp1;//
	vector<cLane*> lanes;//
	
public:

	void redrawObject(int timeuse, float speed);
	bool checkFlagMenu();
	void setLevel(int);
	void setScore(int);
	void output(bool Sound, HDC* hdc, Render_State* a, Input* input, HWND* window);
	void simulatepeople(Input* input, float dt, Render_State* a);
	bool checkCollison();
	bool checkCollison2(int lane1, int lane2);
	void Endless(int timeUse);

};

