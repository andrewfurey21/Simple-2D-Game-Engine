#include "Stage/Stage.h"
#undef main

Stage* stage = nullptr;

int main() {
	const int FPS = 30;
	const int FRAME_DELAY = 1000 / FPS;

	unsigned int frameStart;
	int frameTime;

	stage = new Stage();
	stage->init("Simple2D Engine", 800, 640, false);

	while (stage->running()) {
		frameStart = SDL_GetTicks();

		stage->handleEvents();
		stage->update();
		stage->render();

		frameTime = SDL_GetTicks() - frameStart;
		if (FRAME_DELAY > frameTime) {
			SDL_Delay(FRAME_DELAY - frameTime);
		}
	}

	stage->clean();
	return 0;
 }