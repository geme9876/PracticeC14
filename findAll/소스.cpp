#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

template<typename InputIterator, typename OutputIterator, typename Predicate>
OutputIterator find_all(InputIterator first, InputIterator last, OutputIterator dest, Predicate pred)
{
	while (first != last)
	{
		if (pred(*first))
		{
			*dest = first;
			++dest;
		}
		++first;
	}
	return dest;
}

int main()
{
	vector<int> vec{ 0,1,2,3,4,5 };
	vector<vector<int>::iterator> matches;
	find_all(begin(vec), end(vec), back_inserter(matches),
		[](int i) {return i <3;}
	); // back_intserter  back_insert_iterator의 편의 함수 , push_back 메서드를 호출한다


	cout << "find " << matches.size() << "matching elements : " << endl;

	for (auto it : matches)
	{
		cout << *it << "at position" << (it - cbegin(vec)) << endl;
	}

	for_each(matches.begin(), matches.end(), [&](vector<int>::iterator it) { cout << *it << "at position" << (it - cbegin(vec)) << endl; });

	return 0;
}