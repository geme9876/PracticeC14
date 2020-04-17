#include <random>
#include <iostream>
#include <functional>
#include <vector>
using namespace std;


int main()
{
	random_device rDev;
	mt19937 eng(rDev()); // ���� seed �� ����̽��� ���
	uniform_int_distribution<int>dist(1, 99); // ������ �޸��� Ʈ������ ������ ��������
	//�˰��򸶴� ������ �������� �ٸ���
	//������ ������ �ƴ� ���Ժ����� ��� ������ ��κ��� �߾����� ġ�����ִ�

	auto gen = std::bind(dist, eng);

	
	vector<int> vec(10);
	generate(vec.begin(), vec.end(), gen);

	return 0;
}