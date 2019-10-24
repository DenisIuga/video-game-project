#include"Game.h"

int main(int argc, char* args[]) {

	Game game;

	game.init("Project01");

	game.load();

	game.loop();

	game.close();

	return 0;
}