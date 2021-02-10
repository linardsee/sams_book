/*
 *
 * Author: Linards Smeiksts
 * Last modified: 03.02.2021.
 *
 * Write a program that inserts the contents of 
 * a vector into an STL list using the list's insert 
 * function.
 *
 */



#include<iostream>
#include<list>

using namespace std;

void printTheList(list <int>& listToPrint);

int main()
{
	list <int> theIntList;
	list <int>::iterator it;

	for(int i = 0; i <= 5; ++i)
	{
		theIntList.push_back(i);
	}

	printTheList(theIntList);


	it = ++theIntList.begin();

	// Now it point to the 1 (2nd element of the list)
	theIntList.insert(it, 10);
	printTheList(theIntList);
	
	// Let's add two more list elements, note that
	// iterator still points to the "1" although "10"
	// was inserted between
	
	theIntList.insert(it, 2, 100);
	printTheList(theIntList);


	return 0;
}

void printTheList(list <int>& listToPrint)
{
	cout << endl;
	cout << "The list elements are: ";
	
	list <int>::iterator iit;
	for(iit = listToPrint.begin(); iit !=listToPrint.end(); ++iit)
	{
		cout << " " << *iit;
	}
	cout << endl;
}
