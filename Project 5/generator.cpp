/*

David Walker
Comp-1102 Project 5 extra - data file generator
Assigned: 	11-19-2014
Due:		12-05-2014

*/

#include <iostream.h>
#include <fstream.h>
#include <math.h>
#include <string.h>
#include <iomanip.h>
#include <time.h>

const int FILENAME_SIZE = 255;

void getFileName( char fileName[] );
void openDataFile( ofstream& gradesDataFile, char fileName[] );
int getRandomNumber();
int getRandomGrade();

int main(void)
{
            srand ( time(NULL));
       
    ofstream gradesDataFile;
    char fileName[FILENAME_SIZE] = "\0";
    
    int numberRecords;
    int numberGrades;

    numberRecords = 0;
    
    getFileName( fileName );
    
    cout << "Creating file '" << fileName << "'." << endl;
    
    openDataFile( gradesDataFile, fileName );
    
    cout << "Number of records to generate: ";
    cin >> numberRecords;
    cout << endl;
    
    cout << "Number of grades per record to generate: ";
    cin >> numberGrades;
    cout << endl;
    
    gradesDataFile << numberGrades << '\n';
    
    for(int i = 1; i <= numberRecords; i++)
    {
        string firstName[20] = { "James", "John", "George", "Dave", "Steve", "Mary", "Jane", "Susie", "Kate", "Jean", "Patricia", "Lisa", "Sandra", "Jessica", "Angela", "Adam", "Ben", "Brian", "Kevin", "Robert" };
        string lastName[20] = { "Williams", "Jones", "Smith", "Davis", "Brown", "Johnson", "Moore", "Miller", "Wilson", "Taylor", "Anderson", "Thomas", "Jackson", "White", "Thompson", "Robinson", "Young", "Harris", "Martinez", "Garcia" };

        gradesDataFile << setw(25) << left << firstName[ getRandomNumber() ] + " " + lastName[ getRandomNumber() ];
        
        for(int i = 1; i <= numberGrades; i++)
        {
            gradesDataFile << " " << setw(3) << right << getRandomGrade();
        }
        
        if(i < numberRecords)
            gradesDataFile << '\n';
        
    }
    cout << "Data file generation complete." << endl;
    gradesDataFile.close();
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

void openDataFile( ofstream& gradesDataFile, char fileName[] )
{
    gradesDataFile.open(fileName);
    
    if(gradesDataFile.fail())
    {
        cout << "Error opening file '" << fileName << "'." << endl;
        exit(1);
    }
    else
    {
        cout << "'" << fileName << "' has been created." << endl;
    }
    
}

int getRandomNumber()
{
    int randNumber;
    randNumber = rand() % 20; 
    return randNumber;
}

int getRandomGrade()
{
    int randGrade;
    int max = 100;
    int min = 72;
    
    randGrade = rand()%(max-min + 1) + min;
    return randGrade;
}