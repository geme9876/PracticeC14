#pragma once
#include "Monster.h"
#include <iostream>
#include <functional>

using SpawnCallback = std::function<Monster*(Monster&)>;
class Spawner
{
public:
	Spawner(SpawnCallback spawn) : spawn_(spawn) {}
	~Spawner();

	virtual Monster* spawnMonster(Monster* a) {
		return spawn_(*a);
	}
protected:
	SpawnCallback spawn_;
};

 // 메서드 = this_call
 // ecx -> 객체의 ptr