#include "cCar.h"
void cCar::assignInitSize()
{
	const_width = width = 187;
	const_height = height = 100;
}

cCar::cCar()
{
	this->filename = "bus.bmp";
	this->width = 187;
	this->height = 100;
	this->const_height = 187;
	this->const_width = 100;
}
string cCar::getObjectFileName()
{
	return filename;
}
