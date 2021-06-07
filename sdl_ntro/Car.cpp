#include"Car.h"
#include"LTexture.h"

extern LTexture gCarTexture;

double degrees = 0;


Car::Car()
{
	mPosX = 440;
	mPosY = 440;

	mCollider.w = CAR_WIDTH;
	mCollider.h = CAR_HEIGHT;

	mCollider.x = mPosX;
	mCollider.y = mPosY;

	mVelX = 0;
	mVelY = 0;
}

void Car::handleEvent(SDL_Event& e)
{
	if (e.type == SDL_KEYDOWN && e.key.repeat == 0)
	{
		switch (e.key.keysym.sym)
		{
		case SDLK_UP: 
		{
			mVelY -= CAR_VEL; 
			break;
		}
		case SDLK_DOWN:
		{
			mVelY += CAR_VEL; 
			break;
		}
		case SDLK_LEFT:
		{
			mVelX -= CAR_VEL;
			break;
		}
		case SDLK_RIGHT: 
		{
			mVelX += CAR_VEL; 
			break;
		}
		}
	}
	else if (e.type == SDL_KEYUP && e.key.repeat == 0)
	{
		switch (e.key.keysym.sym)
		{
		case SDLK_UP:
		{
			mVelY += CAR_VEL;
			
			break;
		}
		case SDLK_DOWN:
		{
			mVelY -= CAR_VEL;
			
			break; 
		}
		case SDLK_LEFT: 
		{
			mVelX += CAR_VEL;
		
			break;
		}
		case SDLK_RIGHT:
		{
			mVelX -= CAR_VEL; 
			
			break; 
		}

		}
	}
}

void Car::move()
{
	mPosX += mVelX;
	mCollider.x = mPosX;
	mPosY += mVelY;
	mCollider.y = mPosY;


	if (liczynik_przejscia == 0)
	{
		for (int i = 0; i < 3; i++)
		{
			if ((mPosX < 0) || (mPosX + CAR_WIDTH > 940) || checkCollision(mCollider, buildings_collider[i]))
			{
				mPosX -= mVelX;
				mCollider.x = mPosX;
			}
		}
		for (int i = 0; i < 3; i++)
		{
			if ((mPosY < 0) || (mPosY + CAR_HEIGHT > 780) || checkCollision(mCollider, buildings_collider[i]))
			{
				mPosY -= mVelY;
				mCollider.x = mPosX;
			}
		}
	}
	else if (liczynik_przejscia == 1)
	{
		for (int i = 3; i < 6; i++)
		{
			if ((mPosX < 0) || (mPosX + CAR_WIDTH > 940) || checkCollision(mCollider, buildings_collider[i]))
			{
				mPosX -= mVelX;
				mCollider.x = mPosX;
			}
		}
		for (int i = 3; i < 6; i++)
		{
			if ((mPosY < 0) || (mPosY + CAR_HEIGHT > 780) || checkCollision(mCollider, buildings_collider[i]))
			{
				mPosY -= mVelY;
				mCollider.x = mPosX;
			}
		}
	}
	else if (liczynik_przejscia == 2)
	{
		for (int i = 6; i < 9; i++)
		{
		if ((mPosX < 0) || (mPosX + CAR_WIDTH > 940) || checkCollision(mCollider, buildings_collider[i]))
		{
			mPosX -= mVelX;
			mCollider.x = mPosX;
		}
		}
		for (int i = 6; i < 9; i++)
		{
		if ((mPosY < 0) || (mPosY + CAR_HEIGHT > 780) || checkCollision(mCollider, buildings_collider[i]))
		{
			mPosY -= mVelY;
			mCollider.y = mPosY;
		}
		}
	}
	else if (liczynik_przejscia == 3)
	{
		for (int i = 9; i < 14; i++)
		{
			if ((mPosX < 0) || (mPosX + CAR_WIDTH > 940) || checkCollision(mCollider, buildings_collider[i]))
			{
				mPosX -= mVelX;
				mCollider.x = mPosX;
			}
		}
		for (int i = 9; i < 14; i++)
		{
			if ((mPosY < 0) || (mPosY + CAR_HEIGHT > 780) || checkCollision(mCollider, buildings_collider[i]))
			{
				mPosY -= mVelY;
				mCollider.y = mPosY;
			}
		}
	}
	else if (liczynik_przejscia == 4)
	{
		if ((mPosX < 0) || (mPosX + CAR_WIDTH > 940))
		{
			mPosX -= mVelX;
			mCollider.x = mPosX;
		}
		if ((mPosY < 450) || (mPosY + CAR_HEIGHT > 780))
		{
			mPosY -= mVelY;
			mCollider.y = mPosY;
		}
	}
}

void Car::flip(SDL_Event& e)
{
	if (e.type == SDL_KEYDOWN && e.key.repeat == 0)
	{
		switch (e.key.keysym.sym)
		{
		case SDLK_UP:
		{
			
			degrees = 0;
			break;
		}
		case SDLK_DOWN:
		{
		
			degrees = 180;
			break;
		}
		case SDLK_LEFT:
		{
		
			degrees = 270;
			break;
		}
		case SDLK_RIGHT:
		{
		
			degrees = 90;
			break;
		}
		}
	}
}

void Car::render()
{
	//Show the car
	gCarTexture.render(mPosX, mPosY,NULL,degrees,NULL);
}



int Car::get_x()
{
	return mPosX;
}

int Car::get_y()
{
	return mPosY;
}

void Car::change_position(int x, int y)
{
	mPosX = x;
	mPosY = y;
	mCollider.x = x;
	mCollider.y = y;
}