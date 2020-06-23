#include <iostream>
#include <vector>
#include <list>
#include <queue>
using namespace std;



int soulution(const int& distance, int CurrentGas, queue<pair<int, int>>& GasStation)
{

	int answer = 0;
	auto comp = [](pair<int, int>& lhs, pair<int, int>& rhs)->bool {return lhs.second < rhs.second; };
	priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(comp)> ReachableGasStation{comp};

	for (int i = CurrentGas; i <= distance;i += CurrentGas)
	{
		CurrentGas -= CurrentGas;

		if (!GasStation.empty() && GasStation.front().first <= i)
		{
			ReachableGasStation.push(GasStation.front());
			GasStation.pop();
		}
		if (!ReachableGasStation.empty())
		{
			CurrentGas += ReachableGasStation.top().second;
			answer++;
			ReachableGasStation.pop();
		}
		else
		{
			return -1;
		}

	}
	return answer;
}
int main()
{
	vector<pair<int, int>> to{ {1,3},{5,5},{8,1} };
	queue<pair<int, int>> GasStation;
	for (auto t : to)
	{
		GasStation.push(t);
	}

	soulution(10,5, GasStation);
	return 0;
}