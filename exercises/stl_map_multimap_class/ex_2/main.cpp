/*
 *
 * Author: Linards Smeiksts
 * Last modified: 07.02.2021.
 *
 * The following is a map template definition in your dictionary 
 * application:
 * map <wordProperty, string, fPredicate> mapWordDefinition;
 *
 * where word is the structure
 * struct wordProperty
 * {
 * string strWord;
 * bool bIsFromLatin;
 * };
 *
 * Define the binary predicate fPredicate that will help the map 
 * sort a key of type wordProperty according to the string attribute
 * it contains.
 *
 */



#include<iostream>
#include<string>
#include<algorithm>
#include<map>

using namespace std;

struct wordProperty
{
//	wordProperty(string str): bIsFromLatin(true) {strWord = str;}

	string strWord;
	bool bIsFromLatin;
};

struct fPredicate
{
	bool operator () (const wordProperty& word1, const wordProperty& word2) const 
	{
		string str1NoCase(word1.strWord), str2NoCase(word2.strWord);
		transform(word1.strWord.begin(), word1.strWord.end(), str1NoCase.begin(), ::tolower);
		transform(word2.strWord.begin(), word2.strWord.end(), str2NoCase.begin(), ::tolower);

		return(str1NoCase < str2NoCase);
	};
};

int main()
{	
	string strTheWord, strMeaning;
	multimap <wordProperty, string, fPredicate> Dictionary;
	multimap <wordProperty, string, fPredicate>::iterator it;
	cout << "*** Simple dictionary book app ***\n";
	
	cout << "Enter the dictionary book entries (q to exit):\n";
	while(1)
	{
		cout << "Word: ";
		cin >> strTheWord;
		cout << "\n"; 
		if( strTheWord  == "q")
			break;
		cout << "Meaning: ";
		getline(cin >> ws, strMeaning);
		cout << "\n";
		
		//wordProperty word(strTheWord);
		wordProperty word;
		word.strWord = strTheWord;

		Dictionary.insert(make_pair(word, strMeaning));
	}
	
	cout << "Printing the contents of dictionary book: \n";
	for(it = Dictionary.begin(); it != Dictionary.end(); ++it)
	{
		cout << "Word: " << (it->first).strWord << " Meaning: " << (*it).second << endl; 
	}

	return 0;
}
