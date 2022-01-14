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

void Mouse::down(SDL_MouseButtonEvent& b) {
	switch (b.button) {
	case SDL_BUTTON_LEFT:
		left = true;
		right = false;
		middle = false;
		break;
	case SDL_BUTTON_RIGHT:
		left = false;
		right = true;
		middle = false;
		break;
	case SDL_BUTTON_MIDDLE:
		left = false;
		right = false;
		middle = true;
		break;
	default:
		left = false;
		right = false;
		middle = false;
	}
}

void Mouse::up() {
	left = false;
	right = false;
	middle = false;
}