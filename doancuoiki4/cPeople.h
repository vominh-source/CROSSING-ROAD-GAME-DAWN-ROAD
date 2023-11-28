#pragma once
#include "cConsole.h"
#include "cObject.h"
#include "Header.h"
#include "Input.h"
class cPeople
{
    float x, y; // Tọa dộ của con người
    int height, width; // Chiều cao, chiều rộng của con người
    static bool status;// Trạng thái chết hay sống của con người
    int change;// Nhận biết thay đổi di chuyển của con người lên xuống qua lại để vẽ lại
    char** a; // Tạo con người
public:
    void MoveLeft(); // Di chuyển sang trái
    void MoveRight();// Di chuyển sang phải
    void MoveDown();// Di chuyển xuống
    void MoveUp();// Di chuyển lên
    cPeople(); // Tạo hình cho người(khoi tao)
    void assignX(int); // Gán tọa độ x cho người
    void assignY(int);// Gán tọa độ y cho người
    void assignStatus(bool);// Gán trạng thái cho người
    void assignChange(int);// Gán thay đổi cho người
    int getX();// lấy tọa độ x của người
    int getY();// lấy tọa độ y của người
    int getHeight();// lấy chiều cao của người
    int getWidth();// lấy chiều rộng của người
    int getChange();// lấy thay đổi của người
    bool getStatus();// lấy trạng thái của người
    void simulatepeople(Input* input, float dt,  Render_State* a);

};

