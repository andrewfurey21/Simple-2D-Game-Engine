#pragma once
#include "time.h"
#include "stdlib.h"
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

private:
	Generator() {}
	int InternalInteger(int min, int max);
	float InternalFloat(float min, float max);
	static Generator s_Generator;

};  