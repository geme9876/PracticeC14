#pragma once
/*

����ִ� ������ S�� �־����� ��, �Ʒ� ������ �����ϴ� ���α׷��� �ۼ��Ͻÿ�.

add x: S�� x�� �߰��Ѵ�. (1 �� x �� 20) S�� x�� �̹� �ִ� ��쿡�� ������ �����Ѵ�.
remove x: S���� x�� �����Ѵ�. (1 �� x �� 20) S�� x�� ���� ��쿡�� ������ �����Ѵ�.
check x: S�� x�� ������ 1��, ������ 0�� ����Ѵ�. (1 �� x �� 20)
toggle x: S�� x�� ������ x�� �����ϰ�, ������ x�� �߰��Ѵ�. (1 �� x �� 20)
all: S�� {1, 2, ..., 20} ���� �ٲ۴�.
empty: S�� ���������� �ٲ۴�.
�Է�
ù° �ٿ� �����ؾ� �ϴ� ������ �� M (1 �� M �� 3,000,000)�� �־�����.

��° �ٺ��� M���� �ٿ� �����ؾ� �ϴ� ������ �� �ٿ� �ϳ��� �־�����.

���
check ������ �־���������, ����� ����Ѵ�.
*/
#include <vector>

#define MAXBIT 20
class JUnion
{
public:
	unsigned int data : MAXBIT;

	void add(int x) { data |= (1<<x); }
	void remove(int x) { data &= ~(1 << x); };
	bool check(int x) { return data & (1 << x); };
	void toggle(int x) { data ^= (1 << x); };
	void all() { data = (1 << MAXBIT); };
	void empty() { data = 0; };
	JUnion():data(0) {};
	~JUnion() {};
};