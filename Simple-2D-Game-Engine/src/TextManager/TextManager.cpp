
#include "TextManager.h"


Text* TextManager::LoadText(SDL_Renderer *renderer, const char *fontFile, const char *text, int fontSize, Color &color) {
	static bool initializedTTF = false;
	if (!initializedTTF) {
		initializedTTF = true;
		TTF_Init();
	}
	//parameters: path to true type font and size in points
	TTF_Font *font;
	font = TTF_OpenFont(fontFile, fontSize);
	if (!font) {
		printf("TTF_OpenFont Error: %s\n", TTF_GetError());
	}

	SDL_Color c = { color.red, color.green, color.blue, color.alpha };
	SDL_Surface *textSurface = TTF_RenderText_Solid(font, text, c);
	TTF_CloseFont(font);
	
	SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, textSurface);
	SDL_FreeSurface(textSurface);

	Text *t = new Text();
	
	t->textTexture = texture;
	t->color = color;
	return t;
}

// add x and y
void TextManager::DrawText(SDL_Renderer *renderer, Text *text, int x, int y, int w, int h) {
	SDL_SetRenderDrawColor(renderer, text->color.red, text->color.green, text->color.blue, text->color.alpha);
	Point size = queryTextureSize(text->textTexture);
	const SDL_Rect source = {0, 0, size.x, size.y};
	const SDL_Rect destination = { x, y, w, h };
	SDL_RenderCopy(renderer, text->textTexture, &source, &destination);
}

