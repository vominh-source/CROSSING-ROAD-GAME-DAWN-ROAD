#include "cObject.h"

void cObject::assignX(int X)
{
	x = X;
}
void cObject::assignY(int Y)
{
	y = Y;
}
void cObject::assignWidth(int W)
{
	width = W;
}
void cObject::assignHeight(int H)
{
	height = H;
}
void cObject::assignConstWidth(int W)
{
	const_width = W;
}
void cObject::assignConstHeight(int H)
{
	const_height = H;
}
void cObject::assignStatus(int s)
{
	status = s;
}
void cObject::assignSign(int s)
{
	sign = s;
}

int cObject::getSign()
{
	return sign;
}
int cObject::getX()
{
	return x;
}
int cObject::getY()
{
	return y;
}
int cObject::getWidth()
{
	return width;
}
int cObject::getHeight()
{
	return height;
}
int cObject::getConstHeight()
{
	return const_height;
}
int cObject::getConstWidth()
{
	return const_width;
}
int cObject::getStatus()
{
	return status;
}

