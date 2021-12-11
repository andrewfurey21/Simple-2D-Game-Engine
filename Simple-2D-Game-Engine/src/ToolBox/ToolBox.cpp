
#include "ToolBox.h"

void ToolBox::line(SDL_Renderer* renderer, int x1, int y1, int x2, int y2) {
	SDL_SetRenderDrawColor(renderer, fillColor.red, fillColor.green, fillColor.blue, fillColor.alpha);
	SDL_RenderDrawLine(renderer, x1, y1, x2, y2);
}

void ToolBox::rect(SDL_Renderer* renderer, int _x, int _y, int _width, int _height) {
	SDL_SetRenderDrawColor(renderer, fillColor.red, fillColor.green, fillColor.blue, fillColor.alpha);
	rectangle.x = _x;
	rectangle.y = _y;
	rectangle.w = _width;
	rectangle.h = _height;
	SDL_RenderFillRect(renderer, &rectangle);
}

void ToolBox::point(SDL_Renderer* renderer, int x, int y) {
	SDL_RenderDrawPoint(renderer, x, y);
}

void ToolBox::setColor(int r, int g, int b, int a) {
	fillColor.red = r;
	fillColor.green = g;
	fillColor.blue = b;
	fillColor.alpha = a;
}
