/*
 * Autohor: Linards Smeiksts
 * Last modified: 22.01.2021.
 *
 * Program implements stray pointer (which is bad)
 * for educational purposes.
 *
 */

#include<iostream>

using namespace std;

int main()
{
	int * pStray = new int;
       	*pStray = 100;

	cout << "*pStray = " << *pStray;
	cout << "\nAddres of *pStray in heap: "<< pStray;

	delete pStray;			// This frees the heap address
	// But pStray is still assigned the address
	
	cout << "\nAddress of pStray: " << pStray;

	long * anotherVar = new long;

	cout << "\nAddress of anotherVar: " << anotherVar;

	// We will not assign pStray to some value, because it is 
	// stray pointer and it is dangerous!
	
	pStray = 0;

	// Now everything is fine!

	return 0;
}
