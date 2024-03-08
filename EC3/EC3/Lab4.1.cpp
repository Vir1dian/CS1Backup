// This program tests whether or not an initialized value
// is equal to a value input by the user
// GAVIN TORRECAMPO
#include <iostream>
using namespace std;
int main1()
{
	int num1, num2;
	cout << "Please enter an integer" << endl;
	cin >> num1;
	cout << "Please enter another integer" << endl;
	cin >> num2;
	if (num1 == num2) {
		cout << "The values are the same." << endl;
		cout << "Hey, that's a coincidence!" << endl;
	}
	else {
		cout << "num1 = " << num1 << " and num2 = " << num2 << endl;
		cout << "The values are not the same" << endl;
	}
	return 0;
}
/*
Answers to exercise questions
Ex1: Initially, "Hey, that's a coincidence is always printed because
	 num1 = num2 is seen read as true, this has been fixed to
	 num1 == num2
*/