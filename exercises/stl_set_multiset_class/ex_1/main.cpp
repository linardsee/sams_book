/*
 *
 * Author: Linards Smeiksts
 * Last modified: 03.02.2021.
 *
 * Extend the telephone directory example in this
 * lesson to find a person's name given a phone number,
 * without changing structure ContactItem. (Hint: Define
 * the set with a binary predicate that sorts items in 
 * accordance with the number, thus overrding the default
 * sort based on the < operator.
 *
 */



#include<set>
#include<iostream>
#include<string>

using namespace std;

enum MenuOptionSelection
{
	InsertContactsetEntry = 0,
	DisplayEntries = 1,
	FindNumber = 2,
	EraseEntry = 3,
	QuitApplication = 4
};

struct ContactItem
{
	string strContactsName;
	string strPhoneNumber;

	//Constructor
	ContactItem(const string& strName, const string& strNumber)
	{
		strContactsName = strName;
		strPhoneNumber = strNumber;
	}

	bool operator == (const ContactItem& itemToCompare) const
	{
		return (itemToCompare.strContactsName == this->strContactsName);
	}

	bool operator < (const ContactItem& itemToCompare) const
	{
		return (this->strContactsName < itemToCompare.strContactsName);
	}

};

struct CContactItem
{
	string strContactsName;
	string strPhoneNumber;

	//Constructor
	CContactItem(const string& strName, const string& strNumber)
	{
		strContactsName = strName;
		strPhoneNumber = strNumber;
	}

	bool operator == (const CContactItem& itemToCompare) const
	{
		return (itemToCompare.strPhoneNumber == this->strPhoneNumber);
	}

	bool operator < (const CContactItem& itemToCompare) const
	{
		return (this->strPhoneNumber < itemToCompare.strPhoneNumber);
	}

};


int ShowMenu();
ContactItem GetContactInfo();
void DisplayContactset (const set <ContactItem>& setContacts);
void FindContact (const set <ContactItem>& setContacts);
void EraseContact (set <ContactItem>& setContacts);

int main()
{
	set <ContactItem> setContacts;
	int nUserSelection = InsertContactsetEntry;

	while( (nUserSelection = ShowMenu () ) != (int) QuitApplication)
	{
		switch (nUserSelection)
		{
			case InsertContactsetEntry:
				setContacts.insert(GetContactInfo());
				cout << "Contacts set updated!" << endl << endl;
			break;

			case DisplayEntries:
				DisplayContactset (setContacts);
			break;

			case FindNumber:
				FindContact (setContacts);
			break;

			case EraseEntry:
				EraseContact (setContacts);
				DisplayContactset (setContacts);
			break;

			default:
				cout << "Invalid input '" << nUserSelection;
				cout << ".' Please choose an option between 0 and 4" << endl;
			break;
		}
	}

	cout << "Quiting! Bye!" << endl;
	return 0;
}

void DisplayContactset (const set <ContactItem>& setContacts)
{
	cout << "*** Displaying contact information ***" << endl;
	cout << "There are " << setContacts.size() << " entries:" << endl;

	set <ContactItem>::const_iterator iContact;
	for( iContact = setContacts.begin()
		; iContact != setContacts.end()
		; ++ iContact )
	cout << "Name: '" << iContact->strContactsName << "' Number: '"
	      << iContact->strPhoneNumber << "'" << endl;

	cout << endl;
}

ContactItem GetContactInfo()
{
	cout << "*** Feed contact information ***" << endl;
	string strName;
	cout << "Please enter the person's name" << endl;
	cout << "> ";
	cin >> strName;
	string strPhoneNumber;
	cout << "Please enter " << strName << "'s phone number" << endl;
	cout << "> ";
	cin >> strPhoneNumber;

	return ContactItem (strName, strPhoneNumber);
}

int ShowMenu()
{
	cout << "*** What would you like to do next? ***" << endl << endl;
	cout << "Enter 0 to feed a name and phone number" << endl;
	cout << "Enter 1 to Display all entries" << endl;
	cout << "Enter 2 to find an entry" << endl;
	cout << "Enter 3 to erase an entry" << endl;
	cout << "Enter 4 to quit this applicaiton" << endl << endl;
	cout << "> ";

	int nOptionSelected = 0;

	// Accept user input
	cin >> nOptionSelected;
	cout << endl;
	return nOptionSelected;
}

void FindContact (const set <ContactItem>& setContacts)
{
	cout << "*** Find a contact ***" << endl;
	cout << "Find by person ('p'), find by number ('n')\n";
	string menu;
	cin >> menu;

	if(menu == "n")
	{
		cout << "Enter the number you wish to find?" << endl;
		string strNumber;
		cin >> strNumber;	

		set <CContactItem> ssetContacts;

		for(set <ContactItem>::const_iterator it = setContacts.begin(); it != setContacts.end(); ++it)
		{
			ssetContacts.insert(CContactItem(it->strContactsName, it->strPhoneNumber));
		}

		set <CContactItem>::const_iterator iContactFound
			= ssetContacts.find (CContactItem ("", strNumber));

		if (iContactFound != ssetContacts.end())
		{
			cout << strNumber << " belongs to: ";
			cout << iContactFound->strContactsName << endl;
		}
		else
			cout << strNumber << " was not found in the contacts list" << endl;

		cout << endl;

	}
	
	if(menu == "p")
	{
		cout << "Whose number do you wish to find?" << endl;
		string strName;
		cin >> strName;

		set <ContactItem>::const_iterator iContactFound
			= setContacts.find (ContactItem (strName, ""));

		if (iContactFound != setContacts.end())
		{
			cout << strName << " is reachable at number: ";
			cout << iContactFound->strPhoneNumber << endl;
		}
		else
			cout << strName << " was not found in the contacts list" << endl;

		cout << endl;
	}
	return;
}



void EraseContact (set <ContactItem>& setContacts)
{
	cout << "*** Erase a contact ***" << endl;
	cout << "> ";
	string strName;
	cin >> strName;

	size_t nErased = setContacts.erase (ContactItem (strName, ""));
	if (nErased > 0)
		cout << strName << "'s contact information erased." << endl;
	else
		cout << strName << " was not found!" << endl;

	cout << endl;
}
