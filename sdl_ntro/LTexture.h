#pragma once
#include<SDL.h>
#include<string>
#include<SDL_image.h>
#include<vector>

extern std::vector<SDL_Rect> buildings_collider;
extern bool checkCollision(SDL_Rect a, SDL_Rect b);
extern int liczynik_przejscia;

class LTexture
{
public:
	LTexture();
	~LTexture();
	bool loadFromFile(std::string path);

	void free();


	void render(int x, int y, SDL_Rect* clip = NULL, double angle = 0.0, SDL_Point* center = NULL, SDL_RendererFlip flip = SDL_FLIP_NONE);


	int getWidth();
	int getHeight();

private:

	SDL_Texture * mTexture;


	int mWidth;
	int mHeight;
};