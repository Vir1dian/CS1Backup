// This program illustrates the use of logical operators
// GAVIN TORRECAMPO
#include <iostream>
using namespace std;
int main3()
{
	char year;
	float gpa;
	cout << "What year student are you ?" << endl;
	cout << "Enter 1 (freshman), 2 (sophomore), 3 (junior), or 4 (senior)" << endl << endl;
	cin >> year;
	cout << "Now enter your GPA" << endl;
	cin >> gpa;
	if (!(gpa < 2.0) && year == '4')
		cout << "It is time to graduate soon" << endl;
	else
		cout << "You need more schooling" << endl;
	return 0;
}
/*
Answers to exercise questions
Ex1: Replaced gpa >= 2.0 to !(gpa < 2.0)
Ex2: year != '4' cannot be replaced by < 4 or <= 3 unless year is converted
	 unless you use int(year), since year is a char variable.
Ex3: Any student who is either 4th year or with a 2.0 GPA or higher will
	 will graduate. After testing with a while loop, it seems to handle all cases.
Ex4: Else works the same way as the else if statement, and is more efficient.
*/