#pragma once
#include "Delegate.h"
#include <iostream>

class StatComponent
{
public:
	int hp = 0;
	void SetHp(int i) { std::cout << "SetHP" << std::endl; hp = i;  if (hp == 0)Ondead.excute(); Caller.excute(hp, hp + 1); }
	Delegate<void()> Ondead;
	Delegate<int(int, int)> Caller;

	StatComponent() {};
	~StatComponent() {};
};