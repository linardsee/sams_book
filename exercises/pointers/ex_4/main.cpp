#include<iostream>

using namespace std;

int main()
{
	int myAge = 0;
	int * pAge = &myAge;

	cout << "myAge before pointer manipulation: " << myAge << "\n";
	*pAge = 25;

	cout << "myAge after pointer manipulation: " << myAge << "\n";

	return 0;
}
