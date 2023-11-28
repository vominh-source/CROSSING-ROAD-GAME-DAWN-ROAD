#include "cMap.h"
int cMap::level = 1;
int cMap::score = 0;
int cMap::speed = 30;
int cMap::flagStop = 0;
bool cMap::flagLoad = false;
bool cMap::flagSave = false;
bool cMap::flagMenu = false;
bool cMap::flagCreateObject = false;
cListObject cMap::temp = {};
cListLane cMap::temp1 = {};
void cMap::simulatepeople(Input* input, float speed, Render_State* a)
{
	if (is_down(BUTTON_UP) && people.getY() > 0 + speed)
	{
		this->people.assignY(this->people.getY() - speed);
	}
	if (is_down(BUTTON_DOWN) && people.getY() + people.getHeight() + speed < 901) {
		this->people.assignY(this->people.getY() + speed);
	}
	if (is_down(BUTTON_RIGHT) && people.getX() + people.getWidth() + speed < 1334) {
		this->people.assignX(this->people.getX() + speed);
	}
	if (is_down(BUTTON_LEFT) && people.getX() > 0)
	{
		this->people.assignX(this->people.getX() - speed);
	}
	loadImage("dog.bmp", *&a, this->people.getX(), this->people.getY(), 0, 0, 0);
}
void cMap::redrawObject(int timeuse, float speed)//thay doi thang ListObject trong cMap
{
	
	bool flagSign = 1; //1: den xanh, 0: den do 
	//assign lai toa do
	for (int i = 0; i < lanes.size(); i++) {
		if (lanes[i]->getType() != 3)
		{
			if ( timeuse % lanes[i]->getTime() == 0)
			{
				flagSign = !flagSign;
			}
			for (int j = 0; j < lanes[i]->getList().size(); j++) {
				if (flagSign == 1)
				{
					if (lanes[i]->getDirection() == 1) {
						if (lanes[i]->getList()[j]->getX() >= 1333) {
							//lanes[i]->getList()[j]->assignY(lanes[i]->getList()[j]->getY() - 1);
							lanes[i]->getList()[j]->assignX(-lanes[i]->getList()[j]->getWidth());
							//getRandomNumber()
						}
						lanes[i]->getList()[j]->assignX(lanes[i]->getList()[j]->getX() + speed);

					}
					else {

						if (lanes[i]->getList()[j]->getX() + lanes[i]->getList()[j]->getWidth() <= 0)
						{
							lanes[i]->getList()[j]->assignX(1333);
						}
						lanes[i]->getList()[j]->assignX(lanes[i]->getList()[j]->getX() - speed);
					}
				}
			}
		}
	}
}
bool cMap::checkCollison2(int lane1, int lane2)
{
	bool isColli = false;
	int x = people.getX()+people.getWidth()/4;
	int xMax = people.getX() + people.getWidth()*3 / 4;

	int y = people.getY() + people.getHeight() * 2 / 3;
	int yMax = people.getY() + people.getHeight();
	
	if (lane1 == lane2)
	{
		for (int j = 0; j < lanes[lane1]->getNumObj(); j++)
		{
			cObject* temp = lanes[lane1]->getList()[j];
			if ((x >= temp->getX() && x <= (temp->getX() + temp->getWidth())) ||
			(xMax >= temp->getX() && xMax <= (temp->getX() + temp->getWidth())) ||
			(x >= temp->getX() && xMax <= (temp->getX() + temp->getWidth())))
			{
				return false;
			}
			else
			{
				return true;
			}
		}
	}
	else//player is on 2 lanes
	{
		if (lanes[lane1]->getType() == 3 && lanes[lane2]->getType() != 3)////up lane is water
		{
			for (int j = 0; j < lanes[lane1]->getNumObj(); j++)
			{
				cObject* temp = lanes[lane1]->getList()[j];
				if ((x >= temp->getX() && x <= (temp->getX() + temp->getWidth())) || (xMax >= temp->getX() && xMax <= (temp->getX() + temp->getWidth())) || (x >= temp->getX() && xMax <= (temp->getX() + temp->getWidth())))
				{
					isColli = false;
				}
				else
				{
					return true;
				}
			}
			for (int j = 0; j < lanes[lane2]->getNumObj(); j++)//check lane 1
			{
				cObject* temp = lanes[lane2]->getList()[j];
				if ((x >= temp->getX() && x <= (temp->getX() + temp->getWidth())) || (xMax >= temp->getX() && xMax <= (temp->getX() + temp->getWidth())) || (x >= temp->getX() && xMax <= (temp->getX() + temp->getWidth())))
				{
					return true;
				}
				else
				{
					isColli = false;
				}
			}
		}
		else if (lanes[lane1]->getType() != 3 && lanes[lane2]->getType() == 3) {//down lane is water
			for (int j = 0; j < lanes[lane2]->getNumObj(); j++)
			{
				cObject* temp = lanes[lane2]->getList()[j];
				if ((x >= temp->getX() && x <= (temp->getX() + temp->getWidth())) || (xMax >= temp->getX() && xMax <= (temp->getX() + temp->getWidth())) || (x >= temp->getX() && xMax <= (temp->getX() + temp->getWidth())))
				{
					isColli = false;
				}
				else
				{
					return true;
				}
			}
			for (int j = 0; j < lanes[lane1]->getNumObj(); j++)//check lane 1
			{
				cObject* temp = lanes[lane1]->getList()[j];
				if ((x >= temp->getX() && x <= (temp->getX() + temp->getWidth())) || (xMax >= temp->getX() && xMax <= (temp->getX() + temp->getWidth())) || (x >= temp->getX() && xMax <= (temp->getX() + temp->getWidth())))
				{
					return true;
				}
				else
				{
					isColli = false;
				}
			}
		}
	
	}
	return isColli;
}
bool cMap::checkCollison()
{
	//y
	int lane1 = (people.getY() + people.getHeight()*2/3) / SIZELANE;
	int lane2 = (people.getY() + people.getHeight()) / SIZELANE;
	if (lane2 >= 7) lane2 = lane1;
	int x = people.getX();
	int xMax = people.getX() + people.getWidth();
	int y = people.getY() + people.getHeight() * 2 / 3;
	int yMax = people.getY() + people.getHeight();
	//if (people.getY() >= lanes.size()*99)
	if(lane1>=lanes.size())
	{														
		return false;
	}
	for (int i = lane1; i <= lane2; i++)
	{
		if (lanes[i]->getType() == 3)
		{
			return checkCollison2(lane1, lane2);
		}
	}
	
	for (int i = lane1; i <= lane2; i++)
	{
		for (int j = 0; j < lanes[i]->getNumObj(); j++)                                     
		{
			cObject* temp = lanes[i]->getList()[j];
			if (((x >= temp->getX() && x <= (temp->getX() + temp->getWidth())) ||
			(xMax >= temp->getX() && xMax <= (temp->getX() + temp->getWidth())) ||
			(x <= temp->getX() && xMax >= (temp->getX() + temp->getWidth()))) && 
			((y <= (temp->getY() + temp->getHeight() * 2 / 3) && yMax >= (temp->getY() + temp->getHeight() * 2 / 3)) ||
			(y <= (temp->getY() + temp->getHeight()) && yMax >= (temp->getY() + temp->getHeight())) ||
			(y >= (temp->getY() + temp->getHeight() * 2 / 3) && yMax <= (temp->getY() + temp->getHeight())) ||
			(y <= (temp->getY() + temp->getHeight() * 2 / 3) && yMax >= (temp->getY() + temp->getHeight()))))
			{
				return true;
			}
		}
	}
	return false;
}

void cMap::Endless(int timeUse)//after a certain amount of time, the map will move up 1 lane
{
	if (people.getY() < SIZELANE*3)
	{
		cLane* temp1 = lanes.back();
		lanes.pop_back();
		delete temp1;

		cLane* temp = new cLane(3, 0);
		if (temp->getType() == 3) {
			if (lanes[0]->getType() == 3) {
				while (temp->getType() == 3)
				{
					temp = new cLane(3, 0);
				}
			}
			
		}
		temp->createObject(); 
		lanes.insert(lanes.begin(), (temp));
		for (int i = 1; i < lanes.size(); i++)
		{
			lanes[i]->setY(lanes[i]->getY() + SIZELANE);
			//reset y of every object
			for (int j = 0; j < lanes[i]->getNumObj(); j++)
			{
				lanes[i]->getList()[j]->assignY(lanes[i]->getList()[j]->getY() + SIZELANE);
			}
		}
		people.assignY(people.getY() + SIZELANE);
		score += 1;
	}
}

void cMap::output(bool Sound, HDC * hdc, Render_State * a, Input * input, HWND * window) {
flag:
	//objett, lanes, 
	flagMenu = false;
	//processSubScreen();
	
	if (!flagCreateObject) {
		temp.setNumberObject(3);
		//temp.Creat_Object();
		listObject = temp.getList();
		flagCreateObject = true;

		temp1.Create_Lane(3);
		lanes = temp1.Get_ListLane();
	}
	
	flagLoad = false; // Gán biến nhận biết có thực hiện chức năng load là không
	flagSave = false;// Gán biến nhận biết có thực hiện chức năng save là không
	people.assignStatus(true); // Khởi tạo trạng thái cho người
	start = clock();// Bắt đầu đếm thời gian

	cConsole c;
	flagStop = 0;

	while (flagStop==0)
	{
		MSG message;
		for (int i = 0; i < BUTTON_COUNT; i++) {
			(*input).buttons[i].changed = false;
		}
		while (PeekMessage(&message, *window, 0, 0, PM_REMOVE)) {
			switch (message.message) {
				case WM_KEYUP:
				case WM_KEYDOWN: {
					u32 vk_code = (u32)message.wParam;
					bool is_down = ((message.lParam & (1 << 31)) == 0);

#define process_button(b, vk)\
case vk: {\
(*input).buttons[b].changed = is_down != (*input).buttons[b].is_down;\
(*input).buttons[b].is_down = is_down;\
} break;
					switch (vk_code) {
						process_button(BUTTON_UP, VK_UP);
						process_button(BUTTON_DOWN, VK_DOWN);
						process_button(BUTTON_W, 'W');
						process_button(BUTTON_S, 'S');
						process_button(BUTTON_LEFT, VK_LEFT);
						process_button(BUTTON_RIGHT, VK_RIGHT);
						process_button(BUTTON_ENTER, VK_RETURN);
					}
				} break;
				default: {
					TranslateMessage(&message);
					DispatchMessage(&message);
				}
			}
			if (pressed(BUTTON_ENTER))
			{
				return;
			}
		}
		
				speed = 5 + score / 2;
				clear_screen(0xffffff, *&a);
				
				
				int count = 0;
				for (int i = 0; i < lanes.size();i++) {
					int y = lanes[count++]->getY();
					loadImage(lanes[i]->GetLaneFileName(), *&a, 0, y, 0, 0, 0);
					vector <cObject*> k = lanes[i]->getList();
					for (int j = 0; j < k.size(); j++)
					{
						loadImage(k[j]->getObjectFileName(), *&a,k[j]->getX(), y, 0, 0, 0);
					}
				}
				redrawObject(timeUse, speed);
				simulatepeople(input, 5, a);
				Endless(timeUse);
				if (checkCollison())
				{
					//Sleep(50);
					loadImage("car.bmp", *&a, 901, 0);
				}
				StretchDIBits(*hdc, 0, 0, a->width, a->height, 0, 0, a->width, a->height, a->memory, &a->bitmap_info, DIB_RGB_COLORS, SRCCOPY);

			end = clock();// Bấm thời gian kết thúc
			timeUse = (double)(end - start) / CLOCKS_PER_SEC; // Đo thời gian thực
			//flagMove = false; // Gán biến di chuyển là false tương ứng người đang đứng yên
			//flagStop = 0;
			
			
	}

}
bool cMap::checkFlagMenu() {
	return this->flagMenu;
}
void cMap::setLevel(int lev) {
	this->level = lev;
}
void cMap::setScore(int sco) {
	this->score = sco;
}
