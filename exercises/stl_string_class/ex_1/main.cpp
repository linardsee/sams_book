/*
 *
 * Author: Linards Smeiksts
 * Last modified: 31.01.2021.
 *
 * Program verifies if entered word is 
 * a palindrome - word that is the same from
 * both side, for example ATOYOTA.
 *
 */



#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

int main()
{
	while(1)
	{

		cout << "\nPlease enter palindrome (or 'q' to exit) to verify: ";
		string str1, strConv;
		getline(cin, str1);
		
		if(str1 == "q")
			break;

		strConv = str1;

	
		reverse(strConv.begin(), strConv.end());
		cout << "\nThe converted string is: ";
		cout << strConv;
		cout << endl;

		if(str1 == strConv)
			cout << "The entered string was palindrome!\n";
		else
			cout << "The entered string was not palindrome!\n";
	
	}
	return 0;
}
