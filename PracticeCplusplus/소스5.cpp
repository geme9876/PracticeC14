//#include <iostream>
//#include <vector>
//#include <random>
//using namespace std;
//
//
//
//
//
//int cal(int day, vector<int>& cost, int propit,int iNumCoin)
//{
//
//	if (day == cost.size()) return propit;
//
//
//
//	//������ ������ ���, ������ �Ǵ�, �ƹ��͵� ���Ѵ�
//
//	int case1 = cal(day + 1, cost, propit - cost[day], iNumCoin + 1);
//	int case2 = cal(day + 1, cost, propit + ((cost[day]) * iNumCoin)-1, 0);
//	int case3 = cal(day + 1, cost, propit,iNumCoin);
//
//	propit = __max(propit,__max(__max(case1, case2),case3));
//	
//	return propit;
//
//	//���� ������ ���� ���� best�� ��´�
//
//}
//
//
//
//int main()
//{
//	int day= 100;
//
//	vector<int> cost;
//	for (int i = 0;i < 100;i++)
//	{
//		cost.push_back(i);
//	}
//	int answer = cal(0, cost, 0,0);
//
//	return 0;
//}