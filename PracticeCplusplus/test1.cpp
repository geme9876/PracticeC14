//#include <iostream>
//#include <string>
//#include <random>
//using namespace std;
//
//
//string IPvBinaryGen()
//{
//	string s;
//	random_device rd;
//	uniform_int_distribution<int> dis(0, 1);
//	mt19937 mt(rd());
//	for (int i = 0;i < 128;i++)
//	{
//		s += to_string(dis(mt));
//	}
//	return s;
//}
//
//void soulution(string s)
//{
//	for (int i = 0; i < s.size(); i += 16)
//	{
//		cout.fill('0');
//		cout.width(4);
//		cout <<  hex << stoi(s.substr(i, 16),nullptr,2);
//		if (i + 16 >= s.size())
//		{
//			cout << endl;
//		}
//		else
//		{
//			cout << ":";
//		}
//	}
//
//}
//int main()
//{
//	
//	string s = IPvBinaryGen();
//
//	cout << s<<endl;
//	soulution(s);
//
//	
//	return 0;
//}