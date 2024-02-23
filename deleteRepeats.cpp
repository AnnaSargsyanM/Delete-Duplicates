//****************************************************************************************************
//     File:               deleteRepeats.cpp
// 
//     Student:            Anna Sargsyan
// 
//     Assignment:         Program #12
// 
//     Course Name:        Programming I
// 
//     Course Number:      COSC 1550-01
// 
//     Due:                April 21, 2023
//
//     This program asks user to input the size of the characters, 
//     then asks user to input characters. After it the program should find and 
//     delete repeated entries in a character array.
//
//****************************************************************************************************

#include <iostream>

const int SIZE = 20;

using namespace std;

//****************************************************************************************************

int main()
{
    int used;
    
    char arr[SIZE];

    cout << "Enter the size of the array: ";
    cin >> used;

    cout << "Enter " << used << " characters: ";
    for (int i = 0; i < used; i++) 
    {
        cin >> arr[i];
    }


    for (int i = 0; i < used; i++)
    {
        bool isDuplicate = false;
        for (int j = i + 1; j < used; j++)
        {
            if (arr[i] == arr[j])
            {
                isDuplicate = true;
                for (int k = j; k < used - 1; k++)
                {
                    arr[k] = arr[k + 1];
                }
                used--;
                j--;
            }
        }
        if (isDuplicate)
        {
            cout << "found duplicates at " << i + 1 << " and ";
            for (int j = i + 2; j < used; j++)
            {
                if (arr[i] == arr[j])
                {
                    cout << j + 1 << " : " << arr[i] << " and ";
                }
            }
            cout << i + 1 << " : " << arr[i] << endl;
            cout << "Updated array: ";
            for (int j = 0; j < used; j++)
            {
                cout << arr[j] << " ";
            }
            cout << endl;
            i--;
        }
    }

    cout << "The array after delete repeats \n";
    for (int j = 0; j < used; j++)
    {
        cout << arr[j] << " ";
    }
    cout << endl;

    char answer;

    cout << "Repeat? (Y/N)" << endl;
    cin >> answer;

    if (answer == 'Y' || answer == 'y')
    {
        cout << "The array after delete repeats \n";
        for (int j = 0; j < used; j++)
        {
            cout << arr[j] << " ";
        }
        cout << endl;

        char answer;

        cout << "Repeat? (Y/N)" << endl;
        cin >> answer;

        if (answer == 'N' || answer == 'n')
        {
            cout << "Exiting program..." << endl;
        }
        else
        {
            cout << "Invalid input." << endl;
        }
    }
    else if (answer == 'N' || answer == 'n')
    {
        cout << "Exiting program..." << endl;
    }
    else
    {
        cout << "Invalid input." << endl;
    }



    return 0;
}

 
