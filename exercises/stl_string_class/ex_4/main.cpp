/*
 *
 * Author: Linards Smeiksts
 * Last modified: 31.01.2021.
 *
 * Program concatenates 4 individual strings
 *
 */



#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

int main()
{
	string str1 = "I";
	string str2 = "Love";
	string str3 = "STL";
	string str4 = "String";
	string strSum;

	strSum = str1 + " " + str2 + " " + str3 + " " + str4 + "!";

	cout << strSum;
	cout << endl;


	return 0;
}
