/*
Justin Karnes
Term Class header file.
*/

#ifndef TERM_H
#define TERM_H

#include <iostream>
#include <stdexcept>
using namespace std;

class Term{
private:
	int coefficient; // The coefficient of the term. Negative terms will have negative coefficients
	int exponent; // The exponent of the term. This is always positive.
public:
	// Constructor
	Term();
	Term(int, int);
	// Destructor
	~Term();

	// Get and Set functions
	int get_coefficient(void) const; // returns the coefficient of the term.
	int get_exponent(void) const; // returns the exponent of the term. This number can be negative
	void set_coefficient(int); // Sets the coefficient of a Term
	void set_exponent(int); // Sets the exponent of a term. This can accept a negative number

	// Operator Definitions
	const Term operator+(const Term& L_term) const; // Adds two terms together
	// Comparison operators to comppare exponents
	bool Term::operator<(const Term& L_term);
	bool Term::operator>(const Term& L_term); 
	bool Term::operator==(const Term& L_term);
	// Assignment operator
	const Term& Term::operator=(const Term& L_term);

	// Output function
	friend ostream& operator<<(ostream& output, const Term& aTerm);
};

#endif
