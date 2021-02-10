/*
 *
 * Author: Linards Smeiksts
 * Last modified: 22.01.2021.
 *
 * Program makes memory leakage in heap region
 * Just for educational purposes
 *
 */


#include<iostream>

using namespace std;

int main()
{
	int *pVarOne = new int;
	*pVarOne = 100;

	// Now assign *pVarOne to another value and lose the 
	// heap location
	// This is called memory leak
	
	int varTwo = 200;

	pVarOne = &varTwo;
	
	return 0;
}
