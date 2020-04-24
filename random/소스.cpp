#include <random>
#include <iostream>
#include <functional>
#include <vector>
using namespace std;


int main()
{
	random_device rDev;
	mt19937 eng(rDev()); // ���� seed �� ����̽��� ���
	uniform_int_distribution<int>dist(0, 1); // ������ �޸��� Ʈ������ ������ ��������
	//�˰��򸶴� ������ �������� �ٸ���
	//������ ������ �ƴ� ���Ժ����� ��� ������ ��κ��� �߾����� ġ�����ִ�

	auto gen = std::bind(dist, eng);


	vector<int> vec(1000);
	double hp = 1000;

	for (int i = 0; i < 10000; i++)
	{
		if (gen())
		{
			cout << "����";
			hp += (hp *0.05f);
		}
		else
		{

			cout << "����";
			hp -= (hp*0.05f);
		}
		cout << hp  << " || ";
	}

	return 0;
}