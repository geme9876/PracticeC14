#pragma once
#include "Monster.h"
#include <iostream>
#include <functional>

class Spawner
{
public:
	Spawner(Monster* spawn) : spawn_(spawn) {}
	~Spawner();

	virtual Monster* spawnMonster() {

		return spawn_->clone();
	}
protected:
	Monster*  spawn_;
};

 // �޼��� = this_call
 // ecx -> ��ü�� ptr