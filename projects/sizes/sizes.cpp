#include <iostream>

using namespace std;

int main()
{
	cout << "The size of an int is: \t\t\t"
		<< sizeof(int) << " bytes.\n";
	cout << "The size of a short is: \t\t"
		<< sizeof(short) << " bytes.\n";
  	cout << "The size of a long is: \t\t\t"
		<< sizeof(long) << " bytes.\n";
	cout << "The size of a short is: \t\t"
		<< sizeof(char) << " bytes.\n";
	cout << "The size of a float is: \t\t"
		<< sizeof(float) << " bytes.\n";
  	cout << "The size of a double is: \t\t"
		<< sizeof(double) << " bytes.\n";
	cout << "The size of an bool is: \t\t"
		<< sizeof(bool) << " bytes.\n";

	return 0;
}
