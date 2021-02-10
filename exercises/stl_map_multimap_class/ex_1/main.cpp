/*
 *
 * Author: Linards Smeiksts
 * Last modified: 06.02.2021.
 *
 * You need to write an application that works as a telephone
 * directory where the name of the people need not be unique.
 * What container would you choose? Write a definition of the 
 * container.
 *
 */



#include<iostream>
#include<map>
#include<string>

using namespace std;

int main()
{
	string nameStr, telStr;
	multimap <string, string> telBook;
	multimap <string, string>::iterator it;
	cout << "*** Simple telephone book app ***\n";
	
	cout << "Enter the telephone book entries (q to exit):\n";
	while(1)
	{
		cout << "Name: ";
		cin >> nameStr;
		cout << "\n"; 
		if( nameStr == "q")
			break;
		cout << "Number: ";
		cin >> telStr;
		cout << "\n";

		telBook.insert(pair<string, string>(nameStr, telStr));
	}
	
	cout << "Printing the contents of telephone book: \n";
	for(it = telBook.begin(); it != telBook.end(); ++it)
	{
		cout << "Name: " << (*it).first << " Tel: " << (*it).second << endl; 
	}

	return 0;
}
