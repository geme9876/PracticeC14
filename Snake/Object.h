#pragma once
#include "Vector.h"
class Object
{
public:
	enum Type
	{
		Edible,
		Obstacle
	};
	int type;
	Vector2 Pos;
	Object(int newx, int newy, int newtype) : type(newtype), Pos(newx, newy) {};
	~Object() = default;
};

