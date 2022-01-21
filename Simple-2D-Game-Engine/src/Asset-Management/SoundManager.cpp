
#include "SoundManager.h"


Mix_Chunk* SoundManager::loadSound(const char* fileName) {
	return Mix_LoadWAV(fileName);
}

void SoundManager::playSound(Mix_Chunk* sound) {
	Mix_PlayChannel(-1, sound, 0);
}