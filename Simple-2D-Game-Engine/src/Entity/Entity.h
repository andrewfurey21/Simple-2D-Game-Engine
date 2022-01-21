#pragma once
#include "../Includes.h"
#include "../Math/Vector/Float2.h"

class Entity {
public:
	Entity(SDL_Renderer* renderer, const char* textureFile, int x, int y, int w, int h);

	void Update();
	void Render(SDL_Renderer* renderer);

	float2 position;


private:
	Size size;
	SDL_Texture* entityTexture;
	SDL_Rect source, destination;
};