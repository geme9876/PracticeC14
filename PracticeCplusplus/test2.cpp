//#include <iostream>
//#include <vector>
//#include <sstream>
//#include <algorithm>
//using namespace std;
//
//#define MAX_LINE 2
//
//int solution(int day,vector<int> hospital, int timeout)
//{
//	int answer = -1;
//	int rewind = 0;
//	for (int i = 0;i < day; i += timeout)
//	{
//		if (answer == -1) answer++;
//		while (find(hospital.begin(), hospital.end(), i - rewind) != hospital.end())
//		{
//			++rewind;
//		}
//		i -= rewind;
//		if (i <0 || rewind > timeout)
//		{
//			return -1;
//		}
//		rewind = 0;
//		answer++;
//	}
//	return answer;
//
//}
//
//
//int main()
//{
//	vector<vector<int>> line;
//	line.resize(MAX_LINE);
//	int timeout;
//
//
//	for (int i = 0;i < MAX_LINE;i++)
//	{
//		string s;
//		getline(cin, s);
//		stringstream ss(s);
//		int arg;
//		for (ss;ss >> arg;)
//		{
//			line[i].push_back(arg);
//		}
//	}
//	sort(line[1].begin(), line[1].end(),less<int>());
//	int answer = solution(line[0][0], line[1], line[0][2]);
//	
//	cout << answer << endl;;
//	return 0;
//}