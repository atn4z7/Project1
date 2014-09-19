#include <iostream>
#include <vector>
#include <list>
using namespace std;

list<Term> AddPoly( const list<Term>& List_1, const list<Term>& List_2)
{
	list<Term>::const_iterator Itr1 = List_1.begin();
	list<Term>::const_iterator Itr2 = List_2.begin();

	list<Term> result;
	Term temp;
	while (Itr1!= List_1.end() && Itr2!=List_2.end())
	{
		//comparison sign 
		if (Itr1->get_exponent() > Itr2->get_exponent())
		{
			result.push_back(*Itr1);
			Itr1++;
		}
		else if (Itr1->get_exponent() < Itr2->get_exponent())
		{
			result.push_back(*Itr2);
			Itr2++;
		}
		else
		{
			temp=Term(Itr1->get_coefficient()+Itr2->get_coefficient(),Itr1->get_exponent());
			result.push_back(temp);
			Itr1++;
			Itr2++;
		}
	}
	while (Itr2 != List_2.end()){
		result.push_back(*Itr2);
		++Itr2;
	}
	while (Itr1 != List_1.end()){
		result.push_back(*Itr1);
		++Itr1;
	}
	//not sure it should return a list or pointer to head
	return result;
}
