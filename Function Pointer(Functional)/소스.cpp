#include "Monster.h"
#include "Spawner.h"
Monster* spawnGhost()
{
	return new MonsterGhost();
}
void main()
{
	Monster* ghost = new MonsterGhost();

	Spawner* ghost_spawner = new Spawner(&Monster::clone);

	ghost_spawner->spawnMonster(ghost);

	delete ghost;

	delete ghost_spawner;

	return;
}