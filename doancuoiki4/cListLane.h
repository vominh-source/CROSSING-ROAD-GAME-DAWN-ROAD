#pragma once
#include"cLane.h"
using namespace std;
class cListLane
{
private:
	static vector<cLane*> lanes;
	static int numLanes;
public:
	
	cListLane();
	~cListLane();
	void Create_Lane(int NumberObj);
	vector<cLane*> Get_ListLane();
};

