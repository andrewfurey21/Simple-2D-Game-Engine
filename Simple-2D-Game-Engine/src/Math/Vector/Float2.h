#pragma once

class float2 {
public:
	float x = 0, y = 0;
	float2();
	float2(float x, float y) : x(x), y(y) {}

	void translate(float x, float y);
	void rotate(float angle, float translateX = 0, float translateY = 0);
	
	void normalize();
	void set(float x, float y);
	void setMagnitude(float scalar);
	float magnitude();

	static float dot(float2 a, float2 b);

	float2 scale(float scalar) const;
	float2 operator*(const float scalar) const;

	float2 add(const float2& other) const;
	float2 operator+(const float2& other) const;

	float2 sub(const float2& other) const;
	float2 operator-(const float2& other) const;

	static float2 sTranslate(float2 vector, float x, float y) ;
};
