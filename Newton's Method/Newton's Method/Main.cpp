#include <iostream>
#include <string>
#include <cctype>
#include <math.h>
#include <cmath>
#include "Functions.hpp"
using namespace std;

int main() {
	string poly_a = "-(x-2)^5 + 1"; // Placeholder equation
	float x = 3.44;
	// cout << "Enter a function in terms of x:\n";
	// getline(cin, poly);
	cout << "f(x) = " << poly_a << endl;
	cout << "f(" << x << ") = " << calculate_polynomial(poly_a, x) << endl;
	cout << "f'(x) = " << derivative(poly_a) << endl;
	cout << "f'(" << x << ") = " << calculate_polynomial(derivative(poly_a), x) << endl;
	cout << x - (calculate_polynomial(poly_a, x) / calculate_polynomial(derivative(poly_a), x));
	return 0;
}

