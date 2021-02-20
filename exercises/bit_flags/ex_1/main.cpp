/*
 *
 * Author: Linards Smeiksts
 * Last modified: 20.02.2021.
 *
 * Write a bitset class that contains four bits. Initialize it to a number,
 * display the result, and add it to another bitset object. (The chatch:
 * Bitsets don't allow bitsetA = bitsetX + bitsetY.)
 *
 */



#include<iostream>
#include<bitset>

using namespace std;

int main()
{
	bitset <4> theBitsetObj (string("1010"));
	bitset <4> theBitsetObj2 (string("0001"));

	cout << "theBitsetObj = " << theBitsetObj << endl;
	cout << "theBitsetObj2 = " << theBitsetObj2 << endl;

	bitset <4> theAddResult(theBitsetObj.to_ulong() + theBitsetObj2.to_ulong());

	cout << "theAddResult = " << theAddResult << endl;

/*
	bitset <8> theBitsetObj2 (string("11110000"));
	
	cout << "The 5th is: " << theBitsetObj2[4] << endl;

	cout << "The initialized bitset object is: " << theBitsetObj << endl;

	for(size_t i = 0; i < theBitsetObj.size(); i++)
	{
		theBitsetObj2.set(i, theBitsetObj[i]);
	}

	cout << "The bitset object after addition is: " << theBitsetObj2 << endl;
*/

	
	return 0;
}
