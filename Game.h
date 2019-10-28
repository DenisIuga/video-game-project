#pragma once
#include<SDL.h>
#include<stdio.h>
#include "Textures.h"
#include "Player.h"

class Game 
{

private:

	static SDL_Renderer* gameRenderer;
	SDL_Window* gameWindow;

	static int gameW;
	static int gameH;

public:

	Textures playerTexture; 
	Textures backgroundTexture;
	Textures platformTexture;

	Player player;

	Game();
	~Game();
	void init(const char* title); //initializes sdl, creates the game window and the renderer
	void load(); //loads all images
	void loop(); //game loop
	void update(); //updates all game logic that happens in a frame
	void close(); //shuts down sdl and gets rid of window, renderer and texture

	friend class Textures;
	friend class Player;
};