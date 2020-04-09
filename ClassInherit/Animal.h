#pragma once
#include <iostream>
using namespace std;
class Animal
{
public:
	Animal();
	~Animal();
public:
	virtual void eat() = 0;
	virtual void sleep() { cout << "Animal sleep" << endl; }
};


class Dog : public virtual Animal
{
public:
	virtual void bark() {};
	virtual void eat() override { cout << "dog eat" << endl; };
};

class Bird :public  virtual Animal
{
public:
	virtual void chirp() {};
	virtual void eat() override{ cout << "bird eat" << endl; };
};

class DogBird : public Dog, public Bird
{
public:
	virtual void eat() override{ Dog::eat(); }
};

void main()
{
	DogBird myCunfusedAnimal;
	myCunfusedAnimal.sleep();
	return;
}
