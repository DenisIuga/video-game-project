#include"Textures.h"
#include"Game.h"

SDL_Texture* Textures::loadTexture(std::string path) 
{
	free();

	SDL_Texture* newTexture = nullptr;

	SDL_Surface* loadedSurface = SDL_LoadBMP(path.c_str());

	//SDL_Surface* optimizedSurface = nullptr;

	if (nullptr == loadedSurface) 
	{
		printf("ERROR: texture from specified path was not loaded!\n");
	}
	else
	{
		newTexture = SDL_CreateTextureFromSurface(Game::gameRenderer, loadedSurface);

		if (nullptr == newTexture) 
		{
			printf("ERROR: texture from surface not created!\n");
		}

		width = loadedSurface->w;
		height = loadedSurface->h;

		SDL_FreeSurface(loadedSurface);
	}

	texture = newTexture;
	return texture;
}

Textures::Textures() 
{ 
	texture = nullptr;

	width = 0;
	height = 0;
}

Textures::~Textures() 
{
	free();
}

void Textures::load(std::string path) 
{
	texture = loadTexture(path);

	if (nullptr == texture) 
	{
		printf("ERROR: failed to load texture from path!\n");

	}
}

void Textures::render(int x, int y, SDL_Rect* rectangle) 
{
	SDL_Rect renderRectangle = { x, y, width, height };

	if (rectangle != nullptr) 
	{
		renderRectangle.w = rectangle->w;
		renderRectangle.h = rectangle->h;
	}

	SDL_RenderCopy(Game::gameRenderer, texture, rectangle, &renderRectangle);
}

void Textures::free() 
{
	if (texture != nullptr) 
	{
		SDL_DestroyTexture(texture);
		texture = nullptr;
		width = 0;
		height = 0;
	}
}
