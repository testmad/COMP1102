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
#include <sstream.h>
#include <math.h>

int main( int argc, char* argv[] )
{
	string input;
	double numA;
	double numB;
	double numC;
	
	double problem1;
	double problem2;
	double problem3a;
	double problem3b;
	double problem3b_intPart;
	int problem3b_outsideRoot;
	int problem3b_insideRoot;
	int d;
	double problem3c;
	double problem3c_intPart;
	bool exact;
	string arg;
	
	exact = 0;
	
	if(argc != 1)
	{
//	}
//	else
//	{
		arg = argv[1];
		if((arg == "-e") || (arg == "--exact"))
		{
			exact = 1;
		}
	}

	//cout << string( 100, '\n' );
	system("cls");

	while(true)
	{
	input = "";
	numA = 0;
	numB = 0;
	numC = 0;
	
	//problem1 = 0;
	//problem2 = 0;
	//problem3a = 0;
	//problem3b = 0;
	//problem3c = 0;
	
		while(true)
		{
			cout << endl;
			cout << "Please provide a value for coefficient a: ";
			getline(cin, input);
			
			if(input.find(' ') == 1)
			{
				cout << endl;
				cout << "Please do not use spaces." << endl;
				continue;
			}
			
			stringstream aStream(input);
			if (aStream >> numA)
			{
				if(numA == -999)
					exit(0);
				else
					if((30 - 2 * numA) < 0)
					{
						cout << endl;
						cout << "The number given would result in the square root of a negative." << endl;
						continue;
					}
				break;
			}
			cout << endl;
			cout << "Please enter a valid number." << endl;
		}

		while(true)
		{
			cout << endl;
			cout << "Please provide a value for coefficient b: ";
			getline(cin, input);
			
			if(input.find(' ') == 1)
			{
				cout << endl;
				cout << "Please do not use spaces." << endl;
				continue;
			}
			
			stringstream aStream(input);
			if (aStream >> numB)
				break;
			cout << endl;
			cout << "Please enter a valid number." << endl;
		}
		
		while(true)
		{
			cout << endl;
			cout << "Please provide a value for coefficient c: ";
			getline(cin, input);
			
			if(input.find(' ') == 1)
			{
				cout << endl;
				cout << "Please do not use spaces." << endl;
				continue;
			}
			
			stringstream aStream(input);
			if (aStream >> numC)
				if(numB == 0 && numC == 0)
				{
					cout << endl;
					cout << "Coefficient c cannot be 0 since coefficient b is 0.\nThis would result in trying to divide by 0." << endl;
					continue;
				}
				else
					break;
			cout << endl;
			cout << "Please enter a valid number." << endl;
		}
	
		cout << endl;
		cout << "You entered " << numA << " " << numB << " " << numC << endl;
		
		
		
		problem1 = ((4 * (numC)) + (sqrt(30 - (2 * (numA)) ))) / ((3 * (numB))+(numC));
		
		problem2 = ((4 * (numC)) - (sqrt(30 - (2 * (numA)) ))) / ((3 * (numB))+(numC));
		
		problem3a = 4 * (numC);
		
		problem3b = 30 - (2 * (numA));
		
		//if(problem3b % 1 == 0)
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
			
			
			cout << problem3b_insideRoot << endl;
			cout << problem3b_outsideRoot << endl;
		}
		else
		{
			problem3b_outsideRoot = 1;
		}
		
		problem3c = (3 * (numB))+(numC);
		
		if(problem1 == 0 && problem2 == 0)
		{
			cout << endl;
			cout << "Decimal approximations:" << endl;
			cout << "                        x = " << problem1 << endl;
			cout << endl;
		}
		else
		{
			cout << endl;
			cout << "Decimal approximations:" << endl;
			cout << endl;
			cout << "                        x = " << problem1 << endl;
			cout << endl;
			cout << "                        x = " << problem2 << endl;
			cout << endl;
		}
		if(exact)
		{
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
	}
}
