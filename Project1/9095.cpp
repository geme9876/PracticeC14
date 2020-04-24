//#include <array>
//#include <random>
//using namespace std;
//
//
//
//int NumGen()
//{
//	random_device rd;
//	mt19937 mt(rd());
//	uniform_int_distribution<int> dist(1, pow(10, 6));
//	return dist(mt);
//}
//
//int main()
//{
//	int num = 7;
//		
//	NumGen();
//	vector<int> ar;
//	ar.resize(num+1);
//	
//	for (int i = 2; i <= num; i++)
//	{
//		ar[i] = ar[i - 1] + 1;
//		if (i % 2 == 0)
//		{
//			ar[i] = min(ar[i],ar[i / 2]+1);
//		}
//		else if (i % 3 == 0)
//		{
//			ar[i] = min(ar[i], ar[i / 3] + 1);
//		}
//
//	}
//
//
//	return 0;
//}