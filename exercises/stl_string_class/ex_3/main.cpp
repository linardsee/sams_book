/*
 *
 * Author: Linards Smeiksts
 * Last modified: 31.01.2021.
 *
 * Program converts every alternate character to uppercase
 *
 */



#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

int main()
{

	string str1;
	int i = 0;

	while(1)
	{

		cout << "\nPlease enter some string (or 'q' to exit): ";
		getline(cin, str1);
		
		if(str1 == "q")
			break;	
		
		i = 0;
		do
		{
			str1[i] = toupper(str1[i]);
			i += 2;
		}while(i < str1.length());		

		cout << "\nThe converted string is: ";
		cout << str1;
		cout << endl;
	}
	return 0;
}
