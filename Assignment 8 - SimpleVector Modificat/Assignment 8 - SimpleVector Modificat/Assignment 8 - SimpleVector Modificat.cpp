// Assignment 8 - SimpleVector Modificat.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "SimpleVector.h"
using namespace std;

int main()
{
	SimpleVector<int> intTable(10);
	SimpleVector<double> doubleTable(10);
	int i;
	int x;
	double y;
	char again = 'y';
	// initiate a 'while' loop that allows users to repeat the function.
	do{
		// Store values.
		for (i=0;i<10;i++)
		{
			intTable[i] = i;
			doubleTable[i] = (i+.5);
		}

		// Display values
		cout << "The values in intTable are:\n";
		for (i=0;i<intTable.size(); i++)
			cout << intTable[i] << " ";
		cout << endl;
		cout << "These values are in doubleTable:\n";
		for (i = 0; i < doubleTable.size(); i++)
			cout << doubleTable[i] << " ";
		cout << "\n";
		system("pause");
		// Ask the user for variables to tests the "Push Back" function.
		cout << "We will now test the \"Push Back\" function. \nPlease enter an integer value: ";
		cin >> x;
		cout << "\nNow enter a 'double' value (a number with a decimal point): ";
		cin.ignore();
		cin >> y;
		cin.ignore();
		// Use accepted values for "Push Back".
		intTable.push_back(x);
		doubleTable.push_back(y);
		// Display values
		cout << "The values in intTable are:\n";
		for (i=0;i<intTable.size(); i++)
			cout << intTable[i] << " ";
		cout << endl;
		cout << "These values are in doubleTable:\n";
		for (i = 0; i < doubleTable.size(); i++)
			cout << doubleTable[i] << " ";
		cout << "\n";
		system("pause");
		// Use pop_back function.
		cout << "We will now be testing the \"Pop Back\" function.\n";
		system("pause");
		try
		{
			cout << "\nPopping " << intTable.pop_back() << " from the integer table.\n";
		}
		catch (char *exceptionString)
		{
			cout << exceptionString;
		}

		try
		{
			cout << "\nPopping " << doubleTable.pop_back() << " from the double table.\n";
		}
		catch (char *exceptionString)
		{
			cout << exceptionString;
		}
		// Display values
		cout << "The values in intTable are:\n";
		for (i=0;i<intTable.size(); i++)
			cout << intTable[i] << " ";
		cout << endl;
		cout << "These values are in doubleTable:\n";
		for (i = 0; i < doubleTable.size(); i++)
			cout << doubleTable[i] << " ";
		cout << "\n";
		system("pause");
		// Query the user to see if they would like to repeat the program. 
		cout << "\n\nWell, that was fun.\nWould you like to run the program again? (enter 'y' for 'yes' and any other input for 'no')\n\n>>>>>>   ";
		cin >> again;
		// Clear the console if they wish to repeat the program. 
		if (tolower(again) == 'y')
			system("cls");
	// Close the while loop. 
	}while(tolower(again)=='y');

	return 0;
}

