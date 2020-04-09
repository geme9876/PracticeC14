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

 // �޼��� = this_call
 // ecx -> ��ü�� ptr