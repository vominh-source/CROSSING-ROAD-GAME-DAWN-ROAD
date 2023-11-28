#include "cBridge.h"
void cBridge::assignInitSize()
{
	const_width = width = 71;
	const_height = height = 100;
}

cBridge::cBridge()
{
	this->filename = "BRI.bmp";
	this->width = 185;
	this->height = 100;
	this->const_height = 100;
	this->const_width = 185;
}
string cBridge::getObjectFileName()
{
	return filename;
}
