// *******************************************************************************
// Assignment 5B: Falling Distance
// Author: Gavin Torrecampo
// Description: This program calls the function fallingDistance in a loop that
// passes the values 1-10. The function functionDistance takes in parameter t
// as time an object falls and returns the distance traveled by falling.
// Status: Complete
// Date: February 26, 2024
// *******************************************************************************
#include <iostream>
using namespace std;

float fallingDistance(int);

int main2() {
	for (int i = 1; i <= 10; i++)
		cout << fallingDistance(i) << endl;
	return 0;
}

float fallingDistance(int t) {
	return 0.5 * 9.8 * pow(t, 2);
}