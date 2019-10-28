#include"Game.h"

SDL_Renderer* Game::gameRenderer = nullptr;
int Game::gameW = 640;
int Game::gameH = 480;

Game::Game() 
{
	gameWindow = nullptr;
}

Game::~Game() 
{
	close();
}

void Game::init(const char* title){

	if (SDL_Init(SDL_INIT_EVERYTHING) < 0) 
	{
		printf("ERROR: SDL not initialized!\n");
	}
	else 
	{
		gameWindow = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, gameW, gameH, SDL_WINDOW_SHOWN);
		
		if (nullptr == gameWindow) 
		{
			printf("ERROR: window not created!\n");
		}
		else 
		{	
			gameRenderer = SDL_CreateRenderer(gameWindow, -1, SDL_RENDERER_ACCELERATED);

			if (nullptr == gameRenderer) 
			{
				printf("ERROR: renderer not created!\n");
			}
			else
			{
				SDL_SetRenderDrawColor(gameRenderer, 255, 255, 255, 255);
			}
		}
	}
}

void Game::load() 
{
	backgroundTexture.load("assets/sky.bmp");
	platformTexture.load("assets/platform.bmp");
	playerTexture.load("assets/sprite.bmp");
}

void Game::loop()
{
	bool quitFlag = false;

	SDL_Event event;

	int frameTicks = 16;

	while (!quitFlag) 
	{
		Uint32 ticks = SDL_GetTicks();

		while (SDL_PollEvent(&event) != 0)
		{
			if (event.type == SDL_QUIT)
			{
				quitFlag = true;
			}

			player.eventHandler(event);
		}

		//should put all these in a separate update() function
		player.move();
		player.jump();
		player.respawn();

		SDL_RenderClear(gameRenderer);

		backgroundTexture.render(0, 0, NULL);
		platformTexture.render(0, 320, NULL);
		playerTexture.render(player.xPosition, player.yPosition, NULL);

		SDL_RenderPresent(gameRenderer);

		frameTicks = SDL_GetTicks() - ticks;

		if (frameTicks < 1000 / 60) 
		{
			SDL_Delay(1000 / 60 - frameTicks);
		}
	}
}

void Game::close()
{
	playerTexture.free();
	backgroundTexture.free();

	SDL_DestroyRenderer(gameRenderer);
	gameRenderer = nullptr;

	SDL_DestroyWindow(gameWindow);
	gameWindow = nullptr;

	SDL_Quit();
}

