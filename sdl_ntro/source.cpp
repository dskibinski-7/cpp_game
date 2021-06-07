#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <string>
#include"LTexture.h"
#include"Human.h"
#include"Car.h"
#include<vector>
#include"Buildings.h"
#include"Truck.h"
#include<ctime>
#include"Child.h"
#include"Head.h"

const int SCREEN_WIDTH = 940;
const int SCREEN_HEIGHT = 780;




bool init();
bool loadMedia();
void close();
SDL_Window* gWindow = NULL;
SDL_Renderer* gRenderer = NULL;

int move_bg = 780;
int liczynik_przejscia = 0;
std::vector<SDL_Rect> buildings_collider; 


Building yellow(640, 65, 300, 346);
Building tree(0, 185, 106, 180);
Building tree_2(820,570,106,180);

Building tree_3(156,610,105,180);
Building tree_4(807,30,105,180);
Building sign(609,500,19,90);

Building sign_2(614, 624, 19, 90);
Building school(0,0,305,650);
Building skatepark(680,0,281,505);

Building sp3(0,725,290,100);
Building skpark(670,760,281,100);
Building sign_3(650,260,10,90);
Building river_line_1(0,230,290,5);
Building river_line_2(617,200,400,5);

Building barrier(291,0,25,334);
Building barrier_2(599,0,25,334);

const Uint8* currentKeyStates = SDL_GetKeyboardState(NULL);
bool g_pressed = false;


LTexture gHumanTexture;
const int Animation = 16;
SDL_Rect gHumanClips[Animation];
int frame = 0;
LTexture gCarTexture;
LTexture gBackgroundTexture;
LTexture gTruckTexture;
LTexture gChildTexture;
LTexture gHeadTexture;
LTexture gOhmTexture;
LTexture gIncorrectTexture;
LTexture gCorrectTexture;
LTexture gDeadTexture;
LTexture gBloodTexture; int blood = 0; int collision_place_x; int collision_place_y;

LTexture gExplosionTexture;
SDL_Rect gExplosionClips[Animation];





bool render_hero = true;
bool render_car = true;
bool render_truck = true;
bool smierc = false;
bool poprawna = false;
bool niepoprawna = false;

int expl_frame = 0;



bool init()
{
	//Initialization flag
	bool success = true;

	//Initialize SDL
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("SDL could not initialize! SDL Error: %s\n", SDL_GetError());
		success = false;
	}
	else
	{
		//Set texture filtering to linear
		if (!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1"))
		{
			printf("Warning: Linear texture filtering not enabled!");
		}

		//Create window
		gWindow = SDL_CreateWindow("Game", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (gWindow == NULL)
		{
			printf("Window could not be created! SDL Error: %s\n", SDL_GetError());
			success = false;
		}
		else
		{
			//Create vsynced renderer for window
			gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
			if (gRenderer == NULL)
			{
				printf("Renderer could not be created! SDL Error: %s\n", SDL_GetError());
				success = false;
			}
			else
			{
				//Initialize renderer color
				SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);

				//Initialize PNG loading
				int imgFlags = IMG_INIT_PNG;
				if (!(IMG_Init(imgFlags) & imgFlags))
				{
					printf("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
					success = false;
				}
			}
		}
	}

	return success;
}

bool checkCollision(SDL_Rect a, SDL_Rect b)
{
	//The sides of the rectangles
	int leftA, leftB;
	int rightA, rightB;
	int topA, topB;
	int bottomA, bottomB;

	//Calculate the sides of rect A
	leftA = a.x;
	rightA = a.x + a.w;
	topA = a.y;
	bottomA = a.y + a.h;

	//Calculate the sides of rect B
	leftB = b.x;
	rightB = b.x + b.w;
	topB = b.y;
	bottomB = b.y + b.h;
	//If any of the sides from A are outside of B
	if (bottomA <= topB)
	{
		return false;
	}

	if (topA >= bottomB)
	{
		return false;
	}

	if (rightA <= leftB)
	{
		return false;
	}

	if (leftA >= rightB)
	{
		return false;
	}

	//If none of the sides from A are outside B
	return true;
}


bool loadMedia()
{

	bool success = true;


	if (!gHumanTexture.loadFromFile("grafiki/hero_s.png"))
	{
		printf("Failed to load human texture!\n");
		success = false;
	}
	else
	{
		
		gHumanClips[0].x = 0;
		gHumanClips[0].y = 0;
		gHumanClips[0].w = 46;
		gHumanClips[0].h = 84;

		gHumanClips[1].x = 46;
		gHumanClips[1].y = 0;
		gHumanClips[1].w = 46;
		gHumanClips[1].h = 84;

		gHumanClips[2].x = 92;
		gHumanClips[2].y = 0;
		gHumanClips[2].w = 46;
		gHumanClips[2].h = 84;

		gHumanClips[3].x = 138;
		gHumanClips[3].y = 0;
		gHumanClips[3].w = 46;
		gHumanClips[3].h = 84;

		

		gHumanClips[4].x = 0;
		gHumanClips[4].y = 84;
		gHumanClips[4].w = 46;
		gHumanClips[4].h = 84;

		gHumanClips[5].x = 46;
		gHumanClips[5].y = 84;
		gHumanClips[5].w = 46;
		gHumanClips[5].h = 84;

		gHumanClips[6].x = 92;
		gHumanClips[6].y = 84;
		gHumanClips[6].w = 46;
		gHumanClips[6].h = 84;

		gHumanClips[7].x = 138;
		gHumanClips[7].y = 84;
		gHumanClips[7].w = 46;
		gHumanClips[7].h = 84;

		

		gHumanClips[11].x = 0;
		gHumanClips[11].y = 169;
		gHumanClips[11].w = 46;
		gHumanClips[11].h = 84;

		gHumanClips[8].x = 46;
		gHumanClips[8].y = 169;
		gHumanClips[8].w = 46;
		gHumanClips[8].h = 84;

		gHumanClips[9].x = 92;
		gHumanClips[9].y = 169;
		gHumanClips[9].w = 46;
		gHumanClips[9].h = 84;

		gHumanClips[10].x = 138;
		gHumanClips[10].y = 169;
		gHumanClips[10].w = 46;
		gHumanClips[10].h = 84;

		

		gHumanClips[15].x = 0;
		gHumanClips[15].y = 252;
		gHumanClips[15].w = 46;
		gHumanClips[15].h = 84;

		gHumanClips[12].x = 46;
		gHumanClips[12].y = 252;
		gHumanClips[12].w = 46;
		gHumanClips[12].h = 84;

		gHumanClips[13].x = 92;
		gHumanClips[13].y = 252;
		gHumanClips[13].w = 46;
		gHumanClips[13].h = 84;

		gHumanClips[14].x = 138;
		gHumanClips[14].y = 252;
		gHumanClips[14].w = 46;
		gHumanClips[14].h = 84;

	

		
	}
	if (!gCarTexture.loadFromFile("grafiki/vehicle.png"))
	{
		printf("Failed to load car texture!\n");
		success = false;
	}
	if (!gOhmTexture.loadFromFile("grafiki/ohm.png"))
	{
		printf("Failed to load ohm texture!\n");
		success = false;
	}
	if (!gBackgroundTexture.loadFromFile("grafiki/bg.png"))
	{
		printf("Failed to load background texture!\n");
		success = false;
	}
	if (!gTruckTexture.loadFromFile("grafiki/truck.png"))
	{
		printf("Failed to load truck texture!\n");
		success = false;
	}
	if (!gChildTexture.loadFromFile("grafiki/child.png"))
	{
		printf("Failed to load child texture!\n");
		success = false;
	}
	if (!gIncorrectTexture.loadFromFile("grafiki/zla_odpowiedz.png"))
	{
		success = false;
	}
	if (!gCorrectTexture.loadFromFile("grafiki/poprawna_odpowiedz.png"))
	{
		success = false;
	}
	if (!gDeadTexture.loadFromFile("grafiki/przegrana.png"))
	{
		success = false;
	}
	if (!gBloodTexture.loadFromFile("grafiki/blood.png"))
	{
		printf("Failed to load blood texture!\n");
		success = false;
	}
	if (!gExplosionTexture.loadFromFile("grafiki/explosion.png"))
	{
		printf("Failed to load explosion texture!\n");
		success = false;
	}
	else
	{
		
		int d = 0;
		for (int i = 0; i < 4; i++)
		{
			
			gExplosionClips[i].x = d;
			gExplosionClips[i].y = 0;
			gExplosionClips[i].w = 256;
			gExplosionClips[i].h = 256;
			d += 256;
		}
		d = 0;
		for (int i = 4; i < 8; i++)
		{
			
			gExplosionClips[i].x = d;
			gExplosionClips[i].y = 256;
			gExplosionClips[i].w = 256;
			gExplosionClips[i].h = 256;
			d += 256;
		}
		d = 0;
		for (int i = 8; i < 12; i++)
		{
			
			gExplosionClips[i].x = d;
			gExplosionClips[i].y = 512;
			gExplosionClips[i].w = 256;
			gExplosionClips[i].h = 256;
			d += 256;
		}
		d = 0;
		for (int i = 12; i < 16; i++)
		{
			
			gExplosionClips[i].x = d;
			gExplosionClips[i].y = 768;
			gExplosionClips[i].w = 256;
			gExplosionClips[i].h = 256;
			d += 256;
		}

	}
	if (!gHeadTexture.loadFromFile("grafiki/head.png"))
	{
		printf("Failed to load head texture!\n");
		success = false;
	}

	return success;
}

void close()
{
	//Free loaded images
	gHumanTexture.free();
	gCarTexture.free();
	gBackgroundTexture.free();
	gTruckTexture.free();
	gExplosionTexture.free();
	gChildTexture.free();
	gBloodTexture.free();
	gHeadTexture.free();
	gOhmTexture.free();
	gDeadTexture.free();
	gIncorrectTexture.free();
	gCorrectTexture.free();

	//Destroy window	
	SDL_DestroyRenderer(gRenderer);
	SDL_DestroyWindow(gWindow);
	gWindow = NULL;
	gRenderer = NULL;

	//Quit SDL subsystems
	IMG_Quit();
	SDL_Quit();
}

int main(int argc, char* args[])
{
	buildings_collider.push_back(yellow.mCollider);
	buildings_collider.push_back(tree.mCollider);
	buildings_collider.push_back(tree_2.mCollider);

	buildings_collider.push_back(tree_3.mCollider);
	buildings_collider.push_back(tree_4.mCollider);
	buildings_collider.push_back(sign.mCollider);

	buildings_collider.push_back(sign_2.mCollider);
	buildings_collider.push_back(school.mCollider);
	buildings_collider.push_back(skatepark.mCollider);

	buildings_collider.push_back(sp3.mCollider);
	buildings_collider.push_back(skpark.mCollider);
	buildings_collider.push_back(sign_3.mCollider);
	buildings_collider.push_back(barrier.mCollider);
	buildings_collider.push_back(barrier_2.mCollider);


	if (!init())
	{
		printf("Failed to initialize!\n");
	}
	else
	{
		
		if (!loadMedia())
		{
			printf("Failed to load media!\n");
		}
		else
		{
		
			bool quit = false;

		
			SDL_Event e;

			Human hero;
			Car vehicle;
			Truck lorry(1500,280);
			Child little_boy(281,146);
			Head mach(950,50);

			while (!quit)
			{
				while (SDL_PollEvent(&e) != 0)
				{
					if (e.type == SDL_QUIT)
					{
						quit = true;
					}

					
					hero.handleEvent(e);
					vehicle.handleEvent(e);
					
				}
				if (checkCollision(hero.mCollider, vehicle.mCollider)&&g_pressed==false)
				{
					vehicle.flip(e);
					vehicle.move();
					
					hero.change_position(vehicle.get_x() + 30, vehicle.get_y() + 52);
					
					if (currentKeyStates[SDL_SCANCODE_G])
					{
						g_pressed = true;
					}
				}
				else if (g_pressed&&checkCollision(hero.mCollider, vehicle.mCollider))
				{
					if (vehicle.get_x() > 470)
					{
						hero.change_position(vehicle.get_x() - 80, vehicle.get_y() + 52);
					}
					else if (vehicle.get_x() <= 470)
					{
						hero.change_position(vehicle.get_x() + 115, vehicle.get_y() + 52);
					}
				}
				else if(checkCollision(hero.mCollider, vehicle.mCollider)!=true)
				{
					hero.move();
					g_pressed = false; 
				}

				
				if (liczynik_przejscia < 5)
				{
					if (vehicle.get_y() < 60)
					{
						vehicle.change_position(vehicle.get_x(), vehicle.get_y() + 535);
						hero.change_position(vehicle.get_x(), vehicle.get_y());
						move_bg += 780;
						liczynik_przejscia++;
					}

				}

				if (liczynik_przejscia==3 && (checkCollision(hero.mCollider, river_line_1.mCollider) || checkCollision(hero.mCollider, river_line_2.mCollider)))
				{
					
					render_hero = false;
					smierc = true;
					
					
				}
				
				if (liczynik_przejscia == 3 && (checkCollision(vehicle.mCollider, river_line_1.mCollider) || checkCollision(vehicle.mCollider, river_line_2.mCollider)))
				{
					smierc = true;
					render_hero = false;
					render_car = false;
				}
				
				
			
				
				
				SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
				SDL_RenderClear(gRenderer);

				gBackgroundTexture.render(0, -gBackgroundTexture.getHeight() + move_bg);
				
				
				
				if (liczynik_przejscia == 1 && checkCollision(vehicle.mCollider, lorry.mCollider) == true)
				{
				
					if (expl_frame < 16)
					{
						SDL_Rect* currentClip = &gExplosionClips[expl_frame];
						gExplosionTexture.render(vehicle.get_x(), vehicle.get_y() - 50, currentClip);
					}
					expl_frame++;
					render_hero = false;
					render_car = false;
					render_truck = false;

					if (expl_frame > 16)
					{
						smierc = true;
					}
				}

				
				if (liczynik_przejscia == 4)
				{
					if (mach.get_x() > 600)
					{
						mach.move();
					}
					else
					{
						gOhmTexture.render(mach.get_x() - 200, mach.get_y());
					}
					mach.render();
				}
			
				
				if (liczynik_przejscia == 4 && ((hero.get_y() < 480)|| (vehicle.get_y()<480))) 
				{
					if (hero.get_x() > 55 && hero.get_x() < 200)
					{
						poprawna = true;
					}
					else if ((hero.get_x() > 415 && hero.get_x() < 560) || (hero.get_x() > 738 && hero.get_x() < 885))
					{
						niepoprawna = true;
					}

					if (vehicle.get_x() > 55 && vehicle.get_x() < 200)
					{
						poprawna = true;
					}
					else if ((vehicle.get_x() > 415 && vehicle.get_x() < 560) || (vehicle.get_x() > 738 && vehicle.get_x() < 885))
					{
						niepoprawna = true;
					}
				}
				
				if (liczynik_przejscia == 2 && checkCollision(vehicle.mCollider, little_boy.mCollider))
				{
					little_boy.change_position(1000, 146);
					blood++;
					collision_place_x = vehicle.get_x();
					collision_place_y = vehicle.get_y();
				}


				if (blood >=1 && liczynik_przejscia==2)
				{
						gBloodTexture.render(collision_place_x, collision_place_y-20);
				}
				
				if (liczynik_przejscia == 2)
				{
					if (little_boy.get_x() > 1800)
					{
						little_boy.change_position(281, 146);
					}
					little_boy.move();
					little_boy.render();
				}	

				if (liczynik_przejscia == 1&& render_truck==true)
				{
					lorry.move();
					lorry.render();
				}

				if (render_hero == true)
				{
					hero.render();
				}

				if (render_car == true)
				{
					vehicle.render();
				}

				if (smierc == true)
				{
					gDeadTexture.render(0, 0);
				}
				if (poprawna == true)
				{
					gCorrectTexture.render(0, 0);
				}
				if (niepoprawna == true)
				{
					gIncorrectTexture.render(0, 0);
				}
				
				SDL_RenderPresent(gRenderer);
			}
			
		}
	}

	close();

	return 0;
}