/*
 *
 * Author: Linards Smeiksts
 * Last modified: 08.02.2021.
 *
 * Write a binary predicate that accepts strings as input
 * arguments and returns a value based on case-sensitive
 * comparison. 
 *
 */



#include<iostream>
#include<string>
#include<list>
#include<algorithm>
#include<cctype>
#include<vector>

using namespace std;

bool checkCaseInsensitive(const string& str1, const string& str2)
{
	string str1CaseIns(str1), str2CaseIns(str2);

	transform(str1.begin(), str1.end(), str1CaseIns.begin(), ::tolower);
	transform(str2.begin(), str2.end(), str2CaseIns.begin(), ::tolower);
	
	return (str1CaseIns < str2CaseIns);
}

int main()
{
	string theStr[] = {"Viens", "DIVI", "Divi", "DiVi", "divi", "viens"};
	vector <string> theStringVec(theStr, theStr + sizeof(theStr)/sizeof(string));
	vector <string>::iterator it;
	
	// Printing raw vector
	cout << "Printing raw vector:\n";
	for(it = theStringVec.begin(); it != theStringVec.end(); ++it)
	{
		cout << *it << endl;
	}
	cout << endl;	
	
	// Printing sorted vector (case sensitive)
	sort(theStringVec.begin(), theStringVec.end());
	cout << "Stadard sorted vector\n";
	for(it = theStringVec.begin(); it != theStringVec.end(); ++it)
	{
		cout << *it << endl;
	}
	
	cout << endl;
	sort(theStringVec.begin(), theStringVec.end(), checkCaseInsensitive);

	cout << "Sorted vector using case insensitive\n";
	// Printing sorted vector (case insensitive)
	for(it = theStringVec.begin(); it != theStringVec.end(); ++it)
	{
		cout << *it << endl;
	}
	return 0;
}
