//#include <iostream>
//#include <string>
//#include <algorithm>
//#include <vector>
//using namespace std;
//
//
//
//
//bool IsInWorld(int x, int y,int size)
//{
//	if (x >= 0 && x < size && y >=0 && y < size)
//	{
//		return true;
//	}
//	return false;
//}
//bool IsWater(int x, int y, vector<string>& world)
//{
//	if (world[x][y] == 'W')
//	{
//		return true;
//	}
//	else if(world[x][y] == 'L')
//	{
//		return false;
//	}
//}
//
//
//void AccumulLandSize(int x, int y,int& size, vector<string>& world)
//{
//	if (IsInWorld(x, y, world.size())
//		&& !IsWater(x, y, world))
//	{
//		world[x][y] = 'C';
//		size++;
//		AccumulLandSize(x + 1, y, size, world);
//		AccumulLandSize(x - 1, y, size, world);
//		AccumulLandSize(x, y + 1, size, world);
//		AccumulLandSize(x, y - 1, size, world);
//	}
//}
//
//
//void GetLandInfo(const vector<int>& LandSize, int& max, int& min, float& avg, float& middle)
//{
//	int LandOffset=0; 
//	if (LandSize.size() > 1)
//	{
//		for (int i = 1;i < LandSize.size();++i)
//		{
//			if(LandSize[0] != LandSize[i])
//			{
//				LandOffset = i;
//				break;
//			}
//		}
//
//		int IslandRange = LandSize.size() - LandOffset;
//		max = LandSize[LandOffset];
//		min = LandSize[LandSize.size() - 1];
//		for (int i = LandOffset;i < LandSize.size();++i)
//		{
//			avg += LandSize[i];
//		}
//		avg /= IslandRange;
//
//		if (IslandRange % 2 == 0)
//		{
//			middle += LandSize[IslandRange / 2];
//			middle += LandSize[IslandRange / 2 - 1];
//			middle /= 2;
//		}
//		else
//		{
//			middle = LandSize[IslandRange / 2];
//		}
//	}
//}
//
//
//
//
//void PrintLandInfo(int max, int min, float avg, float middle)
//{
//	cout.precision(3);
//	cout << max << " " << min << " " << avg << " ";
//
//	if (middle - (int)middle == 0)
//	{
//		cout << (int)middle << endl;;
//	}
//	else
//	{
//		cout << (float)middle << endl;
//	}
//
//
//}
//
//void solution(vector<string> world)
//{
//	vector<int> LandSizes;
//	//상//하//좌//우 검사해야함
//	for (int i = 0;i < world.size();i++)
//	{
//		for (int j = 0;j < world.size();j++)
//		{
//			int size = 0;
//			if (world[i][j] == 'C')
//			{
//				continue;
//			}
//			AccumulLandSize(i, j, size, world);
//			if (size)
//			{
//				LandSizes.push_back(size);
//			}
//		}
//	}
//	sort(LandSizes.begin(), LandSizes.end(), greater<int>());
//
//	int max = 0;
//	int min = 0;
//	float avg = 0.f;
//	float middle = 0.f;
//
//
//	GetLandInfo(LandSizes, max, min, avg, middle);
//	PrintLandInfo(max, min, avg, middle);
//}
//
//
//
//int main()
//{
//	int n;
//	cin >> n;
//	string s;
//	getline(cin, s);
//	vector<string> world(n);
//	for (int i = 0;i < n;++i)
//	{
//		getline(cin, world[i]);
//	}
//	solution(world);
//
//
//	return 0;
//}