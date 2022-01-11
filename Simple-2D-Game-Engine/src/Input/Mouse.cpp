#include "Mouse.h"

void Mouse::setCursor(const char* fileName) {
	SDL_Surface* cursorSurface = IMG_Load(fileName);
	cursor = SDL_CreateColorCursor(cursorSurface, 0, 0);
	if (!cursor) {
		std::cout << "Could not load cursor" << std::endl;
	} else {
		SDL_SetCursor(cursor);
	}
}

void Mouse::set() {
	SDL_GetMouseState(&x, &y);
}