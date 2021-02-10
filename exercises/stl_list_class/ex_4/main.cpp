/*
 *
 * Author: Linards Smeiksts
 * Last modified: 03.02.2021.
 *
 * Write a program that sorts and reverses a list of string. 
 *
 */



#include<iostream>
#include<list>
#include<cstdlib>
#include<ctime>

using namespace std;

void printList(list <int>& theList);
bool comp(const int& first, const int& second);


int main()
{
	list <int> theIntList;
	
	srand(time(NULL));
	
	for(int i = 0; i < 10; ++i)
	{
		theIntList.push_back(rand() % 20 + 1);
	}	
	printList(theIntList);

	// Now let's try to sort the random list
	
	theIntList.sort();
	cout << "\nThe list after sorting ascending:";
	printList(theIntList);

	// Now let's try to sort the random list descending
	
	theIntList.sort(comp);
	cout << "\nThe list after soring descending:";
	printList(theIntList);	

	// And trying the reverse method....
	
	theIntList.reverse();
	cout << "\nThe list after reversing:";
	printList(theIntList);

	return 0;
}

void printList(list <int>& theList)
{
	list <int>::iterator iit;
	
	cout << "\nThe element list: ";
	for(iit = theList.begin(); iit != theList.end(); ++iit)
	{
		cout << " " << *iit;
	}
	cout << endl;
}

bool comp(const int& first, const int& second)
{
	if(first > second) return true;
	else
		return false;
}
