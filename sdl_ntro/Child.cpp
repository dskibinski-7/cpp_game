#include"Child.h"
#include"LTexture.h"

extern LTexture gChildTexture;

Child::Child(int x, int y)
{
	mPosX = x;
	mPosY = y;


	mCollider.w = CHILD_WIDTH;
	mCollider.h = CHILD_HEIGHT;

	mCollider.x = mPosX;
	mCollider.y = mPosY;
}

void Child::move()
{
	mPosX += 7;
	mCollider.x = mPosX;
}

void Child::render()
{
	gChildTexture.render(mPosX, mPosY);
}

void Child::change_position(int x, int y)
{
	mPosX = x;
	mPosY = y;
	mCollider.x = x;
	mCollider.y = y;
}

int Child::get_x()
{
	return mPosX;
}