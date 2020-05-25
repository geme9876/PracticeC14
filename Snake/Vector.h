#pragma once
struct Vector2
{
	int x = 0;
	int y = 0;

	Vector2() {};
	Vector2(int newx, int newy) :x(newx), y(newy) {};

	Vector2 operator+(const Vector2& v) { return Vector2(x + v.x, y + v.y); };
	Vector2 operator-(const Vector2& v) { return Vector2(x - v.x, y - v.y); };
	bool operator==(const Vector2& v) { return x == v.x && y == v.y; }
	Vector2& operator+=(const Vector2& v) { (*this) = (*this) + v; return *this; };
	Vector2& operator-=(const Vector2& v) { (*this) = (*this) - v; return *this; };
	Vector2 operator*(const Vector2& v) { return Vector2(x * v.x, y * v.y); };
	Vector2 operator/(const Vector2& v) { return Vector2(x / v.x, y / v.y); };
	Vector2 operator*(int v) { return (*this) * Vector2(v, v); };
	Vector2 operator/(int v) { return (*this) / Vector2(v, v); };
	
};