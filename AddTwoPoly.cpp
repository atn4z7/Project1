//Hoang Nguyen
#include <iostream>
#include <vector>
#include <list>
#include "Term.h"
#include "String_Tokenizer.h"
using namespace std;

//this function adds 2 polynomials and returns the result as a new polynomial
list<Term> AddPoly( const list<Term>& List_1, const list<Term>& List_2)
{
	//iterators
	list<Term>::const_iterator Itr1 = List_1.begin();
	list<Term>::const_iterator Itr2 = List_2.begin();
	//new list
	list<Term> result;
	//a temp term to store the adding
	Term temp;
	//continue till one iterator points to the tail of the list
	while (Itr1!= List_1.end() && Itr2!=List_2.end())
	{
		//add the term with a bigger exponent to the new list
		if ((Term)*Itr1 > (Term)*Itr2)
		{
			result.push_back(*Itr1);
			Itr1++;
		}
		else if ((Term)*Itr1 < (Term)*Itr2)
		{
			result.push_back(*Itr2);
			Itr2++;
		}
		//if 2 term have the same exponent, just add them and add the result to new list
		else
		{
			temp = (Term)*Itr1+(Term)*Itr2;
			if (temp.get_coefficient() != 0) // only add to the result if the term has non-zero coefficient
				result.push_back(temp);
			Itr1++;
			Itr2++;
		}
	}
	//Add any remaining terms to the new list
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
