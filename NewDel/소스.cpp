#include <iostream>
#include <limits>
using namespace std;

int main()
{
	int* a = new int(5);

	size_t size = _msize(a);
	cout << "size" << size <<endl << a << endl;



	cout << "max int value:" << numeric_limits<int>::max() << endl;
	cout << "max uint value:" << numeric_limits<unsigned int>::max() << endl;
	cout << "max int64 value:" << numeric_limits<__int64>::max() << endl;





	return 0;
}