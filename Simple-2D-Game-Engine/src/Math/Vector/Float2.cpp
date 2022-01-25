
#include "../../Includes.h"
#include "float2.h"

void float2::rotate(float angle, const float2& translation) {
	add(translation);
	float tempX = x * cos(-angle) - y * sin(-angle);
	float tempY = x * sin(-angle) + y * cos(-angle);
	x = tempX;
	y = tempY;
	sub(translation);
}

float float2::magnitude() const {
	return (float)(sqrt(pow(this->x, 2) + pow(this->y, 2)));
}

float float2::dot(float2 a, float2 b) {
	return a.x * b.x + a.y * b.y;
}

void float2::setMagnitude(float scalar) {
	normalize(*this);
	scale(scalar);
}

void float2::set(float x, float y) {
	this->x = x;
	this->y = y;
}

void float2::add(const float2& other) {
	x += other.x;
	x += other.y;
}

void float2::operator+=(const float2& other) {
	add(other);
}

void float2::sub(const float2& other) {
	x -= other.x;
	x -= other.y;
}
void float2::operator-=(const float2& other) {
	sub(other);
}

void float2::scale(float scalar) {
	x *= scalar;
	y *= scalar;
}

void float2::operator*=(float scalar) {
	scale(scalar);
}

void float2::operator/=(float scalar) {
	scale(1.0/scalar);
}
