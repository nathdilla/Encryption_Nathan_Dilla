// Encryption_Nathan_Dilla.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

/*
Write a C++ program that will ask the user to enter the shift value.
After the key is set, ask the user to enter words to be encrypted. 
Display each original word and encrypted word in tabular format.
All text should be displayed in lowercase. 
Hint:  Review the "Encryption Examples," for sample output and a copy of part of the ASCII table.
*/

#include <iostream>
#include <string>
using namespace std;
int main()
{
    int shift; //intialization of int shift, the key used to shift chars to encrypt strings
    string input; //initialization of string input, the string that is being encrypted, set by user input
    string res = "";

    cout << "Enter a string." << endl;
    getline(cin, input);//sets string to user input
    //cin >> input; 
    cout << "You entered: " << input << endl;

    cout << "Enter the shift key." << endl;
    cin >> shift; //sets shift key to user input
    cout << "You entered: " << shift << endl;

    shift = shift % 26; // makes sure it doesn't leave table bounds and only shifts between 1-26

    for (int i = 0; i < size(input); i++)
    {
        char character = input.at(i); // stores current character at index i
        if (isalpha(character))
        {
            if (character + shift > 122) // detects if next character is over z, loops back
            {
                shift = shift -26;
            }
            else if (character + shift < 97) // detects if next character is below a, loops forward.
            {
                shift = shift+ 26;
            }
            character = character + shift; //applies shift to character
            res = res + character; // concatenate character to result
        }
        else
        {
            res = res + " "; // adds white space to result
        }
    }

    cout << "Original String: " << input << endl;
    cout << "Encrypted String: " << res;

}