#pragma once
#include<SDL.h>



class Child
{
public:
	static const int CHILD_WIDTH = 35;
	static const int CHILD_HEIGHT = 58;
	SDL_Rect mCollider;
	Child(int x, int y);
	void move();
	void render();
	void change_position(int x, int y);
	int get_x();

private:
	int mPosX, mPosY;


};