#pragma once
#include "StatComponent.h"
#include <iostream>
namespace Test
{
	class Monster
	{
	public:
		StatComponent stat;
		void Hit() { std::cout << "MonsterHit" << std::endl; stat.SetHp(0); }

		void Dead() { std::cout << "MonsterDead" << std::endl; }
		int Called(int a, int b) { 
			std::cout << "MonsterCalled" << a << b << std::endl;
			return a; }

		Monster() { 
			stat.Ondead.bind_unique(std::bind(&Monster::Dead, this));
			stat.Caller.bind_unique(std::bind(&Monster::Called, this,std::placeholders::_1, std::placeholders::_2));
			stat.SetHp(100); 
		
		}
		~Monster() {};
	};
}