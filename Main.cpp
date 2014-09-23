/* Some Assumptions I can think of:
	1. The variable used in the terms is always "x"
	2. No negative exponent
	3. x^ must be followed by an exponent
	4. x^1 can be entered as x
	5. The polynomial is entered in descending order
*/
#include "Term.h"
#include <iostream>
#include <string>
#include <list>

using namespace std;
//declare functions
list<Term> readPolynomial(string& Polynomial);
list<Term> AddPoly( const list<Term>& List_1, const list<Term>& List_2);
void ReadandAdd();
void printPolynomial(const list<Term>& listToPrint);
int main()
{
	char option;
	bool quit=false;
	while (quit!=true)
	{	
		//Menu appears here
		cout <<"-------------------- MAIN MENU ------------------"<<endl;
		cout <<"<E>nter Polynomials\n<Q>uit\nPlease enter an option: ";
		cin>> option;
		cin.ignore(100,'\n');
		switch(option)
		{
			case 'e':
			case 'E': // Enter 2 polynomials
				ReadandAdd();
				break;
			case 'q':
			case 'Q': // Quit
				cout << "\nHave a nice day!" << endl;
				quit=true;
				break;
			default: // if user didn't enter valid option
				cout << "Please enter a valid option!" << endl;
		}
		cout<<"\n\n";
	}
	system("pause");
	return(0);
}
//function to read 2 polynomials, then add them and print the result
void ReadandAdd()
{
	list<Term> firstPoly;
	list<Term> secondPoly;
	list<Term> result;
	string firstPolySt;
	string secondPolySt;
	// read in first polynomial
	cout << "\nEnter the first polynomial:\n";
	getline(cin,firstPolySt);
	cin.clear();
	firstPoly=readPolynomial(firstPolySt);
	// read in second polynomial
	cout << "Enter the second polynomial:\n";
	getline(cin,secondPolySt);
	cin.clear();
	secondPoly=readPolynomial(secondPolySt);
	// add the 2 polynomials
	result=AddPoly(firstPoly,secondPoly);
	// print out the result
	cout << "\nResult:\n";
	printPolynomial(result);
}
//function to print out a polynomial
void printPolynomial(const list<Term>& listToPrint)
{
	for (list<Term>::const_iterator i = listToPrint.begin(); i!=listToPrint.end();++i)
	{
		if (i == listToPrint.begin() ) // for the first term, "+" should never be displayed
		{
			if (i->get_coefficient() > 0) 
			{
				int Coef = i->get_coefficient();
				int Expo = i->get_exponent();

				if (Expo == 0 ) // if the term has exponent == 0, only the coefficient is displayed
					cout << Coef;
				else if (Expo == 1 ) // if the term has exponent == 1, the coefficient is displayed with "x"
					if (Coef == 1) // if the coefficient == 1, only "x" is displayed
						cout << "x" ;
					else 
						cout << Coef << "x" ;
				else // display the term normally
					if (Coef == 1) // if the coefficient == 1, only "x^ some exponent" is displayed
						cout << "x^" << Expo;
					else
						cout << Coef << "x^" << Expo;
			}
			else // display the term normally 
				cout <<  *i ;
		}
		else
			cout <<  *i  ;
	}
}
