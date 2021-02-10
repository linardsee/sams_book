#include <iostream>

using namespace std;

unsigned short int division(unsigned short int a, unsigned short int b);

int main()
{
	unsigned short int a, b, c;
 	b = 0;

	cout << "Please enter the first number: ";
	cin >> a;
	cout << "\n";

	cout << "Please enter the second number: ";	
	while(b == 0)
	{
		cin >> b;
	}
	cout << "\n";

	c = division(a, b);	
	
	cout << "Result of division: " << c << ".\n";

	return 0;
}

unsigned short int division(unsigned short int a, unsigned short int b)
{
	unsigned short res;

	res = a/b;

	return res;
}
