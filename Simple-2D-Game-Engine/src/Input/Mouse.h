#pragma once
#include "../Includes.h"

class Mouse {
public:
	~Mouse() { SDL_FreeCursor(cursor); }
	void set();
	void setCursor(const char* fileName);
	SDL_Cursor* cursor;

private:
	int x, y;
	bool left = false;
	bool middle = false;
	bool right = false;
};