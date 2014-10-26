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

const int FILENAME_SIZE = 255;

void getFileName( char fileName[] );
void openDataFile( ifstream& inventoryDataFile, char fileName[] );
void readDataRecord(ifstream& inventoryDataFile, char stockNumber[], char stockDeptCode[], char stockDescription[], int& currentStock, int& minimumStock, int& maximumStock, float& wholesalePrice, float& retailPrice, int& soldYearToDate);

int main(void)
{
    ifstream inventoryDataFile;
    char fileName[FILENAME_SIZE] = "\0";
    char stockNumber[7] = "\0";
    char stockDeptCode[3] = "\0";
    char stockDescription[13] = "\0";
    
    int currentStock;
    int minimumStock;
    int maximumStock;
    float wholesalePrice;
    float retailPrice;
    int soldYearToDate;
    int recordNumber;

    recordNumber = 0;
    
    system("cls");

    getFileName( fileName );
    openDataFile( inventoryDataFile, fileName );
    
    while(!inventoryDataFile.eof())
    {
        readDataRecord( inventoryDataFile, stockNumber, stockDeptCode, stockDescription, currentStock, minimumStock, maximumStock, wholesalePrice, retailPrice, soldYearToDate );

        if(currentStock <= minimumStock)
        {
            recordNumber++;
            cout << setw(5) << setfill(' ') << recordNumber << "    " << setw(6) << stockNumber << "    " << setw(12) << stockDescription << "    " << setw(5) << setfill('0') << fixed << setprecision(2) << showpoint << maximumStock-currentStock << endl;
        }
    }
    inventoryDataFile.close();
    
    if(recordNumber == 0)
        cout << "Nothing to reorder.";
}

void getFileName( char fileName[] )
{
    bool notValid = true;

    while(notValid)
    {    
        cout << "Enter filename: ";
        cin.getline(fileName, FILENAME_SIZE, '\n');
        cout << endl;
        
        if(fileName[0] == '\0')
        {
            cout << "No filename provided." << endl;
            continue;
        }
        else if(strstr(fileName, ".") == 0)
        {
            cout << "No file extension provided." << endl;
            continue;
        }
        else
        {
            notValid = false;
        }
    }
}

void openDataFile( ifstream& inventoryDataFile, char fileName[] )
{
    inventoryDataFile.open(fileName);
    
    if(inventoryDataFile.fail())
    {
        cout << "Error opening file '" << fileName << "'." << endl;
        exit(1);
    }
}

void readDataRecord(ifstream& inventoryDataFile, char stockNumber[], char stockDeptCode[], char stockDescription[], int& currentStock, int& minimumStock, int& maximumStock, float& wholesalePrice, float& retailPrice, int& soldYearToDate)
{
    inventoryDataFile.get(stockNumber, 7);
    inventoryDataFile.get(stockDeptCode, 3);
    inventoryDataFile.get(stockDescription, 13);
    
    inventoryDataFile>>currentStock;
    inventoryDataFile>>minimumStock;
    inventoryDataFile>>maximumStock;
    inventoryDataFile>>wholesalePrice;
    inventoryDataFile>>retailPrice;
    inventoryDataFile>>soldYearToDate;
    inventoryDataFile.get();
}