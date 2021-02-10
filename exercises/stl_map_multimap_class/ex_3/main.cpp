/*
 *
 * Author: Linards Smeiksts
 * Last modified: 07.02.2021.
 *
 * Demonstrate via a simple program that a map cannot accept
 * duplicate entries, whereas a multimap can.
 *
 */



#include<iostream>
#include<map>
#include<string>

using namespace std;

template<typename T, typename T1>
void printMaps(T& theMaps, T1& theIt)
{
	for(theIt = theMaps.begin(); theIt != theMaps.end(); ++theIt)
	{
		cout << "Number " << (*theIt).first << " belongs to: " << (*theIt).second << endl;
	}
}

int main()
{
	string people[10] = {"Janis", "Pekka", "Valera", "Sjava", "Edijs", "Ivars", "Ediks", "Linards", "Jorls", "Arnis"};
	map <int, string> mThePeople;
	map <int, string>:: iterator mIt;
	multimap <int, string> mmThePeople;
	multimap <int, string>:: iterator mmIt;

	cout << "*** Simple program that shows difference between map and multimap ***\n";

	for(int i = 0; i < 10; i++)
	{
		mThePeople.insert(make_pair(i%5, people[i]));
		mmThePeople.insert(make_pair(i%5, people[i]));
	}
	
	cout << "Printing map (should be 10, but because of map property, is less)\n";
	printMaps<map <int, string>, map <int, string>::iterator>(mThePeople, mIt);
	cout << "Printing multi-map\n";
	printMaps<multimap <int, string>, multimap <int, string>::iterator>(mmThePeople, mmIt);

	return 0;
}


