/*

David Walker
Comp-1102 Project 3b
Assigned: 	10-20-2014
Due:		10-31-2014

*/

#include <iostream.h>
#include <iomanip.h>
#include <fstream.h>
#include <string.h>

int main(void)
{
    ifstream inventoryDataFile;
    
    char stockNumber[7];
    
    int currentStock;
    int minimumStock;
    int maximumStock;
    int recordNumber;
    
    recordNumber = 1;
    
    char fileName[255];
    
    cout << "Enter filename: ";
    
    cin.getline(fileName, sizeof(fileName), '\n');
    
    if(strstr(fileName, ".") == 0)
        cout << "No file extension provided." << endl;
    
    if(fileName[0] == '\0')
        cout << "No filename provided." << endl;
    
    inventoryDataFile.open(fileName);
    
    if(inventoryDataFile.fail())
    {
        cout << "Error opening file '" << fileName << "'." << endl;
        exit(1);
    }
    
    while(!inventoryDataFile.eof())
    {
        //readInventoryData( int currentStock, int minimumStock, int maximumStock );
        cout << "reading" <<endl;
    
    }
    
    
    
    
    
    
}