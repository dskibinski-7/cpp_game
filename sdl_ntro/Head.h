#pragma once


class Head
{
public:
	
	Head(int x, int y);
	void move();
	void render();
	void change_position(int x, int y);
	int get_x();
	int get_y();


private:
	int mPosX, mPosY;

};