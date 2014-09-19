/* This is the test bracket that I am using to test terms. It makes the following assumption:
	1) The variable used in the terms is always "x"
*/
#include "Term.h"
#include <iostream>
#include <string>
#include <list>
using namespace std;
//declare functions
list<Term> readPolynomial(string& Polynomial);
list<Term> AddPoly( const list<Term>& List_1, const list<Term>& List_2);
void show_commands();
int main()
{
	//print out terms
	

	show_commands();
	system("pause");
	return(0);
}
void ReadandAdd()
{
	list<Term> firstPoly;
	list<Term> secondPoly;
	list<Term> result;
	string firstPolySt;
	string secondPolySt;
	cout << "Enter the first polynomial:\n";
	getline(cin,firstPolySt);
	
	firstPoly=readPolynomial(firstPolySt);
	cout << "Enter the second polynomial:\n";
getline(cin,secondPolySt);

	secondPoly=readPolynomial(secondPolySt);
	result=AddPoly(firstPoly,secondPoly);
	for (list<Term>::iterator i = result.begin(); i!=result.end();++i)
	{
		cout <<  *i << "" ;
	}
}
void show_commands()
{
	string commands[] = {
		"Enter 2 Polynomials",
		"Exit" };
	const size_t NUM_COMMANDS = 2; 
	size_t choice = NUM_COMMANDS - 1;
	do {
		
		for (size_t i = 0; i < NUM_COMMANDS; i++) {
			cout << "Select: " << i << " " << commands[i] << "\n";
		}
		cin >> choice;
		cin.ignore(numeric_limits<int>::max(), '\n');
		switch (choice) {
		case 0: ReadandAdd(); break;
		case 1: cout << "Have a nice day!"; break;
		default: cout << "invalid option" <<endl;
		}
	} while (choice != NUM_COMMANDS-1);
}
