/*
 *
 * Author: Linards Smeiksts
 * Last modified: 09.02.2021.
 *
 * You are writing an apllicaion that records the characteristics
 * of stars that come up on the horizon in the order in which they
 * rise. In astronomy, the size of the star is important as well
 * as information on their relative rise and set sequences. If 
 * sorting this collection of stars on the basis of their size, 
 * would you use std::sort ir std::stable_sort?
 *
 */



#include<iostream>
#include<string>
#include<algorithm>
#include<vector>

using namespace std;


class TheStars
{
	private:
		string name;
		int size;

	public:
		TheStars(string starName, int starSize);
		TheStars(string starName);
		TheStars();
		~TheStars(){};
		int getSize() const {return size;};
		void setSize(int theSize) {size = theSize;};
		string getName() const {return name;};
		void setName(string theName) {name = theName;};
};

TheStars::TheStars(string starName, int starSize)
{
	name = starName;
	size = starSize;
}

TheStars::TheStars(string starName): size(1)
{
	name = starName;
}	

TheStars::TheStars(): size(1), name("unknown")
{
}	

bool binaryPredicate(TheStars star1, TheStars star2)
{
	return (star1.getSize() < star2.getSize());
}


int main()
{
	TheStars star1;
	TheStars star2("polarzvaigzne");
	TheStars star3("lynx", 20);
	TheStars star4("sirius", 30);
	TheStars star5("huiriuss", 20);
	TheStars star6("canopus", 20);

	vector <TheStars> starsVec;
	vector <TheStars>::iterator itVec;
	starsVec.push_back(star1);
	starsVec.push_back(star2);
	starsVec.push_back(star3);
	starsVec.push_back(star4);
	starsVec.push_back(star5);
	starsVec.push_back(star6);

	stable_sort(starsVec.begin(), starsVec.end(), binaryPredicate);

	for(itVec = starsVec.begin(); itVec != starsVec.end(); ++itVec)
	{
		cout << itVec->getName() << " size is " << itVec->getSize() << "\n";
	}

	return 0;
}
