#pragma once
#include "../Includes.h"

#include "../TextureManager/TextureManager.h"

struct Text {
	Color color;
	SDL_Texture* textTexture;
};

class TextManager {
public:
	static Text* LoadText(SDL_Renderer* renderer, const char* fontFile, const char* str, int fontSize, Color& color);
	static void DrawText(SDL_Renderer* renderer, Text* text, int x, int y, int w, int h);
};