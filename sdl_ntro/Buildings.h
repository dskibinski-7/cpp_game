#pragma once
#include<SDL.h>


class Building
{
public:
	Building(int x, int y, int w, int h);
	SDL_Rect mCollider;
	
};