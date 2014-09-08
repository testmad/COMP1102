/*

David Walker
Comp-1102 Project 1
Assigned: 	09-05-2014
Due:		09-17-2014

I'm aware of a few instances where user input could cause a problem.  Such as 
providing a letter instead of a number, pressing a function key, spaces, or 
giving no input at all by pressing Enter.

Making use of getline and stringstream allows me to pull the users input as a
string including unwanted input and safely convert to an integer or request
a new number.

In order to make sure that all coefficients are truly valid
in the context of the problem, I am splitting the problem into smaller
pieces so that I can check for error producing input during execution.

I will make extensive use of () to make sure the problem is solved properly.

1) 30 - (2 * a)
2) (3 * b) + c

*/

#include <iostream.h>
#include <string.h>
//#include <sstream.h>
#include <math.h>

using namespace std;

static void show_usage(string name)
{
	cerr	<< endl
			<< "Usage: " << name << " <option(s)>\n"
			<< endl
			<< "Options:\n"
			<< "\t-h,--help\t\tShow this help message.\n"
			<< "\t-d,--decimal\t\tDisables results in decimal approximations.\n"
			<< "\t-e,--exact\t\tEnables results in standard form.\n"
			<< "\t-l,--loop\t\tDisables program loop execution.\n"
			<< endl
			<< "Example: \n" 
			<< "\t" << name << " -d -e\n"
			<< endl;
}

static void get_number(string name)
{
	cout << endl;
	cout << "Please provide a value for coefficient " << name << ": ";
	getline(cin, input);
	
	if(input.find(' ') == 1)
	{
		cout << endl;
		cout << "Please do not use spaces." << endl;
	}
	else	
		return input;
}

int main( int argc, char* argv[] )
{
	//First I want to declare my parameters.
	bool enableDecimal;
	bool disableExact;
	bool enableLoop;
	
	if( argc < 1 )
		//Normally you would want to check for a number of args more than 1, but in this case I still want the program to run without any args given.
		return 1;
	
	//Now I need to parse the args given, if any.	
	for( int i = 1; i < argc; i++)
	{
		string arg = argv[i];
		if( ( arg == "-h") || (arg == "--help") )
		{
			show_usage( argv[0] );
			return 0;
		}
		else if ( ( arg == "-d") || (arg == "--decimal") )
		{
			enableDecimal = false;
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
	
	system("cls");
	
	input = "";
	numA = 0;
	numB = 0;
	numC = 0;
	
	while(enableLoop)
	{
		get_number(a);
		
		
	
	
	
	
	
	
	
	
	
	
	
	
	
	}
	
	
}