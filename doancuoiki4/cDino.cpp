#include "cDino.h"


void cDino::assignInitSize()
{
	const_width = width = 225;
	const_height = height = 84;
}

string cDino::getObjectFileName()
{
	return filename;
}
cDino::cDino()
{
	filename = "new2.bmp";
	this->width = 225;
	this->height = 84;
	this->const_height = 84;
	this->const_width = 225;
}
