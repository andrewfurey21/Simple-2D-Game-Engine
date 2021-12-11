#pragma once
#include "../Includes.h"
#include "../Math/Vector/Float2.h"

class Entity {
public:
	Entity(SDL_Renderer* renderer, const char* textureFile);

	void Update();
	void Render(SDL_Renderer* renderer);

	Float2 position;

private:
	SDL_Texture* entityTexture;
	SDL_Rect srcRect, destRect;
};