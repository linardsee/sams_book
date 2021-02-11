/*
 *
 * Author: Linards Smeiksts
 * Last modified: 11.02.2021.
 *
 * A queue of people (class CPerson) are lining up at the post office.
 * CPerson contains a member attributes that holds age and gender and 
 * is defined as 
 * class CPerson
 * {
 * 	public:
 * 		int m_nAge;
 * 		bool m_bIsFemale;
 * };
 * Write a binary predicate for the priority_queue that helps service
 * older people and women (in that order) on a priority.
 *
 */



#include<queue>
#include<iostream>

using namespace std;

class CPerson
{
	public:
		CPerson(int theAge, bool isWoman);
		CPerson(int theAge);
		CPerson(): m_nAge(20), m_bIsFemale(false){};
		~CPerson(){};
		int m_nAge;
		bool m_bIsFemale;
};

CPerson::CPerson(int theAge, bool isWoman)
{
	m_nAge = theAge;
	m_bIsFemale = isWoman;
}

CPerson::CPerson(int theAge): m_bIsFemale(true)
{
	m_nAge = theAge;
}

class binaryPredicate
{
	public:
		bool operator() (const CPerson& person1, const CPerson& person2)
		{
			bool theFinalState;

			if( (!person1.m_bIsFemale && !person2.m_bIsFemale) || (person1.m_bIsFemale && person2.m_bIsFemale) )
			{
				theFinalState = person1.m_nAge < person2.m_nAge;
			}

			if(!person1.m_bIsFemale && person2.m_bIsFemale)
			{
				theFinalState = true;
			}

			if(person1.m_bIsFemale && !person2.m_bIsFemale)
			{
				theFinalState = false;
			}

			return theFinalState; 
		}	
};

int main()
{
	CPerson man1, man2, man3;
	CPerson man4(70, true);
	CPerson man5(50, false);
	CPerson man6(34);

	priority_queue <CPerson, vector<CPerson>, binaryPredicate> pQueue;

	pQueue.push(man1);
	pQueue.push(man2);
	pQueue.push(man3);
	pQueue.push(man4);
	pQueue.push(man5);
	pQueue.push(man6);

	cout << "Order (by age) in which people have been inserted: ";
	cout << man1.m_nAge << " " << man2.m_nAge << " " << man3.m_nAge << " " << man4.m_nAge << " "
	       << man5.m_nAge << " " << man6.m_nAge << endl;

	// Deleting in priority queue order
	cout << "Deleting the priority queue: \n";
	while(pQueue.size() > 0)
	{
		cout << pQueue.top().m_nAge << " " << pQueue.top().m_bIsFemale << endl;
		pQueue.pop();
	}

	return 0;
}
