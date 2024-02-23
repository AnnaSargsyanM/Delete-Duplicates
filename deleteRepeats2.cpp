//****************************************************************************************************
//     File:               deleteRepeats2.cpp
// 
//     Student:            Anna Sargsyan
// 
//     Assignment:         Program #13
// 
//     Course Name:        Programming I
// 
//     Course Number:      COSC 1550-01
// 
//     Due:                April 28, 2023
//
//     This program asks user to input the size of the characters, 
//     then asks user to input characters. After it the program should find and 
//     delete repeated entries in a character array.
//
//****************************************************************************************************

#include <iostream>
#include <string>

const int SIZE = 20;

void readArray(char[], int &);
void deleteRepeats(char[], int &);
void printArray(char[], int);
void repeatProcess(char[], int, char &);

using namespace std;

//****************************************************************************************************

int main()
{
    int  used = 0;
    char elements[SIZE],
         answer;

    readArray(elements, used);
    deleteRepeats(elements, used);
    printArray(elements, used);
    repeatProcess(elements, used, answer);

    return 0;
}

//****************************************************************************************************

void readArray(char elements[], int & used)
{
    cout << "Enter the size of the array: ";
    cin >> used;

    cout << "Enter " << used << " characters: ";
    for (int i = 0; i < used; i++)
    {
        cin >> elements[i];
    }
    cout << endl;
}

//****************************************************************************************************

void deleteRepeats(char elements[], int& used)
{
    for (int i = 0; i < used - 1; i++)
    {
        
        for (int j = i + 1; j < used - 1; j++)
        {
            if (elements[i] == elements[j])
            {
                cout << "found duplicates at: " << i + 1 << " and ";
                for (int k = j; k < used; k++)
                {
                    elements[k] = elements[k + 1];
                }
                cout << i + 2 << " : " << elements[i] 
                    << " and " << elements[i] << endl;
                used--;
                j--;

                cout << "Updated array: ";
                    for (int j = 0; j < used - 1; j++)
                        {
                            cout << elements[j] << " ";
                        }
                    cout << "\n" << endl;
            }
        }  
    }
}


//****************************************************************************************************

void printArray(char elements[], int used)
{
    cout << "The array after delete repeats:";
    for (int j = 0; j < used - 1; j++)
    {
        cout << elements[j] << " ";
    }
    cout << endl;

}

//****************************************************************************************************
 
void repeatProcess(char elements[], int used, char & answer)
{  
    cout << "Repeat? (Y/N)" << endl;
    cin >> answer;

    if (answer == 'Y' || answer == 'y')
    {
        readArray(elements, used);
        deleteRepeats(elements, used);
        printArray(elements, used);
        repeatProcess(elements, used, answer);
    }
    else if (answer == 'N' || answer == 'n')
    {
        cout << "Exiting program..." << endl;
    }
    else
    {
        cout << "Invalid input." << endl;
        repeatProcess(elements, used, answer);
    }
}

//****************************************************************************************************

/*

Enter the size of the array: 10
Enter 10 characters: a g g g e n g g e e

found duplicates at: 2 and 3 : g and g
Updated array: a g g e n g g e e

found duplicates at: 2 and 3 : g and g
Updated array: a g e n g g e e

found duplicates at: 2 and 3 : g and g
Updated array: a g e n g e e

found duplicates at: 2 and 3 : g and g
Updated array: a g e n e e

found duplicates at: 3 and 4 : e and e
Updated array: a g e n e

found duplicates at: 3 and 4 : e and e
Updated array: a g e n

The array after delete repeats:a g e n
Repeat? (Y/N)
Y
Enter the size of the array: 10
Enter 10 characters: a g e n g g e e h h

found duplicates at: 2 and 3 : g and g
Updated array: a g e n g e e h h

found duplicates at: 2 and 3 : g and g
Updated array: a g e n e e h h

found duplicates at: 3 and 4 : e and e
Updated array: a g e n e h h

found duplicates at: 3 and 4 : e and e
Updated array: a g e n h h

found duplicates at: 5 and 6 : h and h
Updated array: a g e n h

The array after delete repeats:a g e n h
Repeat? (Y/N)
N
Exiting program...

*/