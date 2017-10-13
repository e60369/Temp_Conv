// EGR 126 ELI Fall 2017
//----------------------------------------------------------------------------
// Student Name : Rich MURPHY
// Assignment : Assignment #6
// Submission Date: 10/14/17
// Compiler Info : MacOS, Xcode
// Purpose : This program reads/writes to/from data files and converts temperature
// data from C to F and F to C based on the users input.
//
// Note: Xcode does not support the system ("CLS") command or any of the variations on
// this from one of the many available libraries. This is due to the window that displays
// the output apparently not being a true terminal window.
//
// As a workaround, I have made my own clear screen command which inserts 10 "\n" commands
// where the system ("CLS") command would have otherwise have gone in order to simulate a clean new screen.
//----------------------------------------------------------------------------

#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

void clr_scrn()
{
    for (int i = 1; i < 11; i++)
        cout << "\n" << endl;
}

int myc2f () //This is the celsius to farenheit conversion function.
{
    ifstream celsius("data_Celsius.txt");
    ofstream fahrenheit("MURPHY_Fahrenheit.txt");
    
    cout <<"Celsius to Fahrenheit Process is Initiated" << endl;
    clr_scrn();
    
    int i = 0, degrees;
    
        while (celsius >> degrees)
        {
            i++;
            fahrenheit <<roundf(((degrees+32)*(9.0/5.0))*1)/1 << endl; // It is necessary to round the results to maintain the same level of precision as the input data.
        }
    
    celsius.close();
    fahrenheit.close();
    
    cout << "Celsius to Fahrenheit Process is Completed." <<endl;
    cout << "----------------------" << endl;
    cout << "Option 2. Convert Farenheit to Celsius" << endl;
    cout << "Option 3. Exit " << endl;
    cout << "----------------------" << endl;
    
    return 0;
}

int myf2c () //This is the farenheit to celsius conversion function.
{
    ifstream fahrenheit("data_Fahrenheit.txt");
    ofstream celsius("MURPHY_Celsius.txt");
    
    cout << "Fahrenheit to Celsius Process is Initiated" << endl;
    clr_scrn();
    
    int i = 0, degrees;
    
            while (fahrenheit >> degrees)
            {
                i++;
                celsius << roundf(((degrees-32)*(5.0/9.0))*1)/1 << endl; // It is necessary to round the results to maintain the same level of precision as the input data.
            }
    
        fahrenheit.close();
        celsius.close();
    
    cout << "Fahrenheit to Celsius Process is Completed." << endl;
    cout << "----------------------" << endl;
    cout << "Option 1. Convert Celsius to Farenheit" << endl;
    cout << "Option 3. Exit " << endl;
    cout << "----------------------" << endl;
    
return 0;
}

void mymenu () //This is the main menu which greets the user.
{
    cout << "----------------------" << endl;
    cout << "Rich MURPHY" << endl;
    cout << "Solution for Assignment #6" << endl;
    cout << "----------------------" << endl;
    cout << "Option 1. Convert Celsius to Farenheit" << endl;
    cout << "Option 2. Convert Farenheit to Celsius" << endl;
    cout << "Option 3. Exit " << endl;
    cout << "----------------------" << endl;
}

int main () // Our main program just consists of a simple do-while loop utilizing the functions we created.
{
    int sel;

        mymenu ();
    do
    {
        cout << "Please make a selection from the menu above: ";
        cin >> sel;
        
        if (sel == 1)
            myc2f ();
        
        else if (sel == 2)
            myf2c ();
        
        else if (sel == 3)
            cout << "------------------------\nEnd of Assignment #6\n------------------------" << endl;
        
        else if (sel != 3)
            cout << "Error! Choose only from the available menu options." << endl;
    } while (sel != 3);
    
return 0;
}
