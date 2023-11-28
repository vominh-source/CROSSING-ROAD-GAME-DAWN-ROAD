#pragma once
#include "cObject.h"
class cDino : public cObject
{
	string filename;
public:
	void assignInitSize();
	string getObjectFileName();
	cDino();
};

