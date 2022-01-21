#pragma once

#include "../Includes.h"

class SoundManager {
public:
	static Mix_Chunk* loadSound(const char* fileName);
	static void playSound(Mix_Chunk* sound);
};