/*

David Walker
Comp-1102 Project 4
Assigned: 	11-10-2014
Due:		11-14-2014

*/

#include <iostream.h>
#include <fstream.h>
#include <iomanip>

const int FILENAME_SIZE = 255;

void getFileName( char fileName[] );
void openDataFile( ifstream& gradeDataFile, char fileName[] );
void setGradeCount( ifstream& gradeDataFile, int& numGrades );
void displayRecord( ifstream& gradeDataFile, int numGrades );
void readRecord( ifstream& gradeDataFile, char studentName[], int studentGrades[], int numGrades );
float avgForRecord( int studentGrades[], int numGrades );
    float devForRecord( int studentGrades[], int numGrades );


int main(void)
{
    ifstream gradeDataFile;
    char fileName[FILENAME_SIZE];
    int recordNumber;
    int numGrades;
    
    recordNumber = 1;
    
    system("cls");

    getFileName( fileName );
    openDataFile( gradeDataFile, fileName );
    setGradeCount( gradeDataFile, numGrades );
    
    
    
    while( gradeDataFile.peek() != EOF )
    {
        cout << recordNumber << "  ";
        displayRecord( gradeDataFile, numGrades );


        
    }
    
    
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

void openDataFile( ifstream& gradeDataFile, char fileName[] )
{
    gradeDataFile.open(fileName);
    
    if(gradeDataFile.fail())
    {
        cout << "Error opening file '" << fileName << "'." << endl;
        exit(1);
    }
}

void setGradeCount( ifstream& gradeDataFile, int& numGrades )
{
    gradeDataFile >> numGrades;
    
}

void displayRecord ( ifstream& gradeDataFile, int numGrades )
{
    char studentName[25];
    int studentGrades[100];
    
    readRecord( gradeDataFile, studentName, studentGrades, numGrades );
    
    cout << studentName << " " << avgForRecord( studentGrades, numGrades) << " " << devForRecord(studentGrades, numGrades) << endl;
    
    
}

void readRecord( ifstream& gradeDataFile, char studentName[], int studentGrades[], int numGrades)
{
    gradeDataFile.get( studentName, 25);
    
    for( int i = 0; i <= numGrades; i++)
        cin >> studentGrades[i];
    
    gradeDataFile.get();
}

float avgForRecord( int studentGrades[], int numGrades )
{
    float smallestGrade = 0;
    float sum = 0;
    for( int i = 0; i <= numGrades; i++)
    {
        sum = sum + studentGrades[i];
        if( studentGrades[i] < smallestGrade )
            smallestGrade = studentGrades[i];
    }
    
    return (sum - smallestGrade)/(numGrades - 1);
}

float devForRecord( int studentGrades[], int numGrades )
{
    float avg = 0.0;
    float sum = 0;
    for( int i = 0; i <= numGrades; i++)
    {
        sum = sum + studentGrades[i];
    }
    
    avg = sum/numGrades;
    
    for( int i = 0; i <= numGrades; i++)
    {
        sum = sum + (studentGrades[i] - avg)*(studentGrades[i] - avg);
    }
    
    return sqrt( sum/numGrades );
}


