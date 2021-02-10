/*
 *
 * Author: Linards Smeiksts
 * Last modified: 02.02.2021.
 *
 * Requirements:
 *
 * Write a short program that accepts numbers from
 * the user and inserts them at the top of the list.
 *
 */



#include<iostream>
#include<list>
#include<string>

using namespace std;

int main()
{
	int randNum;
	string menu;
	list <int> theIntList;

	while(1)
	{
		cout << "\nChoose the option: \n";
		cout << "Add numbers to list (press 'a')\n";
		cout << "Print the list (press 'p')\n";
		cout << "Quit (press 'q')\n";
		cin >> menu;
		
		if(menu == "a")
		{
			cout << "Please enter an integer number to add to list: ";
			cin >> randNum;
			cout << endl;
			
			theIntList.push_front(randNum);
		}

		if(menu == "p")
		{
			cout << "The elements:";
			for(list <int>::iterator it = theIntList.begin(); it!=theIntList.end(); ++it)
			{
				cout << " " << *it;
			}
			cout << endl;
		}

		if(menu == "q")
			break;
	}

	return 0;
}
