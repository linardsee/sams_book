/*
 *
 * Author: Linards Smeiksts
 * Last modified: 23.01.2021.
 *
 * Program makes a simple class called 
 * Employee
 *
 */



#include<iostream>

using namespace std;

class Employee
{
	public:
		Employee (int age, int yearsOfService, int salary);
		~Employee() {}

		void setAge(int age);
		void setYearsOfService(int years);
		void setSalary(int salary);
		int getAge() const;
		int getYearsOfService() const;
		int getSalary() const;
	private:
		int itsAge;
		int itsYearsOfService;
		int itsSalary;
};

Employee::Employee(int age, int yearsOfService, int salary)
{
	itsAge = age;
	itsYearsOfService = yearsOfService;
	itsSalary = salary;

	cout << "Employee object has been created!\n";
}

int Employee::getAge() const
{
	return itsAge;
}

int Employee::getYearsOfService() const
{
	return itsYearsOfService;
}

int Employee::getSalary() const
{

	return itsSalary / 1000;
}

void Employee::setAge(int age)
{
	itsAge = age;
	cout << "Age has been set! Age = " << age << "\n";
}

void Employee::setYearsOfService(int years)
{
	itsYearsOfService = years;
	cout << "Years of service has been set! Years = " << years << "\n";
}

void Employee::setSalary(int salary)
{
	itsSalary = salary;
	cout << "Salary has been set! Salary = " << salary << "\n";
}

int main()
{
	Employee Janis(35, 10, 3000);
	Employee Gints(20, 2, 1200);

	cout << "Janis settings...\n";
	//Janis.setAge(35);
	cout << "Janis age: " << Janis.getAge() << "\n";
	//Janis.setYearsOfService(10);
	//Janis.setSalary(4000);
	cout << "Janis salary: " << Janis.getSalary() << " thousand EURos. \n";

	cout << "Gints settings...\n";
	//Gints.setAge(25);
	//Gints.setYearsOfService(2);
	//Gints.setSalary(1200);
	cout << "Gints salary: " << Gints.getSalary() << " thousand EURos. \n";



	return 0;
}
