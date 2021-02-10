/*
 *
 * Author: Linards Smeiksts
 * Last modified: 05.02.2021. 
 *
 * Define a multiset to store words and their meanings;
 * that is, make a multiset work as a dictionary. (Hint: the 
 * multiset should be one of a structure that contains two
 * strings: the word and its meaning).
 *
 */



#include<iostream>
#include<set>
#include<string>

using namespace std;

enum menu{
	AddMeanings = 1,
	DeleteMeaning = 2,
	FindMeaning = 3,
	PrintBook = 4,
	Quit = 5
};

struct Dictionary
{
	string strWord;
	string strMeaning;

	//Constructor
	Dictionary(const string& word, const string& meaning)
	{
		strWord = word;
		strMeaning = meaning;
	}


	bool operator == (const Dictionary& itemToCompare) const
	{
		return (itemToCompare.strWord == this->strWord);
	}

	bool operator < (const Dictionary& itemToCompare) const
	{
		return (this->strWord < itemToCompare.strWord);
	}
};

void addMeaning(multiset <Dictionary>& theMset);
void deleteMeaning(multiset <Dictionary>& theMset);
void findMeaning(multiset <Dictionary>& theMset);
void printAllMeanings(multiset <Dictionary>& theMset);


int main()
{
	int chooseMenu = 0;
	multiset <Dictionary> book;

	while(chooseMenu != Quit)
	{
		cout << endl << "*** Dictionary ***" << endl;
		cout << "Choose an option:\n";
		cout << "Add the dictionary, press 1\n";
		cout << "Delete a meaning, press 2\n";
		cout << "Find a meaning, press 3\n";
		cout << "Print all meanings, press 4\n";
		cout << "Quit the application, press 5\n";
		cout << ">";
		cin >> chooseMenu;
		cout << endl;

		switch(chooseMenu)
		{
			case AddMeanings:
				addMeaning(book);
				break;

			case DeleteMeaning:
				deleteMeaning(book);
				break;

			case FindMeaning:
				findMeaning(book);
				break;
			
			case PrintBook:
				printAllMeanings(book);
				break;

			case Quit:
				break;

			default:
				cout << "Please enter a valid number!\n";
		}
	}

	return 0;
}

void addMeaning(multiset <Dictionary>& theMset)
{
	string word, meaning;

	cout << "Insert the word: ";
	cin >> word;
	cout << endl;
	cout << "Insert the meaning: ";
	getline(cin >> ws, meaning);	
	cout << endl;

	theMset.insert(Dictionary(word, meaning));

	cout << "The dictionary successfully updated!\n";
}

void deleteMeaning(multiset <Dictionary>& theMset)
{
	string word;

	cout << "Write a word you would like to delete: ";
	cin >> word;
	cout << endl;

	multiset <Dictionary>::iterator it = theMset.find(Dictionary(word, ""));
	theMset.erase(it);

	cout << "The record was successfully removed!\n";
}

void findMeaning(multiset <Dictionary>& theMset)
{
	string word;
	typedef multiset <Dictionary>::iterator it;

	cout << "Write a word you would like to find: ";
	cin >> word;
	cout << endl;

	pair<it, it> ret = theMset.equal_range(Dictionary(word, ""));
	multiset <Dictionary>::iterator It = ret.first;

//	cout << "The first found word is: " << ret.first->strWord << " and its meaning is: " << ret.first->strMeaning << endl;

	while(It != ret.second)
	{	
		if(It != ret.second)
		{
			cout << It->strWord << "'s meaning is: " << It->strMeaning << endl;
		}
		else
		{
			cout << "The word is not found in the dictionary!\n";
		}
		++It;
	}
}

void printAllMeanings(multiset <Dictionary>& theMset)
{
	for(multiset <Dictionary>::iterator it = theMset.begin(); it != theMset.end(); ++it)
	{
		cout << it->strWord << " - " << it->strMeaning << endl;
	}
}
