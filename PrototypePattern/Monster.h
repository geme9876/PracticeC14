#pragma once
#include <iostream>

class Monster
{
public:
	Monster();
	virtual ~Monster();
	virtual Monster* clone() = 0;
public:

};

class MonsterGhost : public Monster
{
public:
	MonsterGhost(int health, int speed) :health_(health), speed_(speed) { std::cout << "Ghost Init" << std::endl; }
	//MonsterGhost() { std::cout << "Ghost Init" << std::endl; }
	virtual Monster* clone()
	{
		std::cout << "Clone Ghost" << std::endl;
		return new MonsterGhost(*this);
	}
private:
	MonsterGhost(const MonsterGhost& src)
	{
		health_ = src.health_;
		speed_ = src.speed_;
	};
	int health_;
	int speed_;

};


class MonsterDemon : public Monster {
public:
	MonsterDemon(int health, int speed) :health_(health), speed_(speed) { std::cout << "Demon Init" << std::endl; }
	virtual Monster* clone()
	{
		std::cout << "Clone MonsterDemon" << std::endl;
		return new MonsterDemon(health_, speed_);
	}
private:
	int health_;
	int speed_;


};
class MonsterWarrior : public Monster {

public:
	MonsterWarrior(int health, int speed) :health_(health), speed_(speed) { std::cout << "Warrior Init" << std::endl; }
	virtual Monster* clone()
	{
		std::cout << "Clone MonsterWarrior" << std::endl;
		return new MonsterWarrior(health_, speed_);
	}
private:
	int health_;
	int speed_;
};
