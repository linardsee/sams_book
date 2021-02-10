/*
 *
 * Author: Linards Smeiksts
 * Last modified: 22.01.2021.
 *
 * Program for solving exercise 8
 * bug.
 *
 */

#include<iostream>

using namespace std;

class CAT
{
	public:
		CAT(int age) {itsAge = age;}
		~CAT(){}
		int GetAge() const {return itsAge;}
	private:
		int itsAge;
};

CAT & MakeCat(int age);

int main()
{
	int age = 7;
	CAT Boots = MakeCat(age);
	cout << "Boots is " << Boots.GetAge()
		<< " years old" << endl;

	return 0;
}

CAT & MakeCat(int age)
{
	CAT * pCat = new CAT(age);
	return *pCat;
}
