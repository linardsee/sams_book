#include<iostream>

using namespace std;

int main()
{
	int num;
	int * pNum = &num;
	int &number = num;

	cout << "Integer num before manipulations: " << num;
	cout << "\nInteger pointer to num before manipulations: " << *pNum;
	cout << "\nInteger reference of num before manipulations: " << number;
	cout << "\n";

	// Manipulations
	//
	
	num = 6;

	cout << "\nInteger num after  manipulations: " << num;
	cout << "\nInteger pointer to num after manipulations: " << *pNum;
	cout << "\nInteger reference of num after manipulations: " << number;
	cout << "\n";

	// Few more 
	// manupulations
	
	*pNum = 10;
	
	cout << "\nInteger num after  manipulations: " << num;
	cout << "\nInteger pointer to num after manipulations: " << *pNum;
	cout << "\nInteger reference of num after manipulations: " << number;
	cout << "\n";

	// Few more 
	// manupulations
	
	number = 20;

	cout << "\nInteger num after  manipulations: " << num;
	cout << "\nInteger pointer to num after manipulations: " << *pNum;
	cout << "\nInteger reference of num after manipulations: " << number;
	cout << "\n";

	cout << "\nAddress of num: " << &num;
	cout << "\nAddress of reference: " << &number;
	cout << "\n";

	return 0;
}
