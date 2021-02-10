#include <iostream>
#include <string>

using namespace std;

int main()
{
	string str1 ("Linards");
	string str2 ("programmer");
	string str3 ("Smeiksts");
	string fullName;

	fullName = str1 + str2 + str3;

	cout << "My full name is: " << fullName << "\n";

	return 0;
}
