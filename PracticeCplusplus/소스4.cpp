///*
//���� ����
//����, ���� ���̰� n�� ���簢�����ε� ü������ �ֽ��ϴ�. ü���� ���� n���� ���� ���θ� ������ �� ������ ��ġ�ϰ� �ͽ��ϴ�.
//
//���� �� n�� 4�ΰ�� ������ ���� ���� ��ġ�ϸ� n���� ���� ���θ� �ѹ��� ���� �� �� �����ϴ�.
//
//Imgur
//Imgur
//
//ü������ ���� ������ ������ ���� n�� �Ű������� �־��� ��, n���� ���� ���ǿ� ���� �ϵ��� ��ġ�� �� �ִ� ����� ���� return�ϴ� solution�Լ��� �ϼ����ּ���.
//
//���ѻ���
//��(Queen)�� ����, ����, �밢������ �̵��� �� �ֽ��ϴ�.
//n�� 12������ �ڿ��� �Դϴ�.
//����� ��
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
////���� ���θ� �������� �������� �ּ��� 2ĭ �̻��� ������ �ʿ���
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
//    //���� 4x4���� ���� ��� ���� �浹���� ���� ����� ����
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