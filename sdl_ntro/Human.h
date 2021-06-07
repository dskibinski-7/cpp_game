#pragma once
#include<SDL.h>

class Human
{
public:
	static const int HUMAN_WIDTH = 46;
	static const int HUMAN_HEIGHT = 84;
	static const int HUMAN_VEL = 3;

	SDL_Rect mCollider;
	Human();
	void handleEvent(SDL_Event& e);
	void move();
	void render();
	int get_x();
	int get_y();
	void change_position(int x, int y);

private:
	int mPosX, mPosY;
	int mVelX, mVelY;
	int frame;
};