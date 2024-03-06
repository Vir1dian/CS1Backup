#include <iostream>
#include <string>
#include <cctype>
using namespace std;

/**
* This function reformats a single variable polynomial equation to explicitly
* show coefficients, constants, and exponents of each term. (Currently supports only single digits).
* @param reference: Polynomial equation as string, must be already formatted such that
* f(x)=..., terms do not have to be ordered by the highest power
*/
void format_polynomial(string&);

/**
 * This function calculates the output of a polynomial equation through recursion
 * @param poly: Polynomial equation as string, formatted by function format_polynomial
 * @param x: Float input value used to solve the equation.
 * @return: Float output of equation using the input
 */
float calculate_polynomial(string poly = "(x-3)^3-x^4+3(x+1)^2-2x+1", float x = 0);

string derivative(string);
float newtons_method(string, float, int);

int main1() {
	string poly_a;
	// cout << "Enter a function (such in terms of x such that f(x) = ...):\n";
	// while (poly.find("f(x)=") == string::npos) {
	//		cout << "Try again";
	//		getline(cin, poly);
	// }
	// getline(cin, poly);
	poly_a = "f(x)=(x-3)^3-x^4+3(x+1)^2-2x+1"; // placeholder equation
	cout << poly_a << endl;
	format_polynomial(poly_a);
	// cout << poly_a << endl;
	// newtons_method(poly_a);
	// calculate_polynomial(poly_a);
	cout << poly_a << endl;
	return 0;
}


void format_polynomial(string &poly) {
	string new_poly;

	// Removes f(x)=, whitespace, and capitalized variables
	for (int i = 5; i < poly.length(); i++) {
		if (poly[i] == ' ') {
			continue;
		}
		new_poly += tolower(poly[i]);
	}
	poly = new_poly;
	new_poly.clear();

	// Reformat terms to include coefficients, constants, and terms
	string term;
	int index_x = poly.find('x');
	while (index_x != string::npos) {
		// Reformat coefficient 
		if (index_x == 0) {
			term += "+1(x";
		}
		else {
			if (poly[index_x - 1] == '-')
				term += "-1(x";
			else if (poly[index_x - 1] == '+')
				term += "+1(x";
			else if (poly[index_x - 1] == '(') {
				if (index_x - 1 == 0) {
					term += "+1(x";
				}
				else {
					if (poly[index_x - 2] == '-')
						term += "-1(x";
					else if (poly[index_x - 2] == '+')
						term += "+1(x";
					else {
						if (index_x - 2 == 0)
							term += '+';
						else {
							if (poly[index_x - 3] == '-')
								term += '-';
							else if (poly[index_x - 3] == '+')
								term += '+';
						}
						term += poly[index_x - 2];
						term += "(x";
					}
				}
			}
			else { // if already a coefficent
				if (index_x - 1 == 0)
					term += '+';
				else {
					if (poly[index_x - 2] == '-')
						term += '-';
					else if (poly[index_x - 2] == '+')
						term += '+';
				}
				term += poly[index_x - 1];
				term += "(x";
			}
		}

		// Reformat constant
		if (index_x + 1 < poly.length()) {
			if (poly[index_x + 1] == '-') {
				term += '-';
				term += poly[index_x + 2];
				term += ')';
			}
			else if (poly[index_x + 1] == '+') {
				term += '+';
				term += poly[index_x + 2];
				term += ')';
			}
			else
				term += "+0)";
		}

		new_poly += term;
		term.clear();
		index_x = poly.find('x', index_x + 1);
	}
	poly = new_poly;
}


float calculate_polynomial(string poly, float x) {
	string new_poly;
	float f_of_x = 0;

	bool is_in_parenthesis = false;

	// remember to fix this for loop from int i = 5 to int i = 0
	for (int i = 0; i < poly.length(); i++) {
		// Splitting up equation into smaller parts (this is the part where using recursion)
		// Checking for parenthesis
		if (poly[i] == ')') {
			is_in_parenthesis = false;
			// f_of_x += calculate_polynomial(new_poly, x);
			new_poly.clear();
		}
		if (is_in_parenthesis)
			new_poly += poly[i];
		if (poly[i] == '(')
			is_in_parenthesis = true;

		// Actual calculation
		// if (poly[i] == 'x')

	}
	return f_of_x;
}

string derivative(string poly) {
	for (int i = 0; i < poly.length(); i++) {
		break;
	}
	return poly;
}

float newtons_method(string poly, float x0, int reps) {
	return 0;
}