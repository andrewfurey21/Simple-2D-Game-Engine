#include "Entity.h"
#include "../TextureManager/TextureManager.h"


Entity::Entity(SDL_Renderer* renderer, const char* textureFile) {
	position.set(0, 0);
	entityTexture = TextureManager::LoadTexture(renderer, textureFile);
	srcRect.w = 256;
	srcRect.h = 256;

	srcRect.x = 0;
	srcRect.y = 0;
	destRect.x = 0;
	destRect.y = 0;
	destRect.w = 256;
	destRect.h = 256;
}

void Entity::Update() {
	destRect.x = (int)position.x;
	destRect.y = (int)position.y;
}

void Entity::Render(SDL_Renderer* renderer) {
	SDL_RenderCopy(renderer, entityTexture, nullptr, &destRect);
}