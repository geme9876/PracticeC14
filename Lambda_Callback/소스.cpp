#include <iostream>
#include <functional>
#include <vector>


void testcallback(const std::vector<int>& vec, const std::function<bool(int)>& callback)
{
	for (const auto& i : vec)
	{
		if (!callback(i))
		{
			break;
		}
		std::cout << i << "";
	}
	std::cout << std::endl;
}

int main()
{
	std::vector<int> vec{ 1,2,3,4,5,6,7,8,9,10 };
	testcallback(vec, [](int i) {return i < 6; });
	return 0;
}