#include "Process.h"





Schedular::Schedular(const std::vector<Process>& processes)
{
	for (auto& process : processes)
	{
		//프로세스 추가
		rr.add(process);
	}
}

void Schedular::scheduleTimeSlice()
{
	try
	{
		rr.getNext().doWorkDuringTimeSlice();
	}
	catch (const std::out_of_range&)
	{
		std::cerr << "No more processes to schedule" << std::endl;
	}
}


void Schedular::removeProcess(const Process & process)
{
	rr.remove(process);

}


int main()
{
	std::vector<Process> processes = { Process("1"),Process("2"),Process("3") };
	Schedular schedule(processes);
	for (int i = 0; i < 5; ++i)
	{
		schedule.scheduleTimeSlice();
	}
	schedule.AddProcess(Process("4"));
	schedule.removeProcess(processes[1]);
	schedule.AddProcess(Process("2"));
	std::cout << "remove second process" << std::endl;

	for (int i = 0; i < 4; i++)
	{
		schedule.scheduleTimeSlice();
	}

}
