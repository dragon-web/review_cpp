#define _CRT_SECURE_NO_WARNINGS 

#include<iostream>
#include<string>

using namespace std;

class Animal
{
public:
	Animal(string name1)
	{
		name = new char[name1.size() + 1];
		strcpy(name, name1.c_str());
	}
	virtual ~Animal()
	{
		delete name;
	}
	virtual void speak() = 0;
	virtual void swim() = 0;
	void action()
	{
		speak();
		swim();
	}


	char* name;
};


class Bird : public Animal
{
public:
	using Animal::Animal;
	~Bird() {
		std::cout << "bird " << name << " has gone." << std::endl;
	}
	void speak() {
		std::cout << "bird " << name << " is singing." << std::endl;
	}
	void swim() {
		std::cout << "bird " << name << " can't swim." << std::endl;
	}
};
class Fish : public Animal
{
public:
	using Animal::Animal;
	~Fish() {
		std::cout << "fish " << name << " has gone." << std::endl;
	}
	void speak() {
		std::cout << "fish " << name << " can't speak." << std::endl;
	}
	void swim() {
		std::cout << "fish " << name << " is swimming." << std::endl;
	}
};
int main()
{
	string name1, name2;
	cin >> name1 >> name2;

	Animal *myBird = new Bird(name1), *myFish = new Fish(name2);
	myBird->action();
	myFish->action();
	delete myBird;
	delete myFish;
	system("pause");
	return 0;
}
/*
alice bob

bird alice is singing.
bird alice can't swim.
fish bob can't speak.
fish bob is swimming.
bird alice has gone.
fish bob has gone.

*/