/*
 *
 * Author: Linards Smeiksts
 * Last modified: 21.02.2021.
 *
 * Use the auto_ptr class to instantiate a CDog that inherits from
 * CAnimal. Pass the object as a CAnimal-pointer and comment on 
 * slicing, if any.
 *
 */



#include<iostream>
#include<string>
#include<memory>

using namespace std;

class CAnimal
{
	public:
		CAnimal(): height(10), color("black"){}
		~CAnimal(){}
		int getHeight(){return height;}
		void setHeight(const int h){height = h;}
		string getColor(){return color;}
		void setColor(const string col){color = col;}
		virtual void sound(){cout << "Animal sound\n";}
	protected:
		int height;
		string color;
};

class CDog: public CAnimal
{
	public:
		CDog(int h) {height = h;}
		~CDog(){}
		void woof(){cout << "Woof\n";}
		string getTailColor(){return tailColor;}
		void setTailColor(const string col){tailColor = col;}
		virtual void sound(){cout << "woof\n";}

	private:
		string tailColor;
};
// func prototypes
void animalSounds(auto_ptr <CAnimal> anim);


int main()
{
	auto_ptr <CAnimal> animal (new CAnimal);
	auto_ptr <CAnimal> french_bulldog (new CDog(2));


	//french_bulldog.setTailColor("black");
	
	//cout << "Animal parameters: " << animal.getHeight() << " and "<< animal.getColor() << endl;
	//cout << "Dog parameters: " << french_bulldog.getHeight() << " and " << french_bulldog.getColor() << endl;

	animalSounds(animal);
	animalSounds(french_bulldog); // this does not make slicing

//	french_bulldog.sound();

	return 0;
}

void animalSounds(auto_ptr <CAnimal> anim)
{
	anim->sound();
}
