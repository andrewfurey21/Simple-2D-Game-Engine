#pragma once
#include "time.h"
#include "stdlib.h"
#include "../../Includes.h"
#include <random>


class Generator {
	
public:
	//combats against creating additional generators
	//called a copy constructor
	Generator(const Generator&) = delete;

	static Generator& Get() {
		static Generator generator;
		return generator;
	}
	static float Float(float min, float max) {
		return Get().InternalFloat(min, max);
	};
	static int Integer(int min, int max) { 
		return Get().InternalInteger(min, max); 
	}

	static void Noise(int count, float* seed, int octaves, float* output) {
		return Get().InternalNoise(count, seed, octaves, output);
	}

private:
	Generator() {}
	int InternalInteger(int min, int max);
	float InternalFloat(float min, float max);
	void InternalNoise(int count, float* seed, int octaves, float* output);

};  