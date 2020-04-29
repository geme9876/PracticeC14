#include <map>
#include <iostream>
#include <string>
#include <thread>
#include <mutex>
#include <vector>
using namespace std;


void cal(vector<int>& lhs, vector<int>& rhs, int& Dest, int start,int end,mutex& m)
{
	int local_sum[3]{0,};
	int k=0;
	for (int i = start; i < end; i++)
	{
		local_sum[k] = lhs[i] + rhs[i];
		k++;
	}
	
	m.lock();
	Dest += local_sum[0] + local_sum[1] + local_sum[2];
	m.unlock();
}

int main()
{
	vector<int> a{ 1,2,3,4,5,6,7,8,9 };
	vector<int> b{ 1,2,3,4,5,6,7,8,9 };
	vector<thread> t;
	int dest=0;
	mutex m;
	for (int i = 0; i < 9; i+=3)
	{
		
		t.push_back(thread(cal, ref(a), ref(b), ref(dest), i, i + 3, ref(m)));
	}

	for (auto& thr : t)
	{
		thr.join();
	}
	

	return 0;
}