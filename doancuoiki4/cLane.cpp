#include "cLane.h"
void cLane::createObject() {//khoi tao cho moi lane voi so numbObject quy dinh
	
		//int startPos = 0; //move from left
		//int startPos = 1350; //move from right
		if (type == 3){ //water
			cObject* temp = new cDog;
			temp->assignX(getRandomNumber(0, 1334 - temp->getConstWidth()));
			objs.push_back(temp);
		}
		else if (direction == 1) {
			int disX = 0;
			while (objs.size() < numObj) {
				cObject* temp=NULL;
				if (type == 2) //road
				{
					temp = new cCar;
				}
				else //grass
				{
					temp = new cDino;
				}
				int newX = disX + getRandomNumber(0, 1334/numObj);

				temp->assignX(newX);//tuc la chia lane duong thanh cac khoang
				//sau do x duoc random generate trong cai khoang nay
				//temp->assignX(getRandomNumber(startPos, startPos + saveDistance));
				//startPos += temp.width; //move from right
				//startPos -= temp.width; //move from left
				disX += newX + temp->getWidth();//temp->getwith() tranh vi tri x ms trung vao khoang width cua xe cu: /   x  /

				temp->assignY(coordY);
				temp->assignStatus(1); //right to left
				objs.push_back(temp);
			}
		}
		else {
			int disX = 1334;
			while (objs.size() < numObj) {
				cObject* temp=NULL;
				if (type == 2)
				{
					temp = new cCar;
				}
				else if (type == 1)
				{
					temp = new cDino;
				}
				int newX = disX - getRandomNumber(0, 1334 / numObj) - temp->getWidth();
				//temp->assignX(getRandomNumber(1350 - (int)1350 / numObj, 1350 - temp->getWidth()));
				temp->assignX(newX);
				//temp->assignX(getRandomNumber(startPos, startPos + saveDistance));
				//startPos += temp.width; //move from right
				//startPos -= temp.width; //move from left
				disX -=  (1334 - newX);
				temp->assignY(coordY);
				temp->assignStatus(0); //left to right
				objs.push_back(temp);
			}
		}
		
}
void cLane::SetLaneFilename(string filename)
{
	this->filename = filename;
}
string cLane::GetLaneFileName()
{
	return filename;
}
cLane::cLane(const cLane& a) {
	numObj = a.numObj;
	objs = a.objs;
	direction = a.direction;
	coordY = a.coordY;
	type = a.type;
	filename = a.filename;
	time = a.time;
}
void cLane::setNumObj(int n) {
	numObj = n;
}
int cLane::getNumObj() {
	return numObj;
}
/*int getOrderobj()
{
	return orderObj;
}
void setOrderObj(int order)
{
	this->orderObj = order;
}*/
int cLane::getY() {
	return coordY;
}
void cLane::setY(int y) {
	coordY = y;
}
vector<cObject*> cLane::getList() {
	vector <cObject*> temp;
	for (int i = 0; i < objs.size(); i++)
	{
		cObject *a = objs[i];
		temp.push_back(a);
	}
	return temp;
}
int cLane::getDirection()
{
	return direction;
}
void cLane::setDirection(bool a) {
	direction = a;
}
cLane::cLane(int numObject, int y) {
	int random = rand() % 6;
	if (random == 0) {//grass : ratio 1/6
		numObj = 0;
		type = 1;
		filename = "grass1.bmp";
	}
	else if(random ==1 || random == 2 || random == 3){//road: ratio 3/6
		numObj = numObject;
		type = 2;
		filename = "ROAD.bmp";
	}
	else//river: ratio 2/6
	{
		numObj= 1;
		type = 3;
		filename = "river.bmp";
	}

	//orderObj = 0;
	direction = rand() % 2;
	coordY = y;
	int temp = getRandomNumber(2, 6);
	setTime(temp);
}
cLane::cLane() {}
cLane::~cLane() {
	cObject* temp;
	for (int i = 0; i < objs.size(); i++) {
		temp = objs[objs.size() - 1];
		objs.pop_back();
		delete temp;
		temp = NULL;
		i = -1;
	}
}
void cLane::setTime(int time)
{
	this->time = time;
}
int cLane::getTime()
{
	return time;
}
int cLane::getType()
{
	return type; // 1: grass, 2:road, 3:river
}

void cLane::setType(int type) {
	if (type != 1 && type != 2 && type != 3)return;
		
	this->type = type;
	if (type == 1)
	{
		filename = "grass1.bmp";
		numObj = 3;
	}
	else if (type == 2)
	{
		filename = "ROAD.bmp";
		numObj = 3;
	}
	else if (type == 3)
	{
		filename= "river.bmp";
		numObj = 1;
	}
}