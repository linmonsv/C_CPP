#include <iostream>
using namespace std;

class Animal
{
public:
	virtual void eat() = 0;
	virtual void sleep() { cout << "zzzzz...." << endl; }
};

class Dog:public virtual Animal
{
public:
	virtual void brak() { cout << "Woof!" << endl; }
	virtual void eat() override { cout << "The dog has eaten." << endl; }
};

class  Bird:public virtual Animal
{
	virtual void chirp() { cout << "Chirp!" << endl; }
	virtual void eat() override { cout << "The bird has eaten." << endl; }
};

class DogBird :public Dog, public Bird
{
public:
	virtual void eat() override { Dog::eat(); }
};

int main()
{
	DogBird myConfusedAnimal;
	myConfusedAnimal.sleep();
	return 0;
}
