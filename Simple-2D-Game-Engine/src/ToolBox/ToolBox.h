#pragma once
#include "../Includes.h"

//make it a singleton
class ToolBox {
public:
	void setColor(int r, int g, int b, int a = 255);
	void line(SDL_Renderer* renderer, int x1, int y1, int x2, int y2);
	void rect(SDL_Renderer* renderer, int _x, int _y, int _width, int _height);
	void point(SDL_Renderer* renderer, int x, int y);

private:
	Color fillColor;
	SDL_Rect rectangle;
};