/*
Justin Karnes
Term Class header file.
*/
#pragma once
using namespace std;
#include <iostream>
class Term{
private:
	int coefficient; // The coefficient of the term. Negative terms will have negative coefficients
	int exponent; // The exponent of the term. This is always positive.
public:
	Term();
	Term(int, int);
	~Term();

	// Get and Set functions
	int get_coefficient(void) const; // returns the coefficient of the term.
	int get_exponent(void) const; // returns the exponent of the term. This number can be negative
	void set_coefficient(int); // Sets the coefficient of a Term
	void set_exponent(int); // Sets the exponent of a term. This can accept a negative number
	
	// Operator Definitions
	const Term operator+(const Term& L_term); // Adds two terms together
	
	// An's update
	bool Term::operator<(const Term& L_term);
	bool Term::operator>(const Term& L_term); 
	bool Term::operator==(const Term& L_term);
	friend ostream& operator<<(ostream& output, const Term& aTerm);
	const Term& Term::operator=(const Term& L_term);
};
