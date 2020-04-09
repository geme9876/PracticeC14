#include <iostream>
class MyClass
{
public:
	void swap(int& a, int& b) { int temp = a;  a = b;  b = temp; };
	void incr(int& a) { a++; };
	void incr(int&& a) { a++; };

};
using namespace std;
void main()
{
	MyClass mc;
	int a = 10;
	int b = 20;
	mc.swap(a, b);


	int *ap = &a;
	int *bp = &b;
	mc.swap(*ap, *bp);


	int* cp = nullptr;
	int& c = *cp;

	cp = new int(5);
	//cout << c << endl; // �����߻� // ������ �޸��� ������ �������� ������ ����� �� ����
	delete cp;

	int d=1;
	int e = 2;
	mc.incr(d);
	mc.incr(d + e);
	//������ ������ �ӽð�ü�� ����Ѵ�
	mc.incr(std::move(d));
	return;
}