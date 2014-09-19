#include <iostream>
#include <vector>
#include <list>
using namespace std;

Term AddTerm( Term* Itr_1; Term* Itr_2)
{
	if (Itr_1==NULL || Itr_2==NULL)
		//throw error, not sure about this code
		throw error;
	else
	{
		list<Term> result;
		Term temp;
		while (Itr_1!=NULL && Itr_2!=NULL)
		{
			//comparison sign 
			if ( *Itr_1>*Itr_2)
			{
				result.push_back(*Itr_1);
				Itr_1++;
			}
			else if (*Itr_1<*Itr_2)
			{
				result.pish_back(*Itr_2);
				Itr_2++;
			}
			else
			{
				temp=Term(*Itr_1.coefficient+*Itr_2.coefficient,*Itr_1.exponent);
				result.push_back(temp);
			}
		}
		while (itr2 != list_2.end()){
			result.push_back(*itr2);
			++itr2;
		}
		while (itr1 != list_1.end()){
			result.push_back(*itr1);
			++itr1;
		}
		//not sure it should return a list or pointer to head
		return Term;
	}
