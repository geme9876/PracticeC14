#include <vector>
#include <iostream>
#include <exception>
#include <fstream>
using namespace std;

void readIntegerFile(const string& fileName, vector<int>& dest)
{
	ifstream istr;
	int temp;
	istr.open(fileName.c_str());
	if (istr.fail())
	{
		//throw exception();
		throw "File not exist";
		//�پ��� ������ Ÿ������ �ͼ����� �̿��� �� �ִ�
	}

	while (istr >> temp)
	{
		dest.push_back(temp);
	}
}

int main()
{
	vector<int> myInts;
	const string fileName = "IntegerFile.txt";
	try {
		readIntegerFile(fileName, myInts);
	}
	catch (const exception& e)
	{
		cerr << "Unable to open file" << fileName.c_str() << endl;
		return 1;
	}
	catch (const char* e)
	{
		cerr << e << endl;
		return 1;
	}
	for (const auto element : myInts)
	{
		cout << element << "";
	}
	cout << endl;
	return 0;
}