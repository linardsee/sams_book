/*
 *
 * Author: Linards Smeiksts
 * Last modified: 02.02.2021.
 *
 * This is extended version of ex_1 
 * program. This extension does not allow to 
 * insert the same value in the vector.
 *  
 */



#include<iostream>
#include<vector>
#include<string>

using namespace std;

bool checkForEqual(int value, vector <int> vec);


int main()
{
	vector <int> theVector;
	int val = 0;

	while(1)
	{
		string menuStr;

		cout << "\nChoose the task:\n";
		cout << "Add a value to the vector (press 'a')\n";
		cout << "Show the value of vector given by index (press 's')\n";
		cout << "Delete a value of vector given by index (press 'd')\n";
		cout << "Print the whole vector (press 'p')\n";
		cout << "Quit (press q)\n";
		getline(cin >> ws, menuStr);
		
		if(menuStr == "q")
			break;

		if(menuStr == "a")
		{			
			cout << "Enter a valid integer value to push: ";
			cin >> val;
			cout << endl;

			if(theVector.size())
			{	
				while(checkForEqual(val, theVector))
				{
					cout << "Enter a valid integer value to push: ";
					cin >> val;
					cout << endl;
				}
				
				theVector.push_back(val);	
			}
			else
			{
				theVector.push_back(val);
			}		
		}

		if(menuStr == "p")
		{
			unsigned int nElementIndex = 0;
			while(nElementIndex < theVector.size())
			{
				cout << "Element at position ";
				cout << nElementIndex;
				cout << " is: ";
				cout << theVector[nElementIndex];
				cout << endl;

				++ nElementIndex;
			}
		}

		if(menuStr == "d")
		{
			if(theVector.size() > 0)
			{
				while(1)
				{
					cout << "Enter the index of the array to delete: ";
					cin >> val;
					cout << endl;

					if( (val > (theVector.size()-1)) || (val < 0) )
						cout << "Please enter a valid number!\n";
					else
						break;
				}

				unsigned int diff = (theVector.size() - 1) - val; 

				// instantiating a temporary vector
				vector <int> theCopyVector(theVector.end() - diff, theVector.end());

				for(int i = 0; i <= diff; ++i)
				{
					theVector.pop_back();
				}
				
				unsigned int nElementIndex = 0;
				while(nElementIndex < theCopyVector.size())
				{
					theVector.push_back(theCopyVector[nElementIndex]);

					++nElementIndex;
				}
			}
			else
				cout << "The vector is empty!\n";
		}
		
		if(menuStr == "s")
		{		
			do
			{
				cout << "Please, enter a valid index: ";
				cin >> val;
				cout << endl;
			}while( (val >= theVector.size()) || (val < 0) );
			
			cout << "The value of index ";
			cout << val;
			cout << " is: ";
			cout << theVector[val];
			cout << endl;
		}

		val = 0;

		cout << endl;
	}

	return 0;
}

bool checkForEqual(int value, vector <int> vec)
{
	// The comparison result
	bool theCompRes = false;

	for(vector <int>::iterator it = vec.begin(); it != vec.end(); ++it)
	{
		if(value == *it)
		{
			theCompRes = true;
			break;
		}
	}

	return theCompRes;
}

