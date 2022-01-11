#pragma once
#include "../Includes.h"


class GameManager {
public:
	GameManager();
	~GameManager();

	void init(const char* title, int width, int height, bool fullscreen);
	void handleEvents();
	void update();
	void render();
	void clean();
	bool running() { return isRunning; }

	SDL_Renderer* renderer;
	static SDL_Event event;

private:
	bool isRunning = false;
	SDL_Window *window;
	bool checkForKeyPress(SDL_Scancode scanCode);
	int width, height;
};