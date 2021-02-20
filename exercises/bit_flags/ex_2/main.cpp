/*
 *
 * Author: Linards Smeiksts
 * Last modified: 20.02.2021.
 *
 *
 * Demonstrate how you would toggle (that is, switch) the bits in a bitset.
 *
 */



#include<iostream>
#include<bitset>

using namespace std;

int main()
{
	bitset <4> theBitsetObj (string("1010"));
	bitset <4> theBitsetObj2 (string("0001"));

	cout << "theBitsetObj standard version = " << theBitsetObj << endl;
	cout << "theBitsetObj2 stanadrd version = " << theBitsetObj2 << endl;


	cout << "theBitsetObj toggled version = " << theBitsetObj.flip() << endl;
	cout << "theBitsetObj2 toggled version = " << theBitsetObj2.flip() << endl;
	
	return 0;
}
