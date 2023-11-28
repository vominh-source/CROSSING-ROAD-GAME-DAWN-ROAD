#pragma once
#include "cObject.h"
class cBridge : public cObject
{
	string filename;
public:
	void assignInitSize();
	cBridge();
	string getObjectFileName();

};


