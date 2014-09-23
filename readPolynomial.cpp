//AN NGUYEN
#include "Term.h"
#include <string> 
#include "String_Tokenizer.h"
#include <list>
#include <stdexcept>
using namespace std;

// this function reads a polynomial from a string and return the polynomial as a list
void ReplaceStringInPlace(string& subject, string& search, string& replace);
list<Term> readPolynomial(string& Polynomial)
{
	int expo = 0;
	int coef = 0;
	string coefSt;
	string expoSt;
	list<Term> MyPolynomial;

	// replace - with +-
	ReplaceStringInPlace (Polynomial,string("-"),string("+-"));
	
	// split input by + to get separated terms
	String_Tokenizer st1(Polynomial, "+");

	// continue to parse as long as there is a term
	while (st1.has_more_tokens())
	{
		string currentTerm = st1.next_token(); // get current Term

		if (currentTerm.find("x^") != string::npos) // term contains "x^"
		{ 
			string first_Token, second_Token; // variables to store the coefficient and the exponent
			// split currentTerm by x^
			String_Tokenizer st2(currentTerm, "x^");
			first_Token = st2.next_token();
			second_Token = st2.next_token();
			if (currentTerm.find(first_Token) < currentTerm.find("x^") ) // first_Token is the coefficient
			{
				if (first_Token == "-") //special case
					coefSt = "-1";
				else
					coefSt = first_Token;
				expoSt = second_Token != "" ? second_Token : throw invalid_argument( "Invalid Input" ); // only assign the exponent if second_Token is not empty
			}
			else if (currentTerm.find(first_Token) > currentTerm.find("x^") ) // first_Token is the exponent (the coefficient is hidden)
			{
				coefSt = "1"; 
				expoSt = first_Token;
			}
			else throw invalid_argument( "Invalid Input" );
		} 
		else if (currentTerm.find("x") != string::npos) // term contains "x"
		{
			//split currentTerm by x
			String_Tokenizer st2(currentTerm, "x");
			if (!st2.has_more_tokens()) // the term is "x" only
			{
				coefSt = "1";
				expoSt = "1";
			}
			else // the term has a coefficient
			{
				coefSt = st2.next_token();
				if (coefSt == "-") //special case
					coefSt = "-1";
				expoSt = "1";
			}
		}
		else // term contains only the coefficient
		{
			coefSt = currentTerm;
			expoSt = "0";
		}

		//convert string to int
		coef= stoi(coefSt);
		expo=stoi(expoSt);

		//create the term and add to the list only if the coefficient is not 0
		if (coef != 0)
			MyPolynomial.push_back(Term(coef,expo));
	}
	return MyPolynomial;
}
//function to replace string in place
/* Source http://stackoverflow.com/questions/5343190/how-do-i-replace-all-instances-of-of-a-string-with-another-string by Czarek Tomczak*/
void ReplaceStringInPlace(string& subject, string& search, string& replace)
{
    size_t pos = 0;
    while ((pos = subject.find(search, pos)) != string::npos) 
	{
         subject.replace(pos, search.length(), replace);
         pos += replace.length();
	}
}
