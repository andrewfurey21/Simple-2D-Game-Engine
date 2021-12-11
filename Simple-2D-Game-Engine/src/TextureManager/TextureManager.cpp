#include "TextureManager.h"



SDL_Texture* TextureManager::LoadTexture(SDL_Renderer* renderer, const char* fileName) {
	static bool pngInit = false;
	if (!pngInit) {
		pngInit = true;
		if (IMG_Init(IMG_INIT_PNG) != IMG_INIT_PNG) {
			printf("Error: PNG did not initialize");
		}
	}

	SDL_Surface* tempSurface = IMG_Load(fileName);
	SDL_ConvertSurfaceFormat(tempSurface, SDL_PIXELFORMAT_RGBA32, 0);
	if (!tempSurface) {
		std::cerr << "Temporary surface did not load: " << IMG_GetError() << std::endl;
	}
	SDL_Texture* tex = SDL_CreateTextureFromSurface(renderer, tempSurface);
	if (!tex) {
		std::cerr << "Failed to create player texture" << std::endl;
	}
	SDL_FreeSurface(tempSurface);
	return tex;
}

void TextureManager::Draw(SDL_Renderer* renderer, SDL_Texture* texture, SDL_Rect src, SDL_Rect dest) {
	SDL_RenderCopy(renderer, texture, &src, &dest);
}