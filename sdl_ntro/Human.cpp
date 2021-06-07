#include"Human.h"
#include"LTexture.h"


extern LTexture gHumanTexture;
extern SDL_Rect gHumanClips[];



Human::Human()
{
	mPosX = 0;
	mPosY = 500;

	mCollider.w = HUMAN_WIDTH;
	mCollider.h = HUMAN_HEIGHT;


	mVelX = 0;
	mVelY = 0;

	frame = 0;
}

void Human::handleEvent(SDL_Event& e)
{
	if (e.type == SDL_KEYDOWN && e.key.repeat == 0)
	{
		switch (e.key.keysym.sym)
		{
		case SDLK_UP:
		{
			mVelY -= HUMAN_VEL; 
			if (frame < 7 && frame >3)
			{
				frame++;
			}
			else
			{
				frame = 4;
			}
			break;
			
		}
		case SDLK_DOWN: 
		{
			mVelY += HUMAN_VEL; 
			if (frame < 3)
				frame++;
			else
				frame = 0;
			break;
		}
		case SDLK_LEFT:
		{
			mVelX -= HUMAN_VEL; 
			if (frame < 11 && frame >7)
				frame++;
			else
				frame = 8;
			break;
		}
		case SDLK_RIGHT: 
		{ 
			mVelX += HUMAN_VEL;
			if (frame < 15 && frame >11)
				frame++;
			else
				frame = 12;
			break;
		}
		}
	}
	else if (e.type == SDL_KEYUP && e.key.repeat == 0)
	{
		switch (e.key.keysym.sym)
		{
		case SDLK_UP: mVelY += HUMAN_VEL; break;
		case SDLK_DOWN: mVelY -= HUMAN_VEL; break;
		case SDLK_LEFT: mVelX += HUMAN_VEL;  break;
		case SDLK_RIGHT: mVelX -= HUMAN_VEL; break;
		}
	}
}

void Human::move()
{
	mPosX += mVelX;
	mCollider.x = mPosX;
	mPosY += mVelY;
	mCollider.y = mPosY;
	
	if (liczynik_przejscia == 0)
	{
		for (int i = 0; i < 3; i++)
		{
	
			if ((mPosX < 0) || (mPosX + HUMAN_WIDTH > 940) || checkCollision(mCollider, buildings_collider[i]))
			{
	
				mPosX -= mVelX;
				mCollider.x = mPosX;
			}
		}
		for (int i = 0; i < 3; i++)
		{
			if ((mPosY < 0) || (mPosY + HUMAN_HEIGHT > 780) || checkCollision(mCollider, buildings_collider[i]))
			{
				mPosY -= mVelY;
				mCollider.y = mPosY;
			}
		}
	}
	else if (liczynik_przejscia == 1)
	{
		for (int i = 3; i < 6; i++)
		{
			if ((mPosX < 0) || (mPosX + HUMAN_WIDTH > 940) || checkCollision(mCollider, buildings_collider[i]))
			{
				mPosX -= mVelX;
				mCollider.x = mPosX;
			}
		}
		for (int i = 3; i < 6; i++)
		{
			if ((mPosY < 0) || (mPosY + HUMAN_HEIGHT > 780) || checkCollision(mCollider, buildings_collider[i]))
			{
				mPosY -= mVelY;
				mCollider.y = mPosY;
			}
		}
	}
	else if (liczynik_przejscia == 2)
	{
		for (int i = 6; i < 9; i++)
		{
			if ((mPosX < 0) || (mPosX + HUMAN_WIDTH > 940) || checkCollision(mCollider, buildings_collider[i]))
			{
				mPosX -= mVelX;
				mCollider.x = mPosX;
			}
		}
		for (int i = 6; i < 9; i++)
		{
			if ((mPosY < 0) || (mPosY + HUMAN_HEIGHT > 780) || checkCollision(mCollider, buildings_collider[i]))
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
			if ((mPosX < 0) || (mPosX + HUMAN_WIDTH > 940) || checkCollision(mCollider, buildings_collider[i]))
			{
				mPosX -= mVelX;
				mCollider.x = mPosX;
			}
		}
		for (int i = 9; i < 14; i++)
		{
			if ((mPosY < 0) || (mPosY + HUMAN_HEIGHT > 780) || checkCollision(mCollider, buildings_collider[i]))
			{
				mPosY -= mVelY;
				mCollider.y = mPosY;
			}
		}
	}
	else if (liczynik_przejscia == 4)
	{
		if ((mPosX < 0) || (mPosX + HUMAN_WIDTH > 940))
		{
			mPosX -= mVelX;
			mCollider.x = mPosX;
		}
		if ((mPosY < 450) || (mPosY + HUMAN_HEIGHT > 780))
		{
			mPosY -= mVelY;
			mCollider.y = mPosY; 
		}
	}
}

void Human::render()
{
	SDL_Rect* currentClip = &gHumanClips[frame];
	gHumanTexture.render(mPosX, mPosY, currentClip);
}

int Human::get_x()
{
	return mPosX;
}

int Human::get_y()
{
	return mPosY;
}

void Human::change_position(int x, int y)
{
	mPosX = x;
	mPosY = y;
	mCollider.x = x;
	mCollider.y = y;
}





