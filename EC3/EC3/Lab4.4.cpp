// This program illustrates the use of the switch statement.
// GAVIN TORRECAMPO
#include <iostream>
using namespace std;
int main4()
{
	char grade;
	cout << "What grade did you earn in Programming I ?" << endl;
	cin >> grade;
	if (grade == 'A') cout << "an A - excellent work !" << endl;
	else if (grade == 'B') cout << "you got a B - good job" << endl;
	else if (grade == 'C') cout << "earning a C is satisfactory" << endl;
	else if (grade == 'D') cout << "while D is passing, there is a problem" << endl;
	else if (grade == 'F') cout << "you failed - better luck next time" << endl;
	else cout << "You did not enter an A, B, C, D, or F" << endl;
	return 0;
}
/*
Answers to exercise questions
Ex1: The trailing else statement serves to substitute the default
	 statement in the switch statement
*/