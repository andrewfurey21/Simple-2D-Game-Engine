#include "Entity.h"
#include "../TextureManager/TextureManager.h"


Entity::Entity(SDL_Renderer* renderer, const char* textureFile, int x, int y, int w, int h) {
	position.set(0, 0);
	entityTexture = TextureManager::LoadTexture(renderer, textureFile);
	Size sourceSize = queryTextureSize(entityTexture);
	source.w = sourceSize.x;
	source.h = sourceSize.y;
	source.x = 0;
	source.y = 0;
	destination.w = w;
	destination.h = h;
	position.x = (float)x;
	position.y = (float)y;
}

void Entity::Update() {
	destination.x = (int)position.x;
	destination.y = (int)position.y;
}

void Entity::Render(SDL_Renderer* renderer) {
	SDL_RenderCopy(renderer, entityTexture, &source, &destination);
}