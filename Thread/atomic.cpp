#include <thread>
#include <iostream>
#include <exception>
#include <stdexcept>
#include <atomic>
#include <chrono>
#include <vector>

using namespace std;




void func(atomic<int>& counter)
{
	for (int i = 0; i < 100; i++)
	{
		int fetched = counter.fetch_add(5);
		//++counter;
		std::this_thread::sleep_for(std::chrono::milliseconds(1));
	}
}
int main()
{
	std::atomic<int> counter(0);
	std::vector<std::thread> threads;
	for (int i = 0; i < 10; i++)
	{
		threads.push_back(std::thread{ func,std::ref(counter)});
	}
	for (auto& t : threads)
	{
		t.join();
	}
	std::cout << "Result =" << counter << std::endl;
}