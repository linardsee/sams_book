/*
 *
 * Author: Linards Smeiksts
 * Last modified: 09.02.2021.
 *
 * Demonstrate how STL algortihms such as copy use iterators to do
 * their function without needing to know the nature of the desti-
 * nation collections by copying between two sequences held in two
 * dissimilar containers.
 *
 */



#include<iostream>
#include<vector>
#include<list>
#include<algorithm>
#include<string>

using namespace std;

template<typename T, typename iT>
void printContainer(T& container, iT& it)
{

	cout << endl;
	for(it = container.begin(); it != container.end(); ++it)
	{
		cout << *it << " ";
	}
	cout << endl;
}

int main()
{
	string theNames[] = {"oz", "cd", "as", "yt", "lo"};

	vector <string> strVec(theNames, theNames + sizeof(theNames)/sizeof(string));
	vector <string>::iterator itVec;
	
	list <string> strList(5);
	list <string>::iterator itList;
	
	copy(strVec.begin(), strVec.end(), strList.begin());
	// Print after copy:
	printContainer <vector<string>, vector<string>::iterator>(strVec, itVec);
	printContainer <list<string>, list<string>::iterator>(strList, itList);

	return 0;
}
