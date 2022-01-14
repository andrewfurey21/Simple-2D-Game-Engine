#pragma once
#include "../Includes.h"

class Mouse {
public:
	~Mouse() { SDL_FreeCursor(cursor); }
	void set();
	void setCursor(const char* fileName);
	void down(SDL_MouseButtonEvent& b);
	void up();
	SDL_Cursor* cursor;

	int x, y;
	bool left = false;
	bool middle = false;
	bool right = false;
};