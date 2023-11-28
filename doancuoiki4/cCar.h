#pragma once
#include "cObject.h"
class cCar : public cObject
{
	string filename;
public:
	void assignInitSize();
	cCar();
	string getObjectFileName();

};

