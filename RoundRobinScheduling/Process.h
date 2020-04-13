#pragma once
#include <iostream>
#include <string>
#include "RoundRobin.h"
class Process
{
public:

	Process(const std::string& name) :mName(name) {}
	~Process() {};
	void doWorkDuringTimeSlice()
	{
		std::cout << "Process" << mName << "performing work during time slice" << std::endl;
	}
	bool operator==(const Process& rhs)
	{
		return mName == rhs.mName;
	}
private:
	std::string mName;
};


class Schedular
{
public:
	Schedular(const std::vector<Process>& processes);
	void scheduleTimeSlice();
	void removeProcess(const Process& process);
	void AddProcess(const Process& process)
	{
		rr.add(process);
	}
private:
	RoundRobin<Process> rr;
};



