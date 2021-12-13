
#include "../../Includes.h"
#include "Float2.h"

Float2::Float2() {}

void Float2::translate(float x, float y) {
	this->x += x;
	this->y += y;
}

void Float2::rotate(float angle, float translateX, float translateY) {
	translate(translateX, translateY);
	float tempX = x * cos(-angle) - y * sin(-angle);
	float tempY = x * sin(-angle) + y * cos(-angle);
	x = tempX;
	y = tempY;
	translate(-translateX, -translateY);
}

float Float2::magnitude() {
	return (float)(sqrt(pow(this->x, 2) + pow(this->y, 2)));
}

float Float2::dot(Float2 a, Float2 b) {
	return a.x * b.x + a.y + b.y;
}

void Float2::setMagnitude(float scalar) {
	normalize();
	scale(scalar);
}

void Float2::normalize() {
	float tempX = x;
	float tempY = y;
	tempX /= magnitude();
	tempY /= magnitude();
	x = tempX;
	y = tempY;
}

void Float2::set(float x, float y) {
	this->x = x;
	this->y = y;
}


Float2 Float2::sTranslate(Float2 vector, float _x, float _y) {
	Float2 translatedVector = Float2(vector.x + _x, vector.y + _y);
	return translatedVector;
}

//const at the end means it should not change the current object
Float2 Float2::add(const Float2& other) const {
	return Float2(x + other.x, y+other.y);
}

Float2 Float2::operator+(const Float2& other) const {
	return add(other);
}

Float2 Float2::sub(const Float2& other) const {
	return Float2(x - other.x, y - other.y);
}
Float2 Float2::operator-(const Float2& other) const {
	return sub(other);
}

Float2 Float2::scale(float scalar) const {
	return Float2(x * scalar, y * scalar);
}

Float2 Float2::operator*(const float scalar) const {
	return scale(scalar);
}
