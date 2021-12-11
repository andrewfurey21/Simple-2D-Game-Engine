#pragma once

class Color {
public:
	uint8_t red = 0;
	uint8_t blue = 0;
	uint8_t green = 0;
	uint8_t alpha = 255;
	void set(uint8_t r, uint8_t g, uint8_t b, uint8_t a=255) {
		red = r;
		blue = b;
		green = g;
		alpha = a;
	}
};


