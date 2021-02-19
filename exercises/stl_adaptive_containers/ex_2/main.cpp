/*
 *
 * Author: Linards Smeiksts
 * Last modified: 19.02.2021.
 *
 * Write a program that reverses the user's string input using 
 * the stack class.
 *
 */



#include<iostream>
#include<string>
#include<stack>

using namespace std;

int main()
{
	string inputStr, outputStr;
	stack <char> stackOfStringChars;

	cout << "**** Weolcome to string reversing program ****"  << endl;
	cout << "Please enter some string: ";
	cin >> inputStr;
	cout << endl;

	for(int i = 0; i < inputStr.length(); i++)
	{
		stackOfStringChars.push(inputStr[i]);
	}


	for(int i = 0; i < inputStr.length(); i++)
	{
		outputStr.push_back(stackOfStringChars.top());
		//outputStr.append(stackOfStringChars.top());
		stackOfStringChars.pop();
	}

	cout << "The reversed string looks like: " << outputStr << endl;

	return 0;

}
