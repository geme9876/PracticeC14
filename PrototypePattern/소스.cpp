#include "Monster.h"
#include "Spawner.h"

void main()
{
	Monster* ghost = new MonsterGhost(10,20);

	Spawner* ghost_spawner = new Spawner(ghost);

	ghost_spawner->spawnMonster();


	delete ghost;

	delete ghost_spawner;

	return;
}