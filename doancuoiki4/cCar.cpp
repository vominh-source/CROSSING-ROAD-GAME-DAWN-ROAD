#include "cCar.h"
void cCar::assignInitSize()
{
	const_width = width = 160;
	const_height = height = 99;
}

cCar::cCar()
{
	this->filename = "dog.bmp";
	this->width = 160;
	this->height = 99;
	this->const_height = 99;
	this->const_width = 160;
}
string cCar::getObjectFileName()
{
	return filename;
}
