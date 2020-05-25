#pragma once
#include <bitset>
#include <iostream>
#include "Tetrimino.h"
#include <string>
#define ROW 20
#define COL 10
class TMap
{
public:
	TMap() { MapData.resize(ROW); for (auto& map : MapData) map.resize(COL); };
	~TMap() {  };
	std::vector<std::vector<std::string>> MapData;


	void Render()
	{
		for (int i = ROW -1; i >= 0; --i)
		{
			for (int j = 0; j < COL; j++)
			{
				std::cout << (MapData[i][j]) << ' ';
			}
			std::cout << std::endl;
		}
	}
};

