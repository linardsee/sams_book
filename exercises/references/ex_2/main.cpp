#include<iostream>

using namespace std;

int main()
{
	
	int varOne = 10;
	int * const pVar = &varOne;

	cout << "Here everything should be OK: varOne = " << varOne << 
		"; *pVar = " << *pVar;
		
	varOne = 6;
	*pVar = 7;

	cout << "\nHere everything should not be OK: varOne = " << varOne << 
		"; *pVar = " << *pVar;
	
		
	int varTwo = 100;
	*pVar = varTwo;

	cout << "\nNow *pVar = " << *pVar;
	
	return 0;
}
