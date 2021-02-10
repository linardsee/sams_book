/*
 *
 * Author: Linards Smeiksts
 * Last modified: 06.02.2021.
 *
 * Demonstrate via a simple program that a set cannot 
 * accept duplicate entries, whereas a multiset can.
 *
 */



#include<iostream>
#include<set>

using namespace std;

int main()
{
	int theInt;
	set <int> intSet;
	multiset <int> intMset;
	typedef set <int>::iterator setIt;
	typedef multiset <int>::iterator msetIt;


	cout << "Please enter an integer: \n" << ">";
	cin >> theInt;
	intSet.insert(theInt);
	intSet.insert(theInt);
	intMset.insert(theInt);
	intMset.insert(theInt);

	// Set will print only one value instead of two
	cout << "Set values: ";
	for(setIt sIt = intSet.begin(); sIt != intSet.end(); ++sIt)
	{
		cout << " " << *sIt;
	}
	cout << endl;

	cout << "Multiset values: ";
	for(msetIt msIt = intMset.begin(); msIt != intMset.end(); ++msIt)
	{
		cout << " " << *msIt;
	}
	cout << endl;

	return 0;
}
