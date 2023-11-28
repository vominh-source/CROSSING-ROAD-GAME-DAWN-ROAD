#include "cListObject.h"
int cListObject::numberObject = 7;
int cListObject::orderObject = 0; // Số lượng vật cản
vector<cObject*> cListObject::list = {};
cListObject::~cListObject() {
	cObject* temp;
	for (int i = 0; i < list.size(); i++) {
		temp = list[list.size()-1];
		list.pop_back();
		delete temp;
		temp = NULL;
		i = -1;
	}
}
void cListObject::setNumberObject(int num) {
	this->numberObject = num;
}
void cListObject::setOrderObject(int num){
	this->orderObject = num;
}
vector<cObject*> cListObject::getList() {
	vector<cObject*> temp;
	for (int i = 0; i < this->list.size(); i++) {
		cObject* ob(list[i]);
		temp.push_back(ob);
	}
	return temp;
}
