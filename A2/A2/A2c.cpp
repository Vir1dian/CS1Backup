// *******************************************************************************
// Assignment 2C: Math Tutor
// Author: Gavin Torrecampo
// Description: This program randomly generates math problems (addition) that 
// provides the answer after the user presses enter.
// Status: Complete
// Date: January 31, 2024
// ********************************************************************************
#include<iostream>
#include<iomanip>
#include<cstdlib>
#include<ctime>
using namespace std;

int main() {
	const int MIN = 10;
	const int MAX = 1000;
	unsigned long seed = time(0);
	srand(seed);
	int num1 = MIN + rand() % MAX;
	int num2 = MIN + rand() % MAX;
	cout << setw(6) << num1 << endl;
	cout << "+" << setw(5) << num2 << endl;
	cout << "______\n\nPress enter to see the answer . . .\n";
	cin.get();
	cout << setw(6) << num1 << endl;
	cout << "+" << setw(5) << num2 << endl;
	cout << "______\n";
	cout << setw(6) << num1 + num2 << endl;
	return 0;
}