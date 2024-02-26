// *******************************************************************************
// Assignment 2B: Math Tutor (Modified)
// Author: Gavin Torrecampo
// Description: This program randomly generates math problems (addition), asking for the users
// answer, then gives feedback (congrats if correct, show answer if incorrect).
// Date: February 6, 2024
// ********************************************************************************
#include<iostream>
#include<iomanip>
#include<cstdlib>
#include<ctime>
using namespace std;

int main2() {
	const int MIN = 50;
	const int MAX = 999;
	unsigned long seed = time(0);
	srand(seed);
	int num1 = MIN + rand() % MAX;
	int num2 = MIN + rand() % MAX;
	int attempt;
	cout << setw(6) << num1 << endl;
	cout << "+" << setw(5) << num2 << endl;
	cout << "______\n\nEnter your answer . . .\n";
	cin >> attempt;
	if (attempt == num1 + num2)
		cout << attempt << " is correct. Well done!";
	else
		cout << attempt << " is incorrect. The correct answer is: " << num1 + num2;
	return 0;
}
