#pragma once
#include <list>
#include "Vector.h"


struct SnakeBody
{
	Vector2 Pos;
	Vector2 Dir;
};



class Snake
{
public:
	enum SnakeState
	{
		Alive,
		Dead,
	};

	Snake(Vector2 mapSize) :MapSize(mapSize) 
	{ 
		Pos = MapSize / 2; 
		Dir = Vector2(0, 1);
		SnakeBody Head;
		Head.Pos = Pos;
		Head.Dir = Dir;
		Body.push_back(Head);
		AddBody();
		state = SnakeState::Alive;
	};
	~Snake() {};

	Vector2 Pos;
	Vector2 Dir;
	Vector2 MapSize;
	float speed = 1.f;
	float MoveTimer = 0.f;
	SnakeState state;
public:
	std::list<SnakeBody> Body;
public:
	void SetState(SnakeState newState)
	{
		state = newState;
	}
	
	void SetDirectin(int x, int y)
	{
		Dir = Vector2(x, y);
		Body.front().Dir = Dir;
	}
	void MoveSnake(int x,int y)
	{
		Pos = Vector2(x, y);
		SnakeBody newBody;
		newBody.Dir = Dir;
		newBody.Pos = Pos;
		for (auto body = Body.begin(); body != Body.end(); body++)
		{
			SnakeBody tempBody = (*body);
			(*body) = newBody;
			tempBody = newBody;
		}
	}
	void AddBody()
	{
		SnakeBody newBody;
		newBody.Dir = Body.back().Dir;
		newBody.Pos = Body.back().Pos + (Dir * -1);
		Body.push_back(newBody);
	}
	void Frame(float delta)
	{
		if (state == SnakeState::Alive)
		{
			if (MoveTimer >= speed)
			{
				Vector2 MovePosition = Pos + Dir;
				if (CanMove(MovePosition))
				{
					MoveSnake(MovePosition.x, MovePosition.y);
				}
				else
				{
					state = SnakeState::Dead;
				}
				MoveTimer = 0.f;
			}
			MoveTimer += delta;
		}
	}
	bool CanMove(Vector2 newPos)
	{
		if ((newPos.x >= 0 || newPos.x < MapSize.x) && 
			(newPos.y >= 0 || newPos.y < MapSize.y)) 
			return true;

		return false;
	}
};

