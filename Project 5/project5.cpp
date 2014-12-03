/*

David Walker
Comp-1102 Project 5
Assigned: 	11-19-2014
Due:		12-05-2014

*/

#include <iostream.h>
#include <fstream.h>
#include <iomanip>

const int FILENAME_SIZE = 255;

void getFileName( char fileName[] );
void openDataFile( ifstream& gradeDataFile, char fileName[] );
void setGradeCount( ifstream& gradeDataFile, int& numGrades );
void initArrays( int studentGrades[], char nameList[][25], float avgList[], int nameTags[], int avgTags[] );
void processDataFile( ifstream& gradeDataFile, char studentName[], int studentGrades[], int numGrades, char nameList[][25], float avgList[], int& numRecords );
float avgForRecord( int studentGrades[], int numGrades );
void sortByAvg( float avgList[], int avgTags[], int numRecords, char nameList[][25], ofstream& avgOutFile );
void sortByName( char nameList[][25], int nameTags[], int numRecords, float avgList[], ofstream& avgOutFile );

int main(void)
{
    ifstream gradeDataFile;
    char fileName[FILENAME_SIZE];
    
    ofstream avgOutFile;
    ofstream nameOutFile;

    int numGrades;
    int numRecords;
    
    char studentName[25];
    int studentGrades[100];
    
    char nameList[100][25];
    float avgList[100];
    
    int nameTags[100];
    int avgTags[100];
    
    system("cls");

    getFileName( fileName );
    openDataFile( gradeDataFile, fileName );
    setGradeCount( gradeDataFile, numGrades );
    
    initArrays( studentGrades, nameList, avgList, nameTags, avgTags );

    processDataFile( gradeDataFile, studentName, studentGrades, numGrades, nameList, avgList, numRecords );

    sortByAvg( avgList, avgTags, numRecords, nameList, avgOutFile );
    
    sortByName( nameList, nameTags, numRecords, avgList, nameOutFile );

    
    
    
    
    
    gradeDataFile.close();
    
    //cout << numRecords;
}

void sortByAvg( float avgList[], int avgTags[], int numRecords, char nameList[][25], ofstream& avgOutFile )
{
    bool madeSwap;
    int temp;
    madeSwap = true;

    while(madeSwap)
    {
        madeSwap = false;
        for( int i = 0; i <= numRecords; i++)
        {
            for( int j = i+1; j < numRecords-1; j++)
            {
                if(avgList[avgTags[i]] < avgList[avgTags[j]])
                {
                    temp = avgTags[i];
                    avgTags[i] = avgTags[j];
                    avgTags[j] = temp;
                    madeSwap = true;
                }
            }
        }
    }
    
    avgOutFile.open("byavg.txt");
    if( avgOutFile.fail() )
    {
        cout << "Error creating file: byavg.txt" << endl;
        exit( 1 );
    }
    for(int i = 0; i < numRecords-1; i++)
    {
        avgOutFile << nameList[avgTags[i]] << setw(6) << fixed << setprecision(2) << showpoint << avgList[avgTags[i]];
        if(i+1 < numRecords-1 )
            avgOutFile << '\n';
    }
    avgOutFile.close();
}

void sortByName( char nameList[][25], int nameTags[], int numRecords, float avgList[], ofstream& nameOutFile )
{
    bool madeSwap;
    int temp;
    madeSwap = true;

    while(madeSwap)
    {
        madeSwap = false;
        for( int i = 0; i <= numRecords; i++)
        {
            for( int j = i+1; j < numRecords-1; j++)
            {
                if( strcmp(nameList[nameTags[i]],nameList[nameTags[j]]) > 0)
                {
                    temp = nameTags[i];
                    nameTags[i] = nameTags[j];
                    nameTags[j] = temp;
                    madeSwap = true;
                }
            }
        }
    }
    nameOutFile.open("byname.txt");
    if( nameOutFile.fail() )
    {
        cout << "Error creating file: byname.txt" << endl;
        exit( 1 );
    }
    for(int i = 0; i < numRecords-1; i++)
    {
        nameOutFile << nameList[nameTags[i]] << setw(6) << fixed << setprecision(2) << showpoint << avgList[nameTags[i]];
        if(i+1 < numRecords-1 )
            nameOutFile << '\n';
    }
    nameOutFile.close();
}

void getFileName( char fileName[] )
{
    bool notValid = true;
    bool haveFileName = false;
    bool haveFileExtension = false;

    while(notValid)
    {   
        if(!haveFileName || !haveFileExtension)
        {
            cout << "Enter filename: ";
            cin.getline(fileName, FILENAME_SIZE, '\n');
            cout << endl;
            
            if(fileName[0] == '\0')
            {
                cout << "No filename provided." << endl;
                haveFileName = false;
            }
            else if(strstr(fileName, ".") == 0)
            {
                cout << "No file extension provided." << endl;
                haveFileExtension = false;
            }
            else
            {
                haveFileName = true;
                haveFileExtension = true;
            }
        }
        else
        {
            notValid = false;
        }
    }
}

void openDataFile( ifstream& gradeDataFile, char fileName[] )
{
    gradeDataFile.open( fileName );
    
    if( gradeDataFile.fail() )
    {
        cout << "Error opening file '" << fileName << "'." << endl;
        exit( 1 );
    }
}

void setGradeCount( ifstream& gradeDataFile, int& numGrades )
{
    gradeDataFile >> numGrades;
    gradeDataFile.get();
}

void initArrays( int studentGrades[], char nameList[][25], float avgList[], int nameTags[], int avgTags[] )
{
    for(int i=0; i < 100; i++)
    {
        studentGrades[i] = 0;
        nameList[i][0] = '\n';
        avgList[i] = 0.0;
        nameTags[i] = i;
        avgTags[i] = i;        
    }
}

void processDataFile( ifstream& gradeDataFile, char studentName[], int studentGrades[], int numGrades, char nameList[][25], float avgList[], int& numRecords )
{
    numRecords = 1;
    int n;
    n=0;
    while( gradeDataFile.peek() != EOF )
    {
        gradeDataFile.get( studentName, 25 );
        strcpy(nameList[n], studentName);
        
        for( int i = 0; i < numGrades; i++ )
            gradeDataFile >> studentGrades[i];
        
        avgList[n] = avgForRecord( studentGrades, numGrades );
        gradeDataFile.get();
        n++;
    }
    numRecords = numRecords + n;
}

float avgForRecord( int studentGrades[], int numGrades )
{
    float smallestGrade;
    float sum;
    
    smallestGrade = studentGrades[0];
    
    for( int i = 0; i < numGrades; i++ )
    {
        if( studentGrades[i] < smallestGrade )
            smallestGrade = studentGrades[i];
        
        sum = sum + studentGrades[i];
    }

    return ( sum - smallestGrade ) / ( numGrades - 1 );
}