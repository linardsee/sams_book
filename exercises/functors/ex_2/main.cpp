/*
 *
 * Author: Linards Smeiksts
 * Last modified: 07.02.2021.
 *
 * Extend this predicate to indicate the number of times it 
 * was used.
 *
 */



#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

template <typename T>
struct intDouble
{	
	int nCnt;
	intDouble(){nCnt = 0;}

	void operator () (const T& numToDouble)
	{
		cout << 2*numToDouble << " ";
		++nCnt;
	}
};

struct sortInt
{
	bool operator () (const int& lhs, const int& rhs)
	{
		return (lhs < rhs);
	}
};

int main()
{	
	// Print result using simple functor
	intDouble<int> st1;
	sortInt st2;
	cout << "Functor result: ";
	st1(50);
	cout << endl;
	
	// Print results using for_each
	vector <int> vec;
	vector <int>::iterator it;
	for(int i = 0; i < 10; i++)
	{
		vec.push_back(10-i);
	}
	
	st1 = for_each(vec.begin(), vec.end(), intDouble<int>());

	cout << "\nFunction object (functor) was called " << st1.nCnt << " times.\n";

//	st2 = for_each(vec.begin(), vec.end(), sortInt());

	return 0;	
}
