#pragma once
#include "time.h"
#include "stdlib.h"


class Generator {
	
public:
	//combats against creating additional generators
	//called a copy constructor
	Generator(const Generator&) = delete;

	static Generator& Get() {
		static Generator generator;
		return generator;
	}
	static float Float() {
		return Get().InternalFloat();
	};
	static int Integer(int min, int max) { 
		return Get().InternalInteger(min, max); 
	}
private:

	Generator() { srand((unsigned int)time(0)); };
	int InternalInteger(int min, int max);
	float InternalFloat();
	static Generator s_Generator;

};  