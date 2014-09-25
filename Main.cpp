/* Some Assumptions:
1. The variable used in the terms is always "x"
2. No negative exponent
3. x^ must be followed by an exponent
4. x^1 can be entered as x
5. The polynomial is entered in descending order
6. x is lowercase only */

#include "Polynomial.h"

// Forward declaration of function
//function to read 2 polynomials, then add them and print the result
void ReadandAddPoly();

int main()
{
	char option;
	bool quit=false;
	while (quit!=true)
	{	
		//Menu appears here
		cout <<"-------------------- MAIN MENU ------------------"<<endl; 
		cout <<"<E>nter Polynomials\n<Q>uit\nPlease enter an option (E Q): ";
		cin>> option;
		cin.ignore(100,'\n');
		switch(option)
		{
			case 'e':
			case 'E': // Enter 2 polynomials
				ReadandAddPoly();
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
void ReadandAddPoly() 
{
	//temp variables to store inputs
	string firstPolySt;
	string secondPolySt;

	// read in first polynomial
	cout << "\nEnter the first polynomial:\n";
	getline(cin,firstPolySt);
	cin.clear();
	Polynomial firstPoly = Polynomial(firstPolySt);
	
	// read in second polynomial
	cout << "Enter the second polynomial:\n";
	getline(cin,secondPolySt);
	cin.clear();
	Polynomial secondPoly=Polynomial(secondPolySt);

	// add the 2 polynomials and print out the result
	cout << "\nResult:\n";
	cout << firstPoly+secondPoly;
}
