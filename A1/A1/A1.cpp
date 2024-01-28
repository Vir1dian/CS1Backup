#include <iostream>
using namespace std;
// *******************************************************************************
// Assignment 1A: Fortune Teller Program
// Author: Gavin Torrecampo
// Description: This program prompts the user for their age, calculates how
// old the user would be in a year, and displays it on the screen
// Status: Complete
// Date: January 22, 2024
// ********************************************************************************
void partA() {
	int age;
	int new_age;
	cout << "Please enter your age::: ";
	cin >> age;
	new_age = age + 1;
	cout << "Next year you will be " << new_age << " old.\n";
	cout << "Thank you for using my program!" << endl;
}
// *******************************************************************************
// Assignment 1B: Average of Values
// Author: Gavin Torrecampo
// Description: This program calculates the average of five numbers
// Status: Complete
// Date: January 22, 2024
// ********************************************************************************
void partB() {
	double a = 28, b = 32, c = 37, d = 24, e = 33;
	double sum = a + b + c + d + e;
	cout << "Sum: " << sum << endl;
	cout << "Average: " << sum / 5 << endl;
}
// *******************************************************************************
// Assignment 1C: Cyborg Data Type Sizes
// Author: Gavin Torrecampo
// Description: This program determines the amount of memory used by 4 data types
// Status: Complete
// Date: January 22, 2024
// ********************************************************************************
void partC() {
	cout << "The size of 'char' in bytes: " << sizeof(char) << endl;
	cout << "The size of 'int' in bytes: " << sizeof(int) << endl;
	cout << "The size of 'float' in bytes: " << sizeof(float) << endl;
	cout << "The size of 'double' in bytes: " << sizeof(double) << endl;
}
// Runs all parts of the homework in a sequence starting from part A
int main() {
	partA();
	partB();
	partC();
}