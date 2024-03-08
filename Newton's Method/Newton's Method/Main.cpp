#include <iostream>
#include <string>
#include <cctype>
#include <math.h>
#include "Functions.hpp"
using namespace std;

int main() {
	string poly_a;
	float input;
	// cout << "Enter a function (such in terms of x such that f(x) = ...):\n";
	// while (poly.find("f(x)=") == string::npos) {
	//		cout << "Try again";
	//		getline(cin, poly);
	// }
	// getline(cin, poly);
	poly_a = "f(x)=-x^5-4x^4+0.5(x-3)^3+2(x-0.75^2)+44"; // placeholder equation
	input = 5;
	format_polynomial(poly_a);
	cout << poly_a << endl << endl;
	cout << "f(" << input << ")=" << calculate_polynomial(poly_a, input);
	// cout << calculate_term("-13(x-2)^2", -1) << endl;
	return 0;
}

