#include "Generator.h"

//could use templated or generic types...
int Generator::InternalInteger(int min, int max) {
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<int> distribution(min, max);
	return distribution(gen);
}

float Generator::InternalFloat(float min, float max) {
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_real_distribution<float> distribution(min, max);
	return distribution(gen);
}

void Generator::InternalNoise(int count, float* seed, int octaves, float* output) {
	for (int x = 0; x < count; x++) {
		float noise = 0.0f;
		float scale = 1.0f;

		float acculumateScale = 0;
		for (int o = 0; o <= octaves; o++) {
			int pitch = count >> o;
			if (pitch == 0) break;
			int sample1 = (x / pitch) * pitch;
			int sample2 = (sample1 + pitch) % count;
			float blend = (float)(x - sample1) / (float)pitch;
			float sample = (1.0 - blend) * seed[sample1] + blend * seed[sample2];
			noise += sample * scale;
			acculumateScale += scale;

			scale /= 2.0f;
		}
		output[x] = noise / acculumateScale;
	}
}
