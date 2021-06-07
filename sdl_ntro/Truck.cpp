#include"Truck.h"
#include"LTexture.h"

extern LTexture gTruckTexture;

Truck::Truck(int x, int y)
{
	mPosX = x;
	mPosY = y;
	

	mCollider.w = TRUCK_WIDTH;
	mCollider.h = TRUCK_HEIGHT;

	mCollider.x = mPosX;
	mCollider.y = mPosY;
}

void Truck::move()
{
	mPosX -= 15;
	mCollider.x = mPosX;
}

void Truck::render()
{
	gTruckTexture.render(mPosX,mPosY);
}

void Truck::change_position(int x, int y)
{
	mPosX = x;
	mPosY = y;
	mCollider.x = x;
	mCollider.y = y;
}

int Truck::get_x()
{
	return mPosX;
}
int Truck::get_y()
{
	return mPosY;
}