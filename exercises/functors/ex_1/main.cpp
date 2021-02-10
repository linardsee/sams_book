/*
 *
 * Author: Linards Smeiksts
 * Last modified: 07.02.2021.
 *
 * Write a unary function that can be used with std::for_each to 
 * display the double of the input parameter.
 *
 */



#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

template <typename T>
struct intDouble
{
	void operator () (const T& numToDouble)
	{
		cout << 2*numToDouble << " ";
	}
};

int main()
{	
	// Print result using simple functor
	intDouble<int> st1;
	cout << "Functor result: ";
	st1(40); 
	cout << endl;
	
	// Print results using for_each
	vector <int> vec;
	vector <int>::iterator it;
	for(int i = 0; i < 10; i++)
	{
		vec.push_back(i);
	}
	
	for_each(vec.begin(), vec.end(), intDouble<int>());

	return 0;	
}
