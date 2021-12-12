#pragma once
#include "../Includes.h"
#include "SDL_image.h"

inline Size queryTextureSize(SDL_Texture* texture) {
	Size sizeOfTexture;
	SDL_QueryTexture(texture, NULL, NULL, &sizeOfTexture.x, &sizeOfTexture.y);
	return sizeOfTexture;
}

class TextureManager {
public:
	static SDL_Texture* LoadTexture(SDL_Renderer* renderer, const char* fileName);
	static void Draw(SDL_Renderer* renderer, SDL_Texture* texture, SDL_Rect src, SDL_Rect dest);
};