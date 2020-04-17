#include <iostream>
#include <chrono>

using namespace std;


int main()
{

	auto start = chrono::system_clock::now();
	double d = 0;
	for (int i = 0; i < 100000; ++i)
	{
		d += sqrt(sin(i) * cos(i));
	}

	auto end = chrono::system_clock::now();
	auto diff = end - start;
	cout << chrono::duration<double, milli>(diff).count() << "ms" << endl;


	return 0;
}