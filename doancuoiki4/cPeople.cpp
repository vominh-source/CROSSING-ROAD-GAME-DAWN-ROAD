#include "cPeople.h"
bool cPeople::status = 0;
cPeople::cPeople()
{
	height = 250;
	width = 118;
	x = 0;
	y = 500;
}
void cPeople::assignX(int X)
{
	x = X;
}
void cPeople::assignY(int Y)
{
	y = Y;
}
void cPeople::assignChange(int c)
{
	change = c;
}
void cPeople::assignStatus(bool s)
{
	status = s;
}
int cPeople::getX()
{
	return x;
}
int cPeople::getChange()
{
	return change;
}
int cPeople::getY()
{
	return y;
}
int cPeople::getHeight()
{
	return height;
}
int cPeople::getWidth()
{
	return width;
}
bool cPeople::getStatus()
{
	return status;
}
void cPeople::MoveLeft()
{
	x--;
	change = 0;
}
void cPeople::MoveRight()
{
	x++;
	change = 1;
}
void cPeople::MoveDown()
{
	y++;
	change = 2;
}
void cPeople::MoveUp()
{
	y--;
	change = 3;
}

float x = 0.f, y = 0.f;
