/*
An Nguyen + Hoang Nguyen
Polynomial Class header file.
*/

#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

#include <string> 
#include <list>
#include "Term.h"
#include "String_Tokenizer.h"

class Polynomial{
private:
	list<Term> List_Terms; //a list that store terms
public:
	//constructor
	Polynomial();
	Polynomial(string& poly);
	//destructor
	~Polynomial();
	//operator Definitions
	const Polynomial operator+(const Polynomial& L_term) const; // Adds two polynomials together
	//output function
	friend ostream& operator<<(ostream& output,const Polynomial& poly);
	bool isEmpty() const; //check if the list is empty
};

#endif
