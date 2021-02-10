// Listing 11.8 Using virtual methods

#include <iostream>
using std::cout;

class Mammal
{
	public:
		Mammal():itsAge(1) {cout << "Mammal constructor...\n";}
		virtual ~Mammal() {cout << "Mammal destructor...\n";}
		void Move() const {cout << "Mammal move one step\n";}
		virtual void Speak() const {cout << "Mammal speak\n";
}
		
	protected:
		int itsAge;
};

class Dog : public Mammal
{
	public:
		Dog() {cout << "Dog constructor...\n";}
		virtual ~Dog() {cout << "Dog destructor...\n";}
		void WagTail() {cout << "Wagging tail...\n";}
		void Speak() const {cout << "Woof!\n";}
		void Move() const {cout << "Dog moves  steps...\n";}
};

int main()
{
	Mammal *pDog = new Dog;
	pDog->Move();
	pDog->Speak();
	//pDog->WagTail();	this wont work, because its Dog method

	return 0;
}
