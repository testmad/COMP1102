/*

David Walker
Comp-1102 Project 1
Assigned: 	09-05-2014
Due:		09-17-2014

*/

#include <iostream.h>
#include <math.h> // is this really needed?

int main()
{	
	float a;
	float b;
	float c;
	float totalA;
	float totalB;
	
	system("cls");
	
	cout << "Input coefficient: ";
	cin >> a;
	while( a != -999 )
	{	
		
		cout << endl;
		cout << "Input coefficient: ";
		cin >> b;
		cout << endl;
		cout << "Input coefficient: ";
		cin >> c;
		if( (30 - 2 * a) < 0 )
		{
			cout << endl;
			cout << "The value of " << a << " results in a negative root.  You can't have a negative root." << endl;
		}
		else if( (3 * b + c) == 0 )
		{
			cout << endl;
			cout << "The values of " << b << " and " << c << " result in a zero denominator.  You can't divide by zero." << endl;
		}
		else
		{
			totalA = ((4 * (c)) + (sqrt(30 - (2 * (a)) ))) / ((3 * (b))+(c));
			totalB = ((4 * (c)) - (sqrt(30 - (2 * (a)) ))) / ((3 * (b))+(c));
			cout << endl;
			cout << "x = " << totalA << endl;
			cout << "\tOR" << endl;
			cout << "x = " << totalB << endl;
			cout << endl;
		}
		cout << endl;
		totalA = 0;
		totalB = 0;
		cout << "Input coefficient: ";
		cin >> a;
	}
}