
#include "../../Includes.h"
#include "float2.h"

float2::float2() {}

void float2::translate(float x, float y) {
	this->x += x;
	this->y += y;
}

void float2::rotate(float angle, float translateX, float translateY) {
	translate(translateX, translateY);
	float tempX = x * cos(-angle) - y * sin(-angle);
	float tempY = x * sin(-angle) + y * cos(-angle);
	x = tempX;
	y = tempY;
	translate(-translateX, -translateY);
}

float float2::magnitude() {
	return (float)(sqrt(pow(this->x, 2) + pow(this->y, 2)));
}

float float2::dot(float2 a, float2 b) {
	return a.x * b.x + a.y * b.y;
}

void float2::setMagnitude(float scalar) {
	normalize();
	scale(scalar);
}

void float2::normalize() {
	float tempX = x;
	float tempY = y;
	tempX /= magnitude();
	tempY /= magnitude();
	x = tempX;
	y = tempY;
}

void float2::set(float x, float y) {
	this->x = x;
	this->y = y;
}


float2 float2::sTranslate(float2 vector, float _x, float _y) {
	float2 translatedVector = float2(vector.x + _x, vector.y + _y);
	return translatedVector;
}

//const at the end means it should not change the current object
float2 float2::add(const float2& other) const {
	return float2(x + other.x, y+other.y);
}

float2 float2::operator+(const float2& other) const {
	return add(other);
}

float2 float2::sub(const float2& other) const {
	return float2(x - other.x, y - other.y);
}
float2 float2::operator-(const float2& other) const {
	return sub(other);
}

float2 float2::scale(float scalar) const {
	return float2(x * scalar, y * scalar);
}

float2 float2::operator*(const float scalar) const {
	return scale(scalar);
}
