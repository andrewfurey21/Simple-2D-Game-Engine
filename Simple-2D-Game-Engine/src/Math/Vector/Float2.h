#pragma once

class Float2 {
public:
	float x = 0, y = 0;
	Float2();
	Float2(float x, float y) : x(x), y(y) {}

	void translate(float x, float y);
	void rotate(float angle, float translateX = 0, float translateY = 0);
	
	void normalize();
	void set(float x, float y);
	void setMagnitude(float scalar);
	float magnitude();

	static float dot(Float2 a, Float2 b);

	Float2 scale(float scalar) const;
	Float2 operator*(const float scalar) const;

	Float2 add(const Float2& other) const;
	Float2 operator+(const Float2& other) const;

	Float2 sub(const Float2& other) const;
	Float2 operator-(const Float2& other) const;

	static Float2 sTranslate(Float2 vector, float x, float y) ;
};
