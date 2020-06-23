///*
//
//
//���� ����
//��������� Ʃ��� ��� ���������� ������ ������ ������ ������ �����Ǵ� ����� ���� �߰��Ͽ����ϴ�. �׷��� ���� ������ ���캸�� Ư���� ������ �ڹ���� ��� �־��� �� �տ��� Ư���� ������ ����� �Բ� �ڹ��踦 Ǫ�� ����� ���� ������ ���� ������ �ִ� ���̰� �߰ߵǾ����ϴ�.
//
//����ִ� �ڹ���� ���� �� ĭ�� ũ�Ⱑ 1 x 1�� N x N ũ���� ���簢 ���� �����̰� Ư���� ����� ����� M x M ũ���� ���簢 ���� ���·� �Ǿ� �ֽ��ϴ�.
//
//�ڹ��迡�� Ȩ�� �Ŀ� �ְ� ���� ���� Ȩ�� ���� �κ��� �ֽ��ϴ�. ����� ȸ���� �̵��� �����ϸ� ������ ���� �κ��� �ڹ����� Ȩ �κп� �� �°� ä��� �ڹ��谡 ������ �Ǵ� �����Դϴ�. �ڹ��� ������ ��� �κп� �ִ� ������ Ȩ�� ����� �ڹ��踦 ���� �� ������ ���� ������, �ڹ��� ���� �������� ������ ���� �κа� �ڹ����� Ȩ �κ��� ��Ȯ�� ��ġ�ؾ� �ϸ� ������ ����� �ڹ����� ���Ⱑ �������� �ȵ˴ϴ�. ���� �ڹ����� ��� Ȩ�� ä�� ����ִ� ���� ����� �ڹ��踦 �� �� �ֽ��ϴ�.
//
//���踦 ��Ÿ���� 2���� �迭 key�� �ڹ��踦 ��Ÿ���� 2���� �迭 lock�� �Ű������� �־��� ��, ����� �ڹ��踦 ���� ������ true��, �� �� ������ false�� return �ϵ��� solution �Լ��� �ϼ����ּ���.
//
//���ѻ���
//key�� M x M(3 �� M �� 20, M�� �ڿ���)ũ�� 2���� �迭�Դϴ�.
//lock�� N x N(3 �� N �� 20, N�� �ڿ���)ũ�� 2���� �迭�Դϴ�.
//M�� �׻� N �����Դϴ�.
//key�� lock�� ���Ҵ� 0 �Ǵ� 1�� �̷���� �ֽ��ϴ�.
//0�� Ȩ �κ�, 1�� ���� �κ��� ��Ÿ���ϴ�.
//����� ��
//key	lock	result
//[[0, 0, 0], [1, 0, 0], [0, 1, 1]]	[[1, 1, 1], [1, 1, 0], [1, 0, 1]]	true
//����� ���� ���� ����
//
//
//*/
//
//
//#include <string>
//#include <vector>
//#include <algorithm>
//using namespace std;
//
//
//vector<pair<int, int>> ToBoardSpace(const vector<vector<int>>& elem)
//{
//    vector<pair<int, int>> boardSpace;
//    for (int i=0;i<elem.size();i++)
//    {
//        for (int j = 0;j < elem[i].size();j++)
//        {
//            if (elem[i][j])
//            {
//                boardSpace.push_back(make_pair(i - 1, j - 1));
//            }
//        }
//    }
//    return boardSpace;
//}
//
//vector<pair<int, int>> RotateKey(vector<pair<int, int>>& key)
//{ 
//    vector<pair<int, int>> out;
//    for (int i = 0;i < key.size();i++)
//    {
//        out.push_back({ (key[i].second), -(key[i].first)} );
//    }
//    return out;
//}
//
//vector<pair<int, int>> Movekey(vector<pair<int, int>>& key, pair<int,int> dir, int dis)
//{
//    vector<pair<int, int>> out;
//    
//    int dirY = dir.first * dis;
//    int dirX = dir.second * dis;
//
//    if (dirY == 0 && dirX == 0)
//    {
//        out = key;
//        return out;
//    }
//
//    for (int i = 0;i < key.size();i++)
//    {
//        out.push_back({key[i].first + dirY , key[i].second + dirX });
//    }
//    return out;
//}
//
//
//
//bool CheckLock(vector<vector<int>> lock, vector<pair<int, int>> key)
//{
//    for (auto k : key)
//    {
//        int Y = k.first + 1;
//        int X = k.second + 1;
//
//        if (Y >= 0 && Y < lock.size() && X >= 0 && X < lock.size())
//        {
//            lock[Y][X] += 1;
//        }
//    }
//
//    for (auto lockY : lock)
//    {
//        for (auto lockX : lockY)
//        {
//            if (lockX != 1)
//            {
//                return false;
//            }
//        }
//    }
//    return true;
//}
//
//
//
//bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
//    bool answer = true;
//
//    vector<pair<int, int>> newkey = ToBoardSpace(key);
//    vector<pair<int, int>> newlock = ToBoardSpace(lock);
//
//    vector<pair<int, int>> dir = { {0,0}, {0,1},{0,-1},{1,0},{-1,0},{1,1},{-1,-1},{-1,1},{1,-1} };
//    
//    for (int i = 0; i < 4;i++)
//    {
//        if (i != 0)
//        {
//            newkey = RotateKey(newkey);
//        }
//        for (int j = 0;j < 9;j++)
//        {
//            for (int k = 0;k < lock.size();k++)
//            {
//                vector<pair<int, int>> FinalKey = Movekey(newkey, dir[j], k);
//                if (CheckLock(lock, FinalKey))
//                {
//                    return true;
//                }
//            }
//        }
//    }
//    return false;
//}
//
//
//int main()
//{
//    vector<vector<int>> key = { {0, 0, 0}, {1, 0, 0}, {0, 1, 1} }
//        , lock = { {1, 1, 1},{1, 1, 0},{1, 0, 1}};
//
//
//    solution(key, lock);
//}