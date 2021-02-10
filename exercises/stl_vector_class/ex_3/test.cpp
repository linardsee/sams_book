

#include<iostream>
#include<string>
#include<typeinfo>

using namespace std;

int main()
{
	string str;

	cout << "Enter a string: ";
	cin >> str;
	
	cout << endl;

	cout << "The type of string is: ";
	cout << typeid(str).name() << "\n";

	return 0;
}
