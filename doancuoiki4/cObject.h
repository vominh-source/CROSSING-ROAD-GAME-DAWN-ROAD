#pragma once
#include "cConsole.h"
#include"Header.h"

class cObject
{
protected:
    int x, y; // Tọa độ của vật thể
    int const_width, const_height; // Chiều rộng và cao của vật thể không thay đổi trong quá trình chạy code
    int width, height;// Chiều rộng và cao của vật thể có thể thay đổi trong quá trình chạy code
    int status; //1: right to left, 0:left to right 
    int sign; // Nhận biết vật thể đang ở cột đèn giao thông nào để xử lý phù hợp với cột đèn giao thông đó
    string filename;
public:
    cObject() {};
    //char getPoint(int x, int y);
    void shape();
    cObject(const cObject&);
    //virtual void sound() = 0;
    void assignX(int); // Gán tọa độ x cho vật thể
    void assignY(int); // Gán tọa độ y cho vật thể
    void assignHeight(int); // Gán chiều cao cho vật thể
    void assignWidth(int);// Gán chiều rộng cho vật thể
    void assignConstHeight(int);// Gán chiều cao cho vật thể
    void assignConstWidth(int);// Gán chiều rộng cho vật thể
    void assignStatus(int);// Gán trạng thái cho vật thể
    void assignSign(int);// Gán tín hiệu cho vật thể
    int getX(); // Lấy tọa độ x của vật thể
    int getY();// Lấy tọa độ y của vật thể
    int getSign();// Lấy tín hiệu của vật thể
    int getWidth();// Lấy chiều rộng của vật thể
    int getHeight();// Lấy chiều cao của vật thể
    int getConstWidth();// Lấy chiều rộng của vật thể
    int getConstHeight();// Lấy chiều cao của vật thể
    int getStatus();// Lấy trạng thái của vật thể
    char getPoint(int x, int y);
    virtual string getObjectFileName()=0;

};

