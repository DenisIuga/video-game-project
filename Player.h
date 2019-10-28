#pragma once
#include<stdlib.h>
#include <SDL.h>

class Player 
{
private:
	
	int width; //player dimensions
	int height;

public:

	int xPosition; //the player coordinates and axis velocities
	int yPosition;
	int xVelocity;
	int yVelocity;

	int velocity; //values for axis velocities modifications
	int gravity;

	bool jumpFlag; //the flag that activates when space is pressed (when jumping)

	SDL_Rect player; //rectangles for colission checks, that follow the objects
	SDL_Rect ground;

	Player();
	void eventHandler(SDL_Event& event); //handles keyboard input for movement and eventually future player actions
	void move(); //modifies player position and also contains some movement corrections as well as falling mechanic
	void jump(); //handles jumping
	void respawn(); //repositions player object when falling
};
