#include "hash.h"
#include <iostream>
#include <tuple>
#include <string>
#include <map>

using namespace JHash;
int main()
{



	hash_map < std::string , int > myHash2;
	myHash2.insert(std::make_pair("abc", 10));
	myHash2.insert(std::make_pair("bcd", 20));
	myHash2.insert(std::make_pair("cfg", 30));
	myHash2.insert(std::make_pair("dog", 400));


	for (auto it = myHash2.cbegin(); it != myHash2.cend(); ++it)
	{
		std::cout << it->first << "maps to" << (*it).second << std::endl;
	}

	std::map<std::string, int> myMap(myHash2.cbegin(), myHash2.cend());
	for (auto& p : myMap)
	{
		std::cout << p.first << "maps to " << p.second << std::endl;
	}


	return 0;
}