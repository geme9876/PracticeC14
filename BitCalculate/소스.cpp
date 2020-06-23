#include <iostream>

using namespace std;




bool IsBitOn(const int& n, int x)
{
	return n & (1 << x) > 0 ? true : false;
}
void ToggleBit(int& n, int x)
{
	n ^= (1 << x);
}

int MinBit(int& n)
{
	return (n & -n);
}




void RangeSetAll(int& n, int x)
{
	n |= (1 << x) -1;
}

void SetBitOff(int& n,int x)
{
	n &= ~(1 << x);
}
void SetBitOn(int& n, int x)
{
	n |= (1 << x);
}






int main()
{
	int a = 0;



	return 0;
}