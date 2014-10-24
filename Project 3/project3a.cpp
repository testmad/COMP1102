/*

David Walker
Comp-1102 Project 3a
Assigned: 	10-20-2014
Due:		10-31-2014

*/

#include <iostream.h>
#include <iomanip>

int main(void)
{
    int startHours;
    int startMinutes;
    int elapsedMinutes;
    int newHours;
    int newMinutes;
    
    startHours = 0;
    startMinutes = 0;
    
    cout << "Enter start hours: ";
    cin >> startHours;
    cout << endl;
    cout << "Enter start minutes: ";
    cin >> startMinutes;
    cout << endl;
    cout << "Enter elapsed minutes: ";
    cin >> elapsedMinutes;
    cout << endl;
    
    cout << startHours << ":" << startMinutes << endl;
    cout << elapsedMinutes << endl;
    
    newHours = ((startMinutes + elapsedMinutes)/60 + startHours)%24;
    
    newMinutes = (startMinutes + elapsedMinutes)%60;
    
    if(newHours >= 12)
       {
            if(newHours > 12)
                newHours = newHours - 12;

            cout << setw(2) << setfill('0') << newHours << ":" << setw(2) << setfill('0') << newMinutes << " P.M."<< endl;
       }
    else
       {
            if(newHours == 0)
                newHours = 12;
        
            cout << setw(2) << setfill('0') << newHours << ":" << setw(2) << setfill('0') << newMinutes << " A.M."<< endl;
       }
    
}