#include "Tetrimino.h"

 Tetrimino::Tetrimino() {
	Brics[0][0] = { { 0,0 },{ 1,0 },{ -1,0 },{ -2,0 } };
	Brics[1][0] = { { 0,0 },{ 1,0 },{ 1,1 },{ 0,1 } };
	Brics[2][0] = { { 0,0 },{ -1,0 },{ 1,0 },{ -1,1 } };
	Brics[3][0] = { { 0,0 },{ -1,0 },{ 1,0 },{ 1,1 } };
	Brics[4][0] = { { 0,0 },{ 1,0 },{ 1,-1 },{ 0,1 } };
	Brics[5][0] = { { 0,0 },{ -1,0 },{ -1,-1 },{ 0,1 } };
	Brics[6][0] = { { 0,0 },{ -1,0 },{ 1,0 },{ 0,1 } };
	for (int i = 0; i < 7; i++)
	{
		for (int j = 1; j < 4; j++)
		{
			Brics[i][j] = Brics[i][j - 1].Rotate();
		}
	}

}

 void Tetrimino::GetBric()
{
	std::mt19937 mt(rd());
	std::uniform_int_distribution<int> dis(0, 6);
	std::uniform_int_distribution<int> dis2(0, 3);
	CurrentBric = dis(mt);
	CurrentRotation = dis2(mt);
	CurrentPos = { 5,19 };
}

 void Tetrimino::MovePos(int x, int y)
{
	CurrentPos = Point(x, y);
}

 Bric Tetrimino::GetWorldBric(Point& pos)
{
	Bric bric =
	{
		Brics[CurrentBric][CurrentRotation].block[0] + pos,
		Brics[CurrentBric][CurrentRotation].block[1] + pos,
		Brics[CurrentBric][CurrentRotation].block[2] + pos,
		Brics[CurrentBric][CurrentRotation].block[3] + pos
	};
	return bric;
}

 Bric Tetrimino::GetWorldBric(int a, int b)
{
	Point p(a, b);
	Bric bric =
	{
		Brics[CurrentBric][CurrentRotation].block[0] + p,
		Brics[CurrentBric][CurrentRotation].block[1] + p,
		Brics[CurrentBric][CurrentRotation].block[2] + p,
		Brics[CurrentBric][CurrentRotation].block[3] + p
	};
	return bric;
}
