/*
Justin Karnes
Term Class declarations
*/

#include "Term.h"

// Default Constructor
Term::Term()
{}

//Argument Constructor
Term::Term(int new_coefficient, int new_exponent){
	coefficient = new_coefficient;
	exponent = new_exponent;
}

// Destructor
Term::~Term()
{}

// Get and Set functions
int Term::get_coefficient(void) const{
	return this->coefficient;}

int Term::get_exponent(void) const{
		return exponent;
}

void Term::set_coefficient(int new_coefficient){
	coefficient = new_coefficient;
}

void Term::set_exponent(int new_exponent){
	exponent = new_exponent;
}

// Operator Definitions
const Term Term::operator+(const Term& L_term) const{
	if (this->exponent == L_term.exponent){
		return Term((this->coefficient + L_term.coefficient), this->exponent);
	}
	else throw std::logic_error("Exponents of Terms must match.");
}
bool Term::operator<(const Term& L_term)
{ return (this->exponent < L_term.exponent); } 

bool Term::operator>(const Term& L_term)
{ return (this->exponent > L_term.exponent); } 

bool Term::operator==(const Term& L_term)
{ return (this->exponent == L_term.exponent); } 

// assignment operator
const Term& Term::operator=(const Term& L_term)
{
	this->coefficient = L_term.coefficient;
	this->exponent = L_term.exponent;
	return *this;
}

// output function
ostream& operator<<(ostream& output, const Term& aTerm)
{
	int Coef = aTerm.coefficient;
	int Expo = aTerm.exponent;

	if (Expo == 0 ) // if the term has exponent == 0, only the coefficient is displayed
		output << (Coef > 0 ? "+" : "") << Coef;
	else if (Expo == 1 ) // if the term has exponent == 1, the coefficient is displayed with "x"
	{
		if (abs(Coef) == 1) // if the coefficient == +- 1, only the sign is displayed with "x"
			output << (Coef > 0 ? "+" : "-") << "x" ;
		else 
			output << (Coef > 0 ? "+" : "") << Coef << "x" ;
	}
	else // display the term normally
	{
		if (abs(Coef) == 1) // if the coefficient == +- 1, only the sign of the coefficient is displayed 
			output << (Coef > 0 ? "+" : "-") << "x^" << Expo;
		else
			output << (Coef > 0 ? "+" : "") << Coef << "x^" << Expo;
	}
	return output;
}
