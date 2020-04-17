#include <random>
#include <iostream>
#include <functional>
#include <vector>
using namespace std;


int main()
{
	random_device rDev;
	mt19937 eng(rDev()); // 난수 seed 로 디바이스를 사용
	uniform_int_distribution<int>dist(1, 99); // 유니폼 메르센 트위스터 분포도 범위지정
	//알고리즘마다 난수의 분포도가 다르다
	//유니폼 분포가 아닌 정규분포의 경우 난수의 대부분이 중앙으로 치우쳐있다

	auto gen = std::bind(dist, eng);

	
	vector<int> vec(10);
	generate(vec.begin(), vec.end(), gen);

	return 0;
}