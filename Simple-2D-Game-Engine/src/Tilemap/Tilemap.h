#pragma once
#include "../Includes.h"

class Tilemap {
public:
	Tilemap(SDL_Renderer* renderer);
	~Tilemap();

	void LoadMap(SDL_Renderer* renderer, int level[20][25]);
	void DrawMap(SDL_Renderer* renderer);
private:
	SDL_Rect src, dest;
	SDL_Texture* dirt;
	SDL_Texture* grass;
	SDL_Texture* water;
	
	int map[20][25];
};