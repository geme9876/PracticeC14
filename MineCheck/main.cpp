


#include <iostream>
#include <vector>
#include <string>
#include <random>
#include <queue>
#include <set>
#include <sstream>

using namespace std;
void printBoard(vector<string>& board)
{
	for (int y = 0;y < board.size();y++)
	{
		for (int x = 0; x < board[y].size();x++)
		{
			cout << board[y][x] << " ";
		}
		cout << endl;
	}
	cout << endl;
}


bool IsBoarder(vector<string>& board, int y, int x)
{
	int MAXY = board.size();
	int MAXX = board[0].size();
	
	if (y >= 0 && y < MAXY && x >= 0 && x < MAXX)
	{
		return true;
	}
	return false;
}

void Select(vector<string>& board,int y, int x)
{
	vector<pair<int, int>> dir{ {0,1}, {1,0},{0,-1},{-1,0},{1,1},{-1,-1},{-1,1},{1,-1} };
	queue<pair<int, int>> openlist;
	set<pair<int, int>> closelist;
	
	//선택한 지점이 MINE인가 아닌가
	if (IsBoarder(board, y, x))
	{
		if (board[y][x] != 'M')
		{
			openlist.push({ y,x });
			while (!openlist.empty())
			{
				int mine = 0;
				
				int Y = openlist.front().first;
				int X = openlist.front().second;
				openlist.pop();

				closelist.insert({ X, Y });
				for (int i = 0;i < dir.size();i++)
				{
					//큐에서 꺼낸 위치 검사
					int nextY = Y + dir[i].first;
					int nextX = X + dir[i].second;
					pair<int, int> nextPos = { nextY,nextX };
					pair<int, int> nextPos2 = { nextY,nextX };

					if (closelist.find(nextPos) != closelist.end())continue;
					if (IsBoarder(board,nextY, nextX))
					{
						// 주변 위치 검사
						// 주변에 지뢰가 있는가? 종료
						// 지뢰가 없다면 주변 8개의 노드를 큐에 넣는다
						if (board[nextY][nextX] == 'M')
						{
							mine++;
						}
						else if(board[nextY][nextX] == 'E')
						{
							openlist.push({ nextY,nextX });
						}
					}
				}
				if (mine > 0)
				{
					board[Y][X] = mine+48;
				}
				else if (mine <= 0)
				{
					board[Y][X] = 'B';
				}
			}
		}
	}

	printBoard(board);
	cout << endl;
}





int main()
{
	
	vector<string> board{ "EEEEEMEEEEE","EEEEEEMEEEE" ,"EEMEEEEEEEE" ,"EEEEEEEEMEE","EEEEEEEEMEE","EEMEEEEEEEM","EEMEEEEEEEE" };

	printBoard(board);
	
	while (1)
	{
		string s;
		getline(cin, s);
		stringstream ss(s);

		int X=0;
		int Y = 0;
		ss >> X >> Y;

		Select(board, Y, X);
	}

	return 0;

}

