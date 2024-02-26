// *******************************************************************************
// Assignment 4B: Math Tutor (Modified II)
// Author: Gavin Torrecampo
// Description: This program provides a menu for the user to select a math problem
// (addition, subtraction, multiplication, division) and randomly generates it. 
// Menu will reappear and process will repeat once the user types an answer. User 
// may also choose to quit the program. 
// Status: Complete
// Date: February 12, 2024
// ********************************************************************************
#include<iostream>
#include<iomanip>
#include<cstdlib>
#include<ctime>
#include<cmath>
using namespace std;

int main2() {
	const float epsilon = 0.01;
	const int MIN = 1;
	const int MAX = 50;
	unsigned long seed = time(0);
	srand(seed);

	int input = 1;
	while (input != 5) {
		cout << "\nMath Tutor - Select a math problem:\n";
		cout << "1. Addition\n";
		cout << "2. Subtraction\n";
		cout << "3. Multiplication\n";
		cout << "4. Division\n";
		cout << "5. Quit\n";
		cout << "Enter your choice (1-5) . . .\n";
		cin >> input;
		int num1 = MIN + rand() % MAX;
		int num2 = MIN + rand() % MAX;
		float attempt;
		switch (input) {
		case 1:
			cout << "\nYou have selected: Addition\n";
			cout << setw(6) << num1 << endl;
			cout << "+" << setw(5) << num2 << endl;
			cout << "______\n\nEnter your answer . . .\n";
			cin >> attempt;
			if (attempt == num1 + num2)
				cout << attempt << " is correct. Well done!\n";
			else
				cout << attempt << " is incorrect. The correct answer is: " << num1 + num2 << endl;
			break;
		case 2:
			cout << "\nYou have selected: Subtraction\n";
			cout << setw(6) << num1 << endl;
			cout << "-" << setw(5) << num2 << endl;
			cout << "______\n\nEnter your answer . . .\n";
			cin >> attempt;
			if (attempt == num1 - num2)
				cout << attempt << " is correct. Well done!\n";
			else
				cout << attempt << " is incorrect. The correct answer is: " << num1 - num2 << endl;
			break;
		case 3:
			cout << "\nYou have selected: Multiplication\n";
			cout << setw(6) << num1 << endl;
			cout << "*" << setw(5) << num2 << endl;
			cout << "______\n\nEnter your answer . . .\n";
			cin >> attempt;
			if (attempt == num1 * num2)
				cout << attempt << " is correct. Well done!\n";
			else
				cout << attempt << " is incorrect. The correct answer is: " << num1 * num2 << endl;
			break;
		case 4:
			// See note on float comparisons for division
			cout << "\nYou have selected: Division\n";
			cout << setw(6) << num1 << endl;
			cout << "/" << setw(5) << num2 << endl;
			cout << "______\n\nEnter your answer . . .\n";
			cin >> attempt;
			if (fabs(attempt - float(num1) / num2) < epsilon)
				cout << attempt << " is correct. Well done!\n";
			else
				cout << attempt << " is incorrect. The correct answer is: " << setprecision(2) << fixed << float(num1) / num2 << endl;
			break;
		case 5:
			cout << "\nYou have exited from Math Tutor.\n";
			break;
		default:
			cout << "\nInvalid number (must be 1-5). Try again.\n";
			break;
		}

	}
	return 0;
}
