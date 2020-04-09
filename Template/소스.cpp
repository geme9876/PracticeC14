#include "JTemplate.h"

void main()
{
	JTemplate<int> temp(3,4);
	int ret = temp.foo(1, 2);

	return;
}