#include <iostream>
int main()
{
	enum Days {Sunday, Monday, Tuesday, Wednesday, Thursday, Friday, 
	Saturday};

	Days today;
	today = Sunday;

	if(today == Sunday || today == Saturday)
		std::cout << "\nGotta love love weekends \n";
	else
		std::cout << "\nBack to work.\n";

	return 0;
}
