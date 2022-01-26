#pragma once

class float2 {
public:
	float2() : x(0), y(0) {};
	float2(float x, float y) : x(x), y(y) {}

	void rotate(float angle, const float2& translate=float2());
	
	void set(float x, float y);

	void setMagnitude(float scalar);
	float magnitude() const;

	static float dot(const float2& a, const float2& b);

	void scale(float scalar);
	void operator*=(float scalar);
	void operator/=(float scalar);


	void add(const float2& other);
	void operator+=(const float2& other);

	void sub(const float2& other);
	void operator-=(const float2& other);


public:
	float x = 0, y = 0;

};

inline float2 normalize(const float2& v) {
	float mag = v.magnitude();
	return float2(v.x / mag, v.y / mag);
}

inline std::ostream& operator<<(std::ostream& out, const float2& vector) {
	return out << vector.x << " " << vector.y << " ";
}

inline float2 operator+(const float2& u, const float2& v) {
	return float2(u.x + v.x, u.y + v.y);
}

inline float2 operator-(const float2& u, const float2& v) {
	return float2(u.x - v.x, u.y - v.y);
}

inline float2 operator*(double t, const float2& v) {
	return float2(t * v.x, t * v.y);
}

inline float2 operator*(const float2& v, double t) {
	return t * v;
}

inline float2 operator/(const float2& v, double t) {
	return (1 / t) * v;
}
