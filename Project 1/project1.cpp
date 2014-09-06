/*
David Walker
Comp-1102 Project 1
Assigned: 	09-05-2014
Due:		09-17-2014
*/

#include <iostream.h>
#include <stdio.h>
#include <math.h>

void clear() {
    // CSI[2J clears screen, CSI[H moves the cursor to top-left corner
    cout << "\x1B[2J\x1B[H" << flush;
}

int main(void)
{

	clear();
	cout << "Please press enter.";
	cin.get();
	return 0;
}
