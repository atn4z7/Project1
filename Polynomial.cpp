/*
An Nguyen + Hoang Nguyen
Polynomial Class declarations
*/

#include "Polynomial.h"

/* Function to remove the leading and trailing spaces from a string 
   Source: Blackboard, provided by Prof. Kuhail */
string trim(const string& the_string)
{
	size_t p = the_string.find_first_not_of(" ");
	if (p == string::npos) return "";
	size_t q = the_string.find_last_not_of(" ");
	return the_string.substr(p, q - p + 1);
}

/* Function to replace string in place 
   Source: http://stackoverflow.com/questions/5343190/how-do-i-replace-all-instances-of-of-a-string-with-another-string by Czarek Tomczak */
void ReplaceStringInPlace(string& subject, string& search, string& replace)
{
    size_t pos = 0;
    while ((pos = subject.find(search, pos)) != string::npos) 
	{
         subject.replace(pos, search.length(), replace);
         pos += replace.length();
	}
}

//Polynomial Class Implementation
//constructor
Polynomial::Polynomial()
{}
//this constructor parses the input to get separated terms and add them to List_Terms
Polynomial::Polynomial(string& poly) 
{	
	//temporary variables to store the term, the coefficient and the exponent
	int expo = 0;
	int coef = 0;
	string coefSt;
	string expoSt;
	string currentTerm;

	// replace - with +-
	ReplaceStringInPlace (poly,string("-"),string("+-"));
	
	// split input by + to get separated terms
	String_Tokenizer st1(poly, "+");

	// continue to parse as long as there is a term
	while (st1.has_more_tokens())
	{
		currentTerm = trim(st1.next_token()); // get current Term

		if (currentTerm.find("x^") != string::npos) // term contains "x^"
		{ 
			string first_Token, second_Token; // variables to store the coefficient and the exponent
			// split currentTerm by x^
			String_Tokenizer st2(currentTerm, "x^");
			first_Token = trim(st2.next_token());
			second_Token = trim(st2.next_token());
			if (currentTerm.find(first_Token) < currentTerm.find("x^") ) // first_Token is the coefficient
			{
				if (first_Token == "-") //special case (user entered "-x^...")
					coefSt = "-1";
				else
					coefSt = first_Token;
				expoSt = second_Token != "" ? second_Token : throw invalid_argument( "Invalid Input" ); // only assign the exponent if second_Token is not empty
			}
			else if (currentTerm.find(first_Token) > currentTerm.find("x^") ) // first_Token is the exponent (the coefficient is hidden with value 1 )
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
				coefSt = trim(st2.next_token());
				if (coefSt == "-") //special case (user entered "-x...")
					coefSt = "-1";
				expoSt = "1";
			}
		}
		else if (currentTerm.find("X") != string::npos) // term contains "X" uppercase
			throw invalid_argument( "Invalid Input" );
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
			List_Terms.push_back(Term(coef,expo));
	}
}

//destructor
Polynomial::~Polynomial()
{}

//operator Definitions
const Polynomial Polynomial::operator+(const Polynomial& L_Poly) const // Adds two polynomials together
{
	//iterators
	list<Term>::const_iterator Itr1 = this->List_Terms.begin();
	list<Term>::const_iterator Itr2 = L_Poly.List_Terms.begin();
	//the result
	Polynomial result = Polynomial();
	Term temp; //a temp term to store term when adding

	//continue till one iterator points to the tail of the list
	while (Itr1!= this->List_Terms.end() && Itr2!=L_Poly.List_Terms.end())
	{
		//add the term with a bigger exponent to the new list
		if ((Term)*Itr1 > (Term)*Itr2)
		{
			result.List_Terms.push_back(*Itr1);
			Itr1++;
		}
		else if ((Term)*Itr1 < (Term)*Itr2)
		{
			result.List_Terms.push_back(*Itr2);
			Itr2++;
		}
		//if 2 term have the same exponent, just add them together and add the result to new list
		else
		{
			temp = (Term)*Itr1+(Term)*Itr2;
			if (temp.get_coefficient() != 0) // only add to the result if the term has non-zero coefficient
				result.List_Terms.push_back(temp);
			Itr1++;
			Itr2++;
		}
	}
	//Add any remaining terms to the new list
	while (Itr2 != L_Poly.List_Terms.end()){
		result.List_Terms.push_back(*Itr2);
		++Itr2;
	}
	while (Itr1 != this->List_Terms.end()){
		result.List_Terms.push_back(*Itr1);
		++Itr1;
	}
	return result; //return new list
}

//output function
ostream& operator<<(ostream& output,const Polynomial& poly)
{
	for (list<Term>::const_iterator i = poly.List_Terms.begin(); i!=poly.List_Terms.end();++i)
	{
		if (i == poly.List_Terms.begin() ) 
		{   // for the first term, "+" should never be displayed
			if (i->get_coefficient() > 0) 
			{
				int Coef = i->get_coefficient();
				int Expo = i->get_exponent();

				if (Expo == 0 ) // if the term has exponent == 0, only the coefficient is displayed
					output << Coef;
				else if (Expo == 1 ) // if the term has exponent == 1, the coefficient is displayed with "x"
					if (Coef == 1) // if the coefficient == 1, only "x" is displayed
						output << "x" ;
					else 
						output << Coef << "x" ;
				else // display the term normally
					if (Coef == 1) // if the coefficient == 1, only "x^ some exponent" is displayed
						output << "x^" << Expo;
					else
						output << Coef << "x^" << Expo;
			}
			else // display the term normally 
				output <<  *i ;
		}
		else
			output <<  *i  ;
	}
	return output;
}
