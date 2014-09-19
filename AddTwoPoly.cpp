//Hoang Nguyen

#include <iostream>
#include <vector>
#include <list>
#include "Term.h"
#include "String_Tokenizer.h"
using namespace std;

//this function add 2 polynomials to one new polinomial
//take 2 lists and return 1 new list
list<Term> AddPoly( const list<Term>& List_1, const list<Term>& List_2)
{
	//iterator
	list<Term>::const_iterator Itr1 = List_1.begin();
	list<Term>::const_iterator Itr2 = List_2.begin();
	//call new list
	list<Term> result;
	//a temp term when 2 term have the same exponent
	Term temp;
	//continue till one iterator point the tail of the list
	while (Itr1!= List_1.end() && Itr2!=List_2.end())
	{
		//add the term with a bigger exponent to the new list
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
		//if 2 term have the same exponent, 
		//create a new term with addition of coeffecients and the same exponent
		//add it to new list
		else
		{
			temp=Term(Itr1->get_coefficient()+Itr2->get_coefficient(),Itr1->get_exponent());
			result.push_back(temp);
			Itr1++;
			Itr2++;
		}
	}
	//Add terms left to new list
	while (Itr2 != List_2.end()){
		result.push_back(*Itr2);
		++Itr2;
	}
	while (Itr1 != List_1.end()){
		result.push_back(*Itr1);
		++Itr1;
	}
	//return new list
	return result;
}
