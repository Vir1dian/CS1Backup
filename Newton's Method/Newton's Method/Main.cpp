#include <iostream>
#include <string>
#include <cctype>
#include <math.h>
#include <cmath>
#include "Functions.hpp"
using namespace std;

int main() {
	string poly_a = "x^-4 - 3x^-2 + 2x^-3 - 5x^0 + 4x^1"; // Placeholders
	float x = 1.15;
	int reps = 5;
	cout << "Enter a function in terms of x (omit f(x)=, y=, etc)\nExample is x^-4 - 3x^-2 + 2x^-3 - 5x^0 + 4x^1\n. . .";
	getline(cin, poly_a);
	cout << "Enter a starting value for function x:\n";
	cin >> x;
	cout << "Enter number of iterations for x:\n";
	cin >> reps;
	cout << newtons_method(poly_a, x, reps);
	return 0;
}

