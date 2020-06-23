///*
//문제 설명
//가로, 세로 길이가 n인 정사각형으로된 체스판이 있습니다. 체스판 위의 n개의 퀸이 서로를 공격할 수 없도록 배치하고 싶습니다.
//
//예를 들어서 n이 4인경우 다음과 같이 퀸을 배치하면 n개의 퀸은 서로를 한번에 공격 할 수 없습니다.
//
//Imgur
//Imgur
//
//체스판의 가로 세로의 세로의 길이 n이 매개변수로 주어질 때, n개의 퀸이 조건에 만족 하도록 배치할 수 있는 방법의 수를 return하는 solution함수를 완성해주세요.
//
//제한사항
//퀸(Queen)은 가로, 세로, 대각선으로 이동할 수 있습니다.
//n은 12이하의 자연수 입니다.
//입출력 예
//n	result
//4	2
//*/
//
//#include <string>
//#include <vector>
//
//using namespace std;
//
//
//bool chess_map[12][12] = { false, };
//
////퀸이 서로를 공격하지 않으려면 최소한 2칸 이상의 간격이 필요함
//bool CheckBoard(int x, int y,int n)
//{
//    if (x >= 0 && x < n && y >= 0 && y < n)
//    {
//        return true;
//    }
//    return false;
//}
//
//vector<pair<int,int>> SetQueen(int x, int y, int n)
//{
//    vector<pair<int, int>> out;
//
//        for (int i = 1; i < n; i++)
//        {
//            if (CheckBoard(x - i, y - i, n))
//            {
//                out.push_back({ x - i,y - i });
//            }
//            if (CheckBoard(x + i, y + i, n))
//            {
//                out.push_back({ x + i,y + i });
//            }
//            if (CheckBoard(x + i, y - i, n))
//            {
//                out.push_back({ x + i,y - i });
//            }
//            if (CheckBoard(x - i, y + i, n))
//            {
//                out.push_back({ x - i,y + i });
//            }
//            if (CheckBoard(i, y, n))
//            {
//                out.push_back({  i,y });
//            }
//            if (CheckBoard(x,i, n))
//            {
//                out.push_back({ x,i });
//            }
//        }
//        return out;
//}
//
//
//void dfs(int x,int y, bool(*map)[12],int n,int cnt,int& answer)
//{
//
//    if (y >= n || map[x][y])
//    {
//        return;
//    }
//    if(cnt == n-1)
//    {
//        ++answer;
//        return;
//    }
//
//    vector<pair<int, int>> notSettablePos = SetQueen(x, y, n);
//
//
//
//    for (auto i : notSettablePos)
//    {
//        map[i.first][i.second] = true;
//    }
//    for (int i = 1; i < n;i++)
//    {
//        dfs(i, y + 1, map, n, cnt+1, answer);
//    }
//    for (auto j : notSettablePos)
//    {
//        map[j.first][j.second] = false;
//    }
//
//
//}
//
//int solution(int n) {
//    int answer = 0;
//
//    if (n < 4)
//    {
//    //맵이 4x4보다 작을 경우 서로 충돌하지 않을 방법은 없다
//        return answer;
//    }
//
//    for (int i = 0; i < n;i++)
//    {
//        dfs(i, 0, chess_map, n, 0, answer);
//    }
//    
//     
//
//
//
//
//
//    return answer;
//}
//
//int main()
//{
//    int n = 4;
//    solution(n);
//    
//    return 0;
//}