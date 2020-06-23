//#include <iostream>
//#include <string>
//#include <vector>
//#include <sstream>
//using namespace std;
//
//vector<vector<string>> TurnFunc(vector<vector<string>>& matrix, int rotateCnt, int lineCnt)
//{
//	vector<vector<string>> temp = matrix;
//	vector<vector<string>> out = matrix;
//	int LindEnd = lineCnt-1;
//	for (int d = 0; d < lineCnt / 2;d++)
//	{
//		for (int j = 0;j < abs(rotateCnt)%((LindEnd-d)*4);j++)
//		{
//			for (int CurrLine = d; CurrLine < LindEnd; CurrLine++ )
//			{
//				if (rotateCnt > 0)
//				{
//					out[d][CurrLine + 1] = temp[d][CurrLine];
//					
//					out[CurrLine + 1][LindEnd] =
//						temp[CurrLine][LindEnd];
//					
//					out[LindEnd][(LindEnd+d) - CurrLine - 1] =
//						temp[LindEnd][(LindEnd+d) - CurrLine];
//					
//					out[(LindEnd+d) - CurrLine - 1][d] =
//						temp[(LindEnd+d) - CurrLine][d];
//				}
//				else
//				{
//					out[CurrLine +1][d] = temp[CurrLine][d];
//					
//					out[LindEnd][CurrLine +1] = temp[LindEnd][CurrLine];
//					
//					out[(LindEnd + d) - CurrLine -1][LindEnd] = temp[(LindEnd+d)-CurrLine][LindEnd];
//					
//					out[d][(LindEnd + d) - CurrLine - 1] =temp[d][(LindEnd + d) - CurrLine];
//
//				}
//			}
//
//			temp = out;
//		
//
//
//		}
//		LindEnd--;
//		rotateCnt *= -1;
//
//
//	}
//
//	return out;
//}
//
//
//int main() {
//	string str;
//	getline(cin, str);
//	stringstream ss(str);
//	vector<int> setting;
//	while(!ss.eof())
//	{
//		int n;
//		ss >> n;
//		setting.push_back(n);
//	}
//
//	vector<vector<string>> Display;
//	Display.resize(setting[0]);
//
//	for (int i = 0; i < setting[0];i++)
//	{
//		ss.clear();
//		getline(cin, str);
//		ss.str(str);
//		string name;
//		for (int j = 0;j < setting[0];j++)
//		{
//			getline(ss, name, ' ');
//			Display[i].push_back(name);
//		}
//	}
//	
//
//
//	Display = TurnFunc(Display, setting[1], Display.size());
//
//
//
//
//	for (int i = 0;i < Display.size();i++)
//	{
//		for (int j = 0;j < Display.size();j++)
//		{
//			cout << Display[i][j];
//			if (j == Display.size() - 1)
//				cout << endl;
//			else
//				cout << " ";
//		}
//	}
//
//	return 0;
//}