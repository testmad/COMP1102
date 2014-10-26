/*

David Walker
Comp-1102 Project 3b extra - data file generator
Assigned: 	10-20-2014
Due:		10-31-2014

*/

#include <iostream.h>
#include <fstream.h>
#include <math.h>
#include <string.h>
#include <iomanip.h>
#include <time.h>

const int FILENAME_SIZE = 255;

void getFileName( char fileName[] );
void openDataFile( ofstream& inventoryDataFile, char fileName[] );
string genAlphaNumeric(int length);

int main(void)
{
       
    ofstream inventoryDataFile;
    char fileName[FILENAME_SIZE] = "\0";
    
    int numberRecords;

    numberRecords = 0;
    
    getFileName( fileName );
    
    cout << "Creating file '" << fileName << "'." << endl;
    
    openDataFile( inventoryDataFile, fileName );
    
    cout << "Number of records to generate: ";
    cin >> numberRecords;
    cout << endl;
    
    for(int i = 1; i <= numberRecords; i++)
    {
        string sNumber;
        string sCode;
        string sDesc;
        
        int cStock;
        int minStock;
        int maxStock;
        
        double wPrice;
        double rPrice;
        
        int numYTD;
        
        sNumber = genAlphaNumeric(6);
        sCode = genAlphaNumeric(2);
        sDesc = genAlphaNumeric(12);
        
        cStock = rand() % 99999;
        minStock = rand() % 9999;
        maxStock = rand() % 99999;
        
        wPrice = ((double)rand())/((double)RAND_MAX) * 9999 + 0.55;
        rPrice = ((double)rand())/((double)RAND_MAX) * 9999 + 0.55;
        
        numYTD = rand() % 99999;
        
        
        inventoryDataFile << sNumber << sCode << sDesc << " ";
        inventoryDataFile << setw(5) << setfill('0') << cStock<<" ";
        inventoryDataFile << setw(4) << setfill('0') << minStock<<" ";
        inventoryDataFile << setw(5) << setfill('0') << maxStock<<" ";
        inventoryDataFile << setw(8) << setfill('0') << setprecision (2) << fixed << showpoint << wPrice << " ";
        inventoryDataFile << setw(9) << setfill('0') << setprecision (2) << fixed << showpoint << rPrice << " ";
        inventoryDataFile << setw(5) << setfill('0') << numYTD;
        
        if(i < numberRecords)
            inventoryDataFile << '\n';
        
    }
    cout << "Data file generation complete." << endl;
    inventoryDataFile.close();
 
}

void getFileName( char fileName[] )
{
    bool notValid = true;

    while(notValid)
    {    
        cout << "Enter filename for generation: ";
        cin.getline(fileName, FILENAME_SIZE, '\n');
    
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

void openDataFile( ofstream& inventoryDataFile, char fileName[] )
{
    inventoryDataFile.open(fileName);
    
    if(inventoryDataFile.fail())
    {
        cout << "Error opening file '" << fileName << "'." << endl;
        exit(1);
    }
    else
    {
        cout << "'" << fileName << "' has been created." << endl;
    }
    
}

string genAlphaNumeric(int length)
{   
    string str = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    int position;
    while(str.size() != length)
    {
        position = ((rand() % (str.size() - 1)));
        str.erase (position, 1);
    }
    return str;
}