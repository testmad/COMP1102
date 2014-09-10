/*

David Walker
Comp-1102 Project 1
Assigned: 	09-05-2014
Due:		09-17-2014

*/

#include <iostream.h>
#include <string.h>
#include <sstream.h>
#include <math.h>

using namespace std;

//Function prototypes.
void showUsage(string);
void inputError(int, double, double);
double getCoefficient(string);
bool checkCoefficient(string, double);
void showProblem();
void showDecimal();
void showExact();

// First I want to declare some global variables for program parameters.
bool enableDecimal;
bool disableVerbose;
bool disableExact;
bool enableLoop;

// Declaring a few globals for working with our numbers.
double numberA;
double numberB;
double numberC;
double solution1;
double solution2;

int main( int argc, char *argv[] ) // Because I was asked, argc is how many arguments were given, and argv[] is an array of pointers(*) to char.
{
	// Now define variables to set default behavior.  The compiler will complain about this.
	enableDecimal = true;
	disableVerbose = true;
	disableExact = true;
	enableLoop = true;
	
	if( argc < 1 )
		// Normally you would want to check for a number of args more than 1, but in this case I still want the program to run without any args given.
		return 1;
	
	// Now I need to parse the args given, if any.	
	for( int i = 1; i < argc; i++)
	{
		string arg = argv[i];
		if( ( arg == "-h") || (arg == "--help") )
		{
			showUsage( argv[0] );
			return 0;
		}
		else if ( ( arg == "-d") || (arg == "--decimal") )
		{
			enableDecimal = false;
		}
		else if ( ( arg == "-v") || (arg == "--verbose") )
		{
			disableVerbose = false;
		}
		else if ( ( arg == "-e") || (arg == "--exact") )
		{
			disableExact = false;
		}
		else if ( ( arg == "-l") || (arg == "--loop") )
		{
			enableLoop = false;
		}
		else
		{
			
		}
	}
	
	// Declare input variable.
	string input;
	
	
	// Zero globals
	numberA, numberB, numberC, solution1, solution2 = 0;
	
	// Clear the screen.
	system("cls");
	
	// Sticking closer to what was covered in class here.. Prime Read.
	numberA = getCoefficient("a");
	
	while(enableLoop)
	{
		numberB = getCoefficient("b");
		numberC = getCoefficient("c");
		
		if(!disableVerbose)
			showProblem();
			
		//Compute here.
		solution1 = ((4 * (numberC)) + (sqrt(30 - (2 * (numberA)) ))) / ((3 * (numberB))+(numberC));
		solution2 = ((4 * (numberC)) - (sqrt(30 - (2 * (numberA)) ))) / ((3 * (numberB))+(numberC));
	
		if(enableDecimal)
			showDecimal();
	
		if(!disableExact)
		{
			showExact();
		}
		
		numberA, numberB, numberC, solution1, solution2 = 0;
		
		numberA = getCoefficient("a");
	}
	
	numberB = getCoefficient("b");
	numberC = getCoefficient("c");
		
	if(!disableVerbose)
		showProblem();
			
	//Compute here.
	solution1 = ((4 * (numberC)) + (sqrt(30 - (2 * (numberA)) ))) / ((3 * (numberB))+(numberC));
	solution2 = ((4 * (numberC)) - (sqrt(30 - (2 * (numberA)) ))) / ((3 * (numberB))+(numberC));
	
	if(enableDecimal)
		showDecimal();
	
	if(!disableExact)
	{
		showExact();
	}
}

// Shows program usage when the -h parameter is used.
void showUsage(string programName)
{
	cerr	<< endl
			<< "Usage: " << programName << " <option(s)>\n"
			<< endl
			<< "Options:\n"
			<< "\t-h,--help\t\tShow this help message.\n"
			<< "\t-v,--verbose\t\tShow the problem being solved.\n"
			<< "\t-d,--decimal\t\tDisables results in decimal approximations.\n"
			<< "\t-e,--exact\t\tEnables results in standard form.\n"
			<< "\t-l,--loop\t\tDisables program loop execution.\n"
			<< endl
			<< "Example: \n" 
			<< "\t" << programName << " -d -e\n"
			<< endl;
}

// Simple error handler.  Could have enumerated them, but I only have a few.
void inputError(int errorID, double coefficientValue1)
{
	if( errorID == 1)
	{
		cout << endl;
		cout << "Error: Invalid input." << endl;
	}
	else if( errorID == 2)
	{
		cout << endl;
		cout << "Error: Negative root result. Input a number less than " << coefficientValue1 << "." << endl;
	}
	else if( errorID == 3)
	{
		cout << endl;
		cout << "Error: Division by 0. Input a number greater or less than " << coefficientValue1 << "." << endl;
	}
}

// Prompts for input and processes it for use.  Using a do.. while so that the function will loop until proper input is given.
// Wanted to avoid recursive functions and this seemed to be the simplest solution.
double getCoefficient(string coefficientID)
{
	string input;
	double number;
	bool invalid = true;
	
	do
	{
		cout << endl;
		cout << "Please provide a value for coefficient " << coefficientID << ": ";

		getline(cin, input); // Get the entire input as a string.

		if(input.find(' ') == 1) // Searching string for spaces.
		{
			inputError(1,0);
		}
		else
		{
			stringstream numberStream(input);
			if(numberStream >> number) // Extracting to a double.
			{
				if(numberStream.eof()) // Making sure nothing is left over.
				{
					if(checkCoefficient(coefficientID, number)) // Checking if the number passes certain tests before assigning it to its global. 
						invalid = false; // Exiting the loop.
					else
						invalid = true; // Staying in loop for another go.
				}
				else
				{
					inputError(1,0);
				}
			}
		}
	}
	while(invalid);
	
	if((coefficientID == "a") && (number == -999)) // Checking for the conditions for program termination.
		exit(0);
	
	return number; // Returning the double.
}
// Checking if the number provided doesn't cause a problem during input and before its assigned to a global.
bool checkCoefficient(string coefficientID, double coefficientValue)
{
	bool status;
	
	if(coefficientID == "a")
	{
		if(coefficientValue == -999)
			exit(0);
		else if((30-2*coefficientValue) < 0)
		{
			inputError(2, coefficientValue);
			status = false;
		}
		else
			status = true;
	}
	else if(coefficientID == "c")
	{
		if((3 * numberB + coefficientValue) == 0)
		{
			inputError(3, coefficientValue);
			status = false;
		}
		else
			status = true;
	}
	else
	{
		status = true;
	}
	return status;
}

void showProblem()
{
	cout << endl;
	cout << "Problem:" << endl;
	cout << "                4c" << "\xF1\xFB" << "30-2a" << endl;
	cout << "           x = \xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4" << endl;
	cout << "                  3b+c" << endl;
}

void showDecimal()
{
	if(solution1 == 0 && solution2 == 0)
	{
		cout << endl;
		cout << "Decimal approximations:" << endl;
		cout << "                        x = " << solution1 << endl;
		cout << endl;
	}
	else
	{
		cout << endl;
		cout << "Decimal approximations:" << endl;
		cout << endl;
		cout << "                        x = " << solution1 << endl;
		cout << "                             OR" << endl;
		cout << "                        x = " << solution2 << endl;
		cout << endl;
	}
}
void showExact()
{
	double problem3a;
	double problem3b;
	double problem3b_intPart;
	int problem3b_outsideRoot;
	int problem3b_insideRoot;
	int d;
	double problem3c;
	double problem3c_intPart;
	
	problem3a = 4 * (numberC);
	problem3b = 30 - (2 * (numberA));

	if(modf(problem3b, &problem3b_intPart) == 0.0)
	{
		problem3b_outsideRoot = 1;
		problem3b_insideRoot = problem3b;
		d = 2;
		while(d * d <= problem3b_insideRoot)
		{
			if(problem3b_insideRoot % (d * d) == 0)
			{
				problem3b_insideRoot = problem3b_insideRoot / (d * d);
				problem3b_outsideRoot = problem3b_outsideRoot * d;
			}
			else
			{
				d = d + 1;
			}
		}
		//cout << problem3b_insideRoot << endl;
		//cout << problem3b_outsideRoot << endl;
	}
	else
	{
		problem3b_outsideRoot = 1;
	}
	
	problem3c = (3 * (numberB))+(numberC);
	
	if(problem3c < 0)
	{
		cout << "Exact result:" << endl;
		cout << endl;
		if(modf(problem3c, &problem3c_intPart) == 0.0)
		{
			if((1/(abs(problem3c))) == 1)
				cout << "              x = - ( " << problem3a << "\xF1";
			else
			{
			cout << "                      1" << endl;
			cout << "              x = - \xC4\xC4\xC4\xC4 ( " << problem3a << "\xF1";
			}
		}
		else
		{
			cout << "              x = " << 1/problem3c << " ( " << problem3a << "\xF1";
		}
		if(problem3b_insideRoot == 0)
		{	
			if((1/(abs(problem3c))) != 1)
			{
				cout << problem3b_insideRoot << " )" << endl;
				if(modf(problem3c, &problem3c_intPart) == 0.0)
					cout << "                     " << abs(problem3c) << endl;
			}
		}
		else
		{
			if(problem3b_outsideRoot != 1)
			{
				if(problem3b_insideRoot != 1)
				{
					if((1/problem3c) != 1)
						cout << problem3b_outsideRoot << "\xFB" << problem3b_insideRoot << " )" << endl;
					else
						cout << problem3b_outsideRoot << "\xFB" << problem3b_insideRoot << endl;
				}
				else
					if((1/problem3c) != 1)
						cout << problem3b_outsideRoot << " )" << endl;
			}
			else
			{
				if(modf(problem3b, &problem3b_intPart) == 0.0)
				{
					if((1/problem3c) != 1)
						cout << "\xFB" << problem3b << " )" << endl;
					else
						cout << "\xFB" << problem3b << endl;
				}
				else
				{
					cout << sqrt(problem3b) << " )" << endl;
				}
			}
			if((1/(abs(problem3c))) != 1)
				if(modf(problem3c, &problem3c_intPart) == 0.0)
					cout << "                     " << abs(problem3c) << endl;
		}
	}
	else if(problem3c > 0)
	{
		cout << "Exact result:" << endl;
		cout << endl;
		if(modf(problem3c, &problem3c_intPart) == 0.0)
		{
			if((1/problem3c) == 1)
				cout << "              x = " << problem3a << "\xF1";
			else
			{
				cout << "                    1" << endl;
				cout << "              x = \xC4\xC4\xC4\xC4 ( " << problem3a << "\xF1";
			}
		}
		else
		{
			cout << "              x = " << 1/problem3c << " ( " << problem3a << "\xF1";
		}
		if(problem3b_insideRoot == 0)
		{
			if((1/problem3c) != 1)
			{
				cout << problem3b_insideRoot << " )" << endl;
				if(modf(problem3c, &problem3c_intPart) == 0.0)
					cout << "                   " << problem3c << endl;
			}
		}
		else
		{
			if(problem3b_outsideRoot != 1)
			{
				if(problem3b_insideRoot != 1)
				{
					if((1/problem3c) != 1)
						cout << problem3b_outsideRoot << "\xFB" << problem3b_insideRoot << " )" << endl;
					else
						cout << problem3b_outsideRoot << "\xFB" << problem3b_insideRoot << endl;
				}
				else
					if((1/problem3c) != 1)
						cout << problem3b_outsideRoot << " )" << endl;
			}
			else
			{
				if(modf(problem3b, &problem3b_intPart) == 0.0)
				{
					if((1/problem3c) != 1)
						cout << "\xFB" << problem3b << " )" << endl;
					else
						cout << "\xFB" << problem3b << endl;
				}
				else
				{
					cout << sqrt(problem3b) << " )" << endl;
				}
			}
			if((1/problem3c) != 1)
				if(modf(problem3c, &problem3c_intPart) == 0.0)
					cout << "                   " << problem3c << endl;
		}
	}
}