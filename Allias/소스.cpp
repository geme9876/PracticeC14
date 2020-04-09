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
	//cout << c << endl; // 오류발생 // 참조는 메모리의 생성과 해제등의 관리를 담당할 수 없다
	delete cp;

	int d=1;
	int e = 2;
	mc.incr(d);
	mc.incr(d + e);
	//우측값 참조는 임시객체를 담당한다
	mc.incr(std::move(d));
	return;
}