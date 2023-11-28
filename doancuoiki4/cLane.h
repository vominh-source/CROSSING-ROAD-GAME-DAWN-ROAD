#pragma once
#include"cObject.h"
#include<vector>
#include"cCar.h"
#include "cDino.h"
#include "cDog.h"
#include"Header.h"
#include"cBridge.h"

class cLane
{
	int numObj;
	vector<cObject*> objs;
	bool direction; //1 is to left, 0 is to right
	int coordY;
	int type; //1 is grass, 2 is road, 3 is river
	string filename;
	int time;
public:
	void SetLaneFilename(string filename);
	string GetLaneFileName();
	cLane(const cLane& a);
	void setNumObj(int n);
	int getNumObj();
	int getY();
	void setY(int y);
	vector<cObject*> getList();
	int getDirection();
	void setDirection(bool a);
	cLane(int numObject, int y);
	cLane();
	~cLane();
	void createObject();
	void setTime(int time);
	int getTime();
	int getType();
	void setType(int type);

};

