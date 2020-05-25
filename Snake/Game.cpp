#include "Game.h"
#include <conio.h>
#include <random>
bool Game::CheckSnakeAround(Vector2& Pos)
{
	for (auto sn : snake.Body)
	{
		if (Pos.x >= sn.Pos.x + 3 || Pos.x <= sn.Pos.x - 3 && 
			Pos.y >= sn.Pos.y + 3 || Pos.y <= sn.Pos.y - 3)
			return false;
	}
	return true;
}
void Game::input()
{
		if (_kbhit())
		{
			int keyboard = _getch();
			if (keyboard == 224)
			{
				keyboard = _getch();
				switch (keyboard)
				{
				case 72:
				{
					snake.SetDirectin(0, -1);
					break;
				}
				case 75:
				{
					//аб
					snake.SetDirectin(-1, 0);
					break;
				}
				case 77:
				{
					//©Л
					snake.SetDirectin(1, 0);
					break;
				}
				case 80:
				{
					//го
					snake.SetDirectin(0, 1);
					break;
				}
				default:
					break;
				}
			}
		}
}

void Game::SpawnObj(int type)
{


	std::random_device rd;
	std::mt19937 mt(rd());
	Vector2 pos;
	do
	{
		std::uniform_real_distribution<float> dis(0, map.GetMapSize().x);
		std::uniform_real_distribution<float> dis2(0, map.GetMapSize().y);

		pos = Vector2(dis(mt), dis2(mt));
	} while ( CheckSnakeAround(pos) );

	
	switch (type)
	{
	case 0:
	{
		Edible.push_back(pos);
		break;
	}
	case 1:
	{
		Obstacle.push_back(pos);
		break;
	}
	default:
		break;
	}
}


void  Game::SetSpawnerTimer(float& timer)
{
	std::random_device rd;
	std::mt19937 mt(rd());

	std::uniform_real_distribution<float> dis(2.f, 5.f);
	timer = dis(mt);

}

void Game::CheckSpawner(float delta)
{
	if (EdibleTimer <= 0.f)
	{
		SpawnObj(0);
		SetSpawnerTimer(EdibleTimer);
	}
	if (ObstacleTimer <= 0.f)
	{
		SpawnObj(1);
		SetSpawnerTimer(ObstacleTimer);
	}
	EdibleTimer-= delta;
	ObstacleTimer -= delta;
}

void Game::PutMapData()
{
	for (auto sn : snake.Body)
	{
		map.SetMapData(sn.Pos, 1);
	}
	for (auto ed : Edible)
	{
		map.SetMapData(ed, 2);
	}
	for (auto ob : Obstacle)
	{
		map.SetMapData(ob, 3);
	}
}

void Game::Render(float delta)
{
	system("cls");
	map.Render();
}

void Game::Frame(float delta)
{
	input();
	map.ClearMap();
	CheckSpawner(delta);
	snake.Frame(delta);
	CheckEdible();
	PutMapData();
}


void Game::CheckEdible()
{
	for (auto iter = Edible.begin(); iter != Edible.end(); iter++)
	{
		if ((*iter) == snake.Pos)
		{
			snake.AddBody();
			Edible.erase(iter);
			break;
		}
	}
}
void Game::Run()
{
	float delta = timer.Mark();
	SetSpawnerTimer(EdibleTimer);
	SetSpawnerTimer(ObstacleTimer);
	while (1)
	{
		delta = timer.Mark();
		Frame(delta);
		Render(delta);
	}
}
