/*
Justin Karnes
Term Class declarations
*/
#pragma once
#include <exception>
#include <stdexcept>
#include "Term.h"
#include <iostream>
using namespace std;
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

const Term Term::operator+(const Term& L_term){
	if (this->exponent == L_term.exponent){
		return Term((this->coefficient + L_term.coefficient), this->exponent);
	}
	else throw std::logic_error("Exponents of Terms must match.");
}

//  An's update
bool Term::operator<(const Term& L_term)
{ return (this->exponent < L_term.exponent); } 

bool Term::operator>(const Term& L_term)
{ return (this->exponent > L_term.exponent); } 

bool Term::operator==(const Term& L_term)
{ return (this->exponent == L_term.exponent); } 

// output function
ostream& operator<<(ostream& output, const Term& aTerm)
{
	// I have added this check to make sure that if an exponent is of the power (1) that
	// the term output includes the variable in the output of the term. -Jkarnes 9/22 8:33 PM
	if (aTerm.get_exponent() == 1)
		output << aTerm.get_coefficient() << "x";
	else if (aTerm.get_exponent() != 0 )
		output << aTerm.get_coefficient() << "x^" << aTerm.get_exponent();
	else 
		output << aTerm.get_coefficient();
	return output;
}
// assignment operator
const Term& Term::operator=(const Term& L_term)
{
	this->coefficient = L_term.coefficient;
	this->exponent = L_term.exponent;
	return *this;
}
