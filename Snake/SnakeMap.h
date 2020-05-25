#pragma once
#include "Vector.h"
#include <vector>
#include <iostream>


class SnakeMap
{
public:
	SnakeMap(int x, int y) :MapSize(x, y) { 
		MapData.resize(y); 
		for (auto& md : MapData) 
		{ md.resize(x); } 
	};
	~SnakeMap() {};
	
public:
	const Vector2& GetMapSize() { return MapSize; }
	std::vector<std::vector<int>>& GetMapData() { return MapData; }
	
	void ClearMap()
	{
		for (auto& mdY : MapData)
		{
			for (auto& mdX : mdY)
			{
				mdX = 0;
			}
		}
	}

	void SetMapData(const Vector2& v, int value)
	{
		if (v.x < 0 || v.x >= MapSize.x) return;
		if (v.y < 0 || v.y >= MapSize.y) return;
		GetMapData()[v.y][v.x] = value;
	}
	void Render()
	{
		for (const auto mdY : MapData)
		{
			for (const auto mdX : mdY)
			{
				switch (mdX)
				{
				case 0:
				{
					std::cout << "¡à" << ' ';
					break;
				}
				case 1:
				{
					std::cout << "£À" << ' ';
					break;
				}
				case 2:
				{
					std::cout << "¢¾" << ' ';
					break;
				}
				case 3:
				{
					std::cout << "¡Ø" << ' ';
					break;
				}
				default:
					break;
				}
			}
			std::cout << std::endl;
		}
	}
	
private:
	Vector2 MapSize;
	std::vector<std::vector<int>> MapData;
};

