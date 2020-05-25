#pragma once

#include "Snake.h"
#include "SnakeMap.h"
#include "SimpleTimer.h"
#include "Object.h"
class Game
{
public:
	SnakeMap map;
	Snake snake;
	SimpleTimer timer;
	std::list<Vector2> Edible;
	std::list<Vector2> Obstacle;

	float ObstacleTimer = 0.f;
	float EdibleTimer = 0.f;

	Game(int x,int y): map(x,y),snake(map.GetMapSize())  {};
	~Game() {};
	void input();
	void Render(float delta);
	void Frame(float delta);
	void Run();


	bool CheckSnakeAround(Vector2& Pos);
	void SpawnObj(int type);
	void SetSpawnerTimer(float& timer);
	void CheckSpawner(float delta);
	void PutMapData();
	void CheckEdible();
};

