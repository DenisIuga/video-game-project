#pragma once

#include<SDL.h>
#include<string>

class Textures
{
private:

	SDL_Texture* texture; //the actual texture

	int width; //texture dimensions
	int height;

	SDL_Texture* loadTexture(std::string path); //loads a surface, creates a texture from it and returns the texture

public:

	Textures();
	~Textures();
	void load(std::string path); //gets the texture returned by loadTexture
	void render(int x, int y, SDL_Rect* rectangle);	//renders the texture
	void free(); //frees memory
};
