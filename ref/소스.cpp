#include <iostream>
#include <string>
#include <tuple>
using namespace std;


int main()
{
	int a = 10;
	string b("abc");
	double c = 10.f;
	

	auto t1 = make_tuple(ref(a), ref(b), cref(c));

	get<0>(t1) *= 10;

	get<1>(t1).assign("def");
	//get<2>(t1) += 10.f;  에러  cref이기 때문
	
	return 0;
}