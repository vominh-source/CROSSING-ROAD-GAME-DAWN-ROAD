#include "cDog.h"
cDog::cDog()
{
	this->filename = "dog.bmp";
	this->width = 160;
	this->height =99;
	this->const_height = 99;
	this->const_width = 160;
}
string cDog::getObjectFileName()
{
	return filename;
}

void cDog::assignInitSize()
{
	const_width = width = 298;
	const_height = height = SIZELANE;
}
