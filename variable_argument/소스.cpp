#include <iostream>
using namespace std;
void printInts(int num, ...)
{
	int temp;
	va_list ap;
	__crt_va_start(ap, num);
	for (int i = 0; i < num; i++)
	{
		temp = __crt_va_arg(ap, int);
		cout << temp << "";
	}
	__crt_va_end(ap);
}

void main()
{
	printInts(5, 5, 4, 3, 2, 1);

	return;
}