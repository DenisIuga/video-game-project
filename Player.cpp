#include "Player.h"
#include "Game.h"

Player::Player() {

	width = 64;
	height = 64;

	xPosition = 0;
	yPosition = 320-height;

	xVelocity = 0;
	yVelocity = 0;

	velocity = 8;
	gravity = 1;
	jumpFlag = false;

	player.x = xPosition;
	player.y = yPosition;
	player.w = width;
	player.h = height;

	ground.x = 0;
	ground.y = 320;
	ground.w = 480;
	ground.h = 160;
}

void Player::eventHandler(SDL_Event& event) {

	if (event.type == SDL_KEYDOWN && event.key.repeat == 0) {

		switch (event.key.keysym.sym) {
		
		case SDLK_a: xVelocity -= velocity; break;
		case SDLK_d: xVelocity += velocity; break;			
		case SDLK_SPACE: yVelocity -= 2*velocity; jumpFlag = true;  break;
				
		}
	}
	else if (event.type == SDL_KEYUP && event.key.repeat == 0) {

		switch (event.key.keysym.sym) {

		case SDLK_a: xVelocity += velocity; break;
		case SDLK_d: xVelocity -= velocity; break;
		case SDLK_SPACE: break;
		}
	}
}

void Player::move() {

	xPosition += xVelocity;

	//these are a bunch of collisions and falling mechanics
	//which should be made into a separate function

	if ((xPosition < 0) || (xPosition + width > 640) || ((yPosition + height > ground.y) && (xPosition < ground.x + ground.w))) {		

		xPosition -= xVelocity;
	}

	if ((xPosition >= ground.x + ground.w) && (!jumpFlag)) {
		
		yPosition += yVelocity;
		yVelocity += gravity;
	}
	else if (!jumpFlag) {

		yVelocity = 0;
	}

	if (yPosition + yVelocity <= 0) {

		yPosition = 0;
		yVelocity = 0;
	}
}

void Player::jump() {

	if (jumpFlag) {
		
		yPosition += yVelocity;
		yVelocity += gravity;
		
		int yNextPosition = yPosition + height + yVelocity;

		if ((yNextPosition >= ground.y) && (xPosition < ground.x + ground.w)) {

			yPosition = ground.y - height;
			yVelocity = 0;
			jumpFlag = false;
		}
	}
}

void Player::respawn() {

	if (yPosition > 480) {

		xPosition = 0;
		yPosition = 320 - 64;
	}

}



