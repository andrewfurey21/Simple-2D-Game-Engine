#include "Generator.h"

//Generator::Generator() {
//	
//}

//does not include max
int Generator::InternalInteger(int min, int max) {
	//use c++ random generator (this is more for c)
	//someone said its not good for threads. i should look at using threads and concurrency
	return rand()%(max-min) + min;
}

float Generator::InternalFloat() {
	return float(rand()) / RAND_MAX;
}