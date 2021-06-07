#pragma once
#include<SDL.h>



class Car
{
public:
	static const int CAR_WIDTH = 99;
	static const int CAR_HEIGHT = 190;
	static const int CAR_VEL = 8;
	SDL_Rect mCollider;
	Car();
	void handleEvent(SDL_Event& e);

	void move();

	void flip(SDL_Event& e);

	void render();

	int get_x();
	int get_y();

	void change_position(int x, int y);

	
private:
	int mPosX, mPosY;
	int mVelX, mVelY;

};

