#include"Head.h"
#include"LTexture.h"

extern LTexture gHeadTexture;

Head::Head(int x, int y)
{
	mPosX = x;
	mPosY = y;

}

void Head::move()
{
	mPosX -= 5;
	
}

void Head::render()
{
	gHeadTexture.render(mPosX, mPosY);
}

void Head::change_position(int x, int y)
{
	mPosX = x;
	mPosY = y;

}

int Head::get_x()
{
	return mPosX;
}
int Head::get_y()
{
	return mPosY;
}