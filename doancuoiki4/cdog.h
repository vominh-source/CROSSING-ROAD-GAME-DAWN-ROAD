#pragma once
#include "cObject.h"

class cDog : public cObject
{
	string filename;
public:
	cDog();
	void assignInitSize();
	string getObjectFileName();

};

