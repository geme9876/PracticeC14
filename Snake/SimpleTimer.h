#pragma once
#include <chrono>

using namespace std::chrono;

class SimpleTimer
{
public:
	SimpleTimer() { last = steady_clock::now(); };
	~SimpleTimer() = default;

	std::chrono::steady_clock::time_point last;
	float Mark() {
		const auto old = last;
		last = steady_clock::now();
		const duration<float> frameTime = last - old;
		return frameTime.count();
	};
	float Peek() { duration<float>(steady_clock::now() - last).count(); } ;
};

