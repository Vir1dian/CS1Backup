// This program prints "You Pass" if a student's average is
// 60 or higher and prints "You Fail" otherwise
// GAVIN TORRECAMPO
#include <iostream>
using namespace std;
int main2()
{
	float average; // holds the grade average
	cout << "Input your average:" << endl;
	cin >> average;
	if (average > 100)
		cout << "Invalid data" << endl;
	else if (average >= 90)
		cout << "A" << endl;
	else if (average >= 80)
		cout << "B" << endl;
	else if (average >= 60)
		cout << "You Pass" << endl;
	else
		cout << "You Fail" << endl;
	return 0;
}
/*
Answers to exercise questions
Ex1: Entering 60 as the average initially prints nothing
Ex3: Entering -12 prints "You Fail" since it is less than 60
*/