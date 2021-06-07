#pragma once
#include<SDL.h>



class Truck
{
public:

	static const int TRUCK_WIDTH = 289;
	static const int TRUCK_HEIGHT = 109;



	SDL_Rect mCollider;


	Truck(int x, int y);




	void move();

	void render();
	void change_position(int x, int y);
	int get_x();
	int get_y();


private:

	int mPosX, mPosY;

};