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
	filename = "BigTree.bmp";//BigTree
	this->width = 138;
	this->height = 150;
	this->const_height = 138;
	this->const_width = 150;
}
