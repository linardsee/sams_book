#include <iostream>

using namespace std;

int main()
{
	int num1, num2;

	cout << "Please, type the first integer: ";
	cin >> num1;
	cout << "\n";
	
	cout << "Please, type the second integer: ";
	cin >> num2;
	cout << "\n";

	if(num1 > num2)
		num1 = num2;
	else
		num2 = num1;

	cout << "Now num1 = " << num1 << " and num2 = " << num2 << ".\n";

}
