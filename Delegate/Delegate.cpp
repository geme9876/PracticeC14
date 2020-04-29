#include "Delegate.h"
#include <iostream>
#include "Monster.h"
using namespace std;
int func0(int a, int b)
{
	cout << a << "+" << b;
	return a + b;
}

int main()
{
	Delegate<int(int, int)> d1;

	d1.bind_unique(func0);
	d1.bind_unique(func0);

	d1.excute(10,10);

	Test::Monster m;
	m.Hit();

	return 0;
}