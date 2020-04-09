#pragma once
#include "Monster.h"
#include <iostream>
#include <functional>

using SpawnCallback = Monster * (Monster::*)(void);
class Spawner
{
public:
	Spawner(SpawnCallback spawn) : spawn_(spawn) {}
	~Spawner();

	virtual Monster* spawnMonster(Monster* a) {
		Monster* mob = nullptr;
		return (a->*spawn_)();
	}
protected:
	SpawnCallback spawn_;
};

 // 메서드 = this_call
 // ecx -> 객체의 ptr