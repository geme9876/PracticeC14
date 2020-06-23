//#include <string>
//#include <vector>
//#include <algorithm>
//#include <map>
//#include <set>
//using namespace std;
//
//// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
//
//
//
//bool IsInBoard(int x, int y, int BoardSize)
//{
//	if (x < 0 || x >= BoardSize || y < 0 || y >= BoardSize) return false;
//	return true;
//}
//
//
//bool check(int srcX, int srcY, int destX, int destY, vector<string>& board)
//{
//	int Rect[4];
//	Rect[0] = srcX < destX ? srcX : destX;
//	Rect[1] = srcY < destY ? srcY : destY;
//	Rect[2] = srcX > destX ? srcX : destX;
//	Rect[3] = srcY > destY ? srcY : destY;
//
//
//	bool answer = true;
//	{
//		for (int i = Rect[0];i <= Rect[2];i++)
//		{
//			char node = board[i][Rect[1]];
//			if (node == '*' || (node != '.' && node != board[srcX][srcY]))
//			{
//				answer = false; break;
//			}
//		}
//		if (answer)
//		{
//			for (int j = Rect[1]; j <= Rect[3];j++)
//			{
//				char node = board[Rect[0]][j];
//				if (node == '*' || (node != '.' && node != board[srcX][srcY]))
//				{
//					answer = false; break;
//				}
//			}
//		}
//		if (answer)
//		{
//			return answer;
//		}
//	}
//
//	answer = true;
//	{
//		for (int i = Rect[0];i <= Rect[2];i++)
//		{
//			char node = board[i][Rect[3]];
//			if (node == '*' || (node != '.' && node != board[srcX][srcY]))
//			{
//				answer = false; break;
//			}
//		}
//		if (answer)
//		{
//			for (int j = Rect[1]; j <= Rect[3];j++)
//			{
//				char node = board[Rect[1]][j];
//				if (node == '*' || (node != '.' && node != board[srcX][srcY]))
//				{
//					answer = false; break;
//				}
//			}
//		}
//	}
//	return answer;
//}
//
//
//string solution(int m, int n, vector<string> board) {
//	string answer = "";
//	vector<vector<pair<int, int>>> list;
//	map<int, set<char>, greater<int>> result;
//	list.resize(26);
//	int iNumCard = 0;
//	vector<char> destroyNode;
//	for (int i = 0; i < m;i++)
//	{
//		for (int j = 0;j < n;j++)
//		{
//			//먼저 해당 노드가 벽이나 비어있는 노드가 아닌지 확인
//			if (board[i][j] != '*' && board[i][j] != '.')
//			{
//				list[board[i][j] - 65].push_back({ i,j });
//				iNumCard++;
//			}
//		}
//	}
//
//	iNumCard /= 2;
//
//	while (iNumCard)
//	{
//		int checkLast = iNumCard;
//		for (int i = 0;i < 26;i++)
//		{
//			char c = i + 65;
//			if (list[i].size())
//			{
//				if (check(list[i][0].first, list[i][0].second, list[i][1].first, list[i][1].second, board))
//				{
//					iNumCard--;
//					result[iNumCard].insert(i + 65);
//					board[list[i][0].first][list[i][0].second] = '.';
//					board[list[i][1].first][list[i][1].second] = '.';
//					list[i].clear();
//				}
//			}
//		}
//		if (checkLast == iNumCard)
//		{
//			return "IMPOSSIBLE";
//		}
//
//	}
//
//	for (auto r : result)
//	{
//		for (auto a : r.second)
//		{
//			answer += a;
//		}
//	}
//
//	return answer;
//}
//
//
//
//int main()
//{
//	vector<string> s = { "DBA","C*A","CDB" };
//
//	solution(3, 3, s);
//
//}