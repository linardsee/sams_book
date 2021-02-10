/*
 *
 * Author: Linards Smeiksts
 * Last modified: 02.02.2021.
 *
 * Program creates a vector of objects dynamically
 * Objects are created by user prompt.
 * User sets name, dimensions and price.
 * After input, it is possible to print the objects as well.
 *
 */



#include<iostream>
#include<vector>
#include<string>

using namespace std;

class Jar
{
	public:
		Jar();
		~Jar(){};
		string getName() const {return itsName;};
		void setName(string theName) {itsName = theName;};
		double getPrice() const {return itsPrice;};
		void setPrice(double thePrice) {itsPrice = thePrice;};
		unsigned int getHeight(void) const {return itsHeight;};
		unsigned int getWidth(void) const {return itsWidth;};
		void setDimension(unsigned int height);
		void setDimension(unsigned int height, unsigned int width);

	private:
		string itsName;
		double itsPrice;
		unsigned int itsHeight, itsWidth;
		const unsigned int defaultWidth = 100;
};

Jar::Jar()
{
	cout << "Constructing an object...\n";
}

void Jar::setDimension(unsigned int height)
{
	itsHeight = height;
	itsWidth = defaultWidth;
}

void Jar::setDimension(unsigned int height, unsigned int width)
{
	itsHeight = height;
	itsWidth = width;
}

int main()
{
	vector <Jar> jarArr;
	vector <Jar>::iterator it;
	string promtStr;
	double price;
	unsigned int realWidth, realHeight;
	unsigned int index;

	while(1)
	{
		cout << "\nChoose the option: \n";
		cout << "Input jar (press 'i')\n";
		cout << "Print a specific object parameters (press 'p')\n";
		cout << "Print object names (press 'pa')\n";
		cout << "Quit (press 'q')\n";
		
		cin >> promtStr;

		if(promtStr == "i")
		{
			jarArr.push_back(Jar());
			it = --jarArr.end(); 
			cout << "Enter the name: ";
			cin >> promtStr;
			it->setName(promtStr);
			cout << "The vector 1st element name is: " << it->getName() << " \n";

			cout << "Enter the price: ";
			cin >> price;
			it->setPrice(price);
			cout << "The vector's first element's price is: " << it->getPrice() << " Euros.\n";

			cout << "Enter the width and then height: ";
			cin >> realWidth;
			cout << "\nHeight: ";
			cin >> realHeight;
			it->setDimension(realHeight, realWidth);
			cout << "The vector's first element's height is: " << it->getHeight() << " cm and ";
			cout << it->getWidth() << " cm.\n";

			cout << "Object successfully built!\n";
		}

		if(promtStr == "pa")
		{
			if(jarArr.size() > 0)
			{
				cout << "All the jar are here: ";
				for(it = jarArr.begin(); it != jarArr.end(); ++it)
				{
					cout << it->getName() << ", ";
				}
				cout << endl;
				cout << "Number of jars: " << jarArr.size() << endl;
			}
			else
				cout << "The vector is empty, please fill it!\n";
		}

		if(promtStr == "q")
			break;

		if(promtStr == "p")
		{
			if(jarArr.size() > 0)
			{
				cout << "Enter the index: ";
				cin >> index;
				cout << endl;
				while( (index > (jarArr.size() - 1)) || (index < 0) )
				{
					cout << "Please enter a valid index!\n";
					cin >> index;
				}

				cout << "The name of the " << index + 1 << ". jar is " << jarArr[index].getName() << endl;
			}
			else
				cout << "The vector is empty, please fill it!\n";

		}
	}

	return 0;
}
