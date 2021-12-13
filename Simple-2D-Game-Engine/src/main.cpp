#include "GameManager/GameManager.h"
#include <random>
#undef main

GameManager* manager = nullptr;

int main() {
	const int FPS = 30;
	const int FRAME_DELAY = 1000 / FPS;

	unsigned int frameStart;
	int frameTime;

	manager = new GameManager();
	manager->init("Simple2D Engine", 800, 640, false);

	while (manager->running()) {
		frameStart = SDL_GetTicks();

		manager->handleEvents();
		manager->update();
		manager->render();

		frameTime = SDL_GetTicks() - frameStart;
		if (FRAME_DELAY > frameTime) {
			SDL_Delay(FRAME_DELAY - frameTime);
		}
	}

	manager->clean();
	return 0;
 }