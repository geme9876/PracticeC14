#include <iostream>
#include "TMap.h"
#include "SimpleTimer.h"
#include <conio.h>

SimpleTimer timer;
TMap map;
Tetrimino mino;
float DownTimer=0.f;



bool isBoarder(const Point& a)
{
	if (a.x < 0 || a.x >= COL)
	{
		return true;
	}
	if (a.y < 0)
	{
		return true;
	}
	return false;
}

bool isBoarderBric(const Bric& b)
{
	for (int i = 0; i < 4; ++i)
	{
		if(isBoarder(b.block[i])) return true;
	}
	return false;
}

bool isOnSet(Point a)
{
	if (!isBoarder(a))
	{
		if (a.y <= 0 || map.MapData[a.y - 1][a.x] == "¢Ë")
		{
			return true;
		}
	}
	return false;
}

bool isOnSetBric(Bric& a)
{
	for (int i = 0; i < 4; i++)
	{
		if (!isBoarder(a.block[i]))
		{
			if (a.block[i].y <= 0 || map.MapData[a.block[i].y - 1][a.block[i].x] == "¢Ë")
			{
				return true;
			}
		}
	}
	return false;
}


void ClearLine()
{
	for (int i = 0 ; i< map.MapData.size();  ++i)
	{
		bool bClear = true;
		for (int j = 0; j < map.MapData[i].size(); j++)
		{
			if (map.MapData[i][j] == "¡à")
			{
				bClear = false;
				break;
			}
		}
		if (bClear)
		{
			for(int k = i; k < map.MapData.size()-1; k++)
			{
				map.MapData[k] = map.MapData[k+1];
			}
			map.MapData[19].assign(10, "¡à");
			++i;
		}
	}


}


void ClearMap()
{
	for (auto& data : map.MapData)
	{
		for (auto& data2 : data)
		{
			if (data2 != "¢Ë")
				data2 = "¡à";
		}
	}
}

void DropBric()
{
	if (DownTimer > 1.f)
	{

		if(!isBoarderBric(mino.GetWorldBric(mino.CurrentPos.x, mino.CurrentPos.y - 1)))
		{
			mino.MovePos(mino.CurrentPos.x, mino.CurrentPos.y - 1);
		}
		DownTimer = 0.f;
		//ClearLine();
	}
}

void FillCurrentBric()
{
	Bric br = mino.GetWorldBric(mino.CurrentPos);
	for (int i = 0; i < 4; ++i)
	{
		if (!isBoarder(br.block[i]))
		{
			if(br.block[i].y < ROW)
			map.MapData[br.block[i].y][br.block[i].x] = "¡á";
		}
	}
}

void SetOnDropedBric()
{
	Bric br = mino.GetWorldBric(mino.CurrentPos);
	if (isOnSetBric(br))
	{
		for (int i = 0; i < 4; ++i)
		{
			if (!isBoarder(br.block[i]))
			{
				map.MapData[br.block[i].y][br.block[i].x] = "¢Ë";
			}
		}
		mino.GetBric();
	}
}


void input()
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

					++mino.CurrentRotation;
					if (mino.CurrentRotation >= 4)
					{
						mino.CurrentRotation = 0;
					}
					if (isBoarderBric(mino.GetWorldBric(mino.CurrentPos)))
					{
						--mino.CurrentRotation;
						if (mino.CurrentRotation >= 4)
						{
							mino.CurrentRotation = 0;
						}
						else if(mino.CurrentRotation < 0)
						{
							mino.CurrentRotation = 3;
						}
					}
				
				break;
			}
			case 75:
			{
				//ÁÂ
				if (!isBoarderBric(mino.GetWorldBric(mino.CurrentPos.x - 1, mino.CurrentPos.y)))
				{
					mino.MovePos(mino.CurrentPos.x - 1, mino.CurrentPos.y);
				}
				break;
			}
			case 77:
			{
				//¿ì
				if (!isBoarderBric(mino.GetWorldBric(mino.CurrentPos.x + 1, mino.CurrentPos.y)))
				{
					mino.MovePos(mino.CurrentPos.x + 1, mino.CurrentPos.y);
				}
				break;
			}
			case 80:
			{
				//ÇÏ
				if (!isBoarderBric(mino.GetWorldBric(mino.CurrentPos.x, mino.CurrentPos.y - 1)))
				{
					mino.MovePos(mino.CurrentPos.x, mino.CurrentPos.y - 1);
				}
				break;
			}
			default:
				break;
			}
		}
	}
}



void Frame(float delta)
{
	ClearMap();
	DropBric();
	input();
	FillCurrentBric();
	SetOnDropedBric();
	ClearLine();
	DownTimer+= delta;
};



void Render(float delta)
{
	map.Render();
	system("cls");
};

int main()
{

	mino.GetBric();
	while (1)
	{
		float delta = timer.Mark();
		Frame(delta);
		Render(delta);
	}

	return 0;
}


