/*
 *
 * Author: Linards Smeiksts
 * Last modified: 02.02.2021.
 *
 * Exercise 2.
 *
 * Using a short program, demonstrate that an iterator pointing 
 * to an element in a list continues to remain valid even after
 * another element has been inserted before it, thus changing the
 * relative position of the former element.
 *
 */



#include<iostream>
#include<string>
#include<list>

using namespace std;

int main()
{
	list <int> theTestList;
	theTestList.push_front(1);
	theTestList.push_front(2);
	theTestList.push_front(3);

	list <int>::iterator it = ++theTestList.begin();

	cout << "The value under the iterator before pushing_front and pushing back: " << *it << endl;

	theTestList.push_front(10);
	theTestList.push_back(15);

	cout << "The value under the iterator after pushing_front and pushing back: " << *it << endl;


	return 0;
}
