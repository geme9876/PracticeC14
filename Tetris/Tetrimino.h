#pragma once
#include <random>


struct  Point
{
	int x=0;
	int y=0;
	Point() {};
	Point(int newx, int newy)
	{
		x = newx;
		y = newy;
	}
	Point operator+(const Point& a) { return Point(x + a.x, y + a.y); };
	Point operator-(const Point& a) { return Point(x - a.x, y - a.y); };
	bool operator==(const Point& a) {return x == a.x && y == a.y ? true : false; };
	bool operator!=(const Point& a) { return !operator==(a); };
};
struct Bric
{
	Point block[4];
	Bric() {};
	Bric(Point a, Point b, Point c, Point d)
	{
		block[0] = a;
		block[1] = b;
		block[2] = c;
		block[3] = d;
	}
	Bric Rotate()
	{
		Bric rotatebric;
		for (int i = 0; i < 4; i++)
		{
			rotatebric.block[i] =
			{
				block[i].y ,
				-block[i].x
			};
		}
		return rotatebric;
	}
};



class Tetrimino
{
public:
	Tetrimino();;
	~Tetrimino() {};


	Bric Brics[7][4];
	int CurrentBric=0;
	int CurrentRotation=0;

	Point CurrentPos{ 5,19 };
	std::random_device rd;
	void GetBric();
	void MovePos(int x, int y);
	Bric GetWorldBric(Point& pos);
	Bric GetWorldBric(int a, int b);
};

