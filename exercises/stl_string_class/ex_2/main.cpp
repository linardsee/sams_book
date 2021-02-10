/*
 *
 * Author: Linards Smeiksts
 * Last modified: 31.01.2021.
 *
 * Program tells the user the number of 
 * vowels in the given sentence.
 *
 */



#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

int main()
{
	
	string str1;
	const unsigned char numOfVowels = 5;
	unsigned char vowelArr[numOfVowels] = {'a', 'e', 'i', 'o', 'u'};
	size_t offset = 0;
        size_t searchOffset = 0;
	int vowelCnt = 0;

	while(1)
	{
		cout << "\nPlease enter a sentece (or 'q' to exit) to check the number of vowels: ";
		getline(cin, str1);
		
		if(str1 == "q")
			break;

		
		for(int i = 0; i < numOfVowels; i++)
		{
			while(offset != string::npos)
			{
				offset = str1.find(vowelArr[i], searchOffset);
				if(offset != string::npos)
					vowelCnt++;
				searchOffset = offset + 1;
			}
			offset = 0;
			searchOffset = 0;
		}

		cout << "\nThe count of vowels in this sentence is: ";
		cout << vowelCnt;
		cout << endl;
		
		vowelCnt = 0;

	}
	return 0;
}
