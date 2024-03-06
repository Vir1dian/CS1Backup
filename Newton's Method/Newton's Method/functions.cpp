#include <iostream>
#include <string>
#include <cctype>
#include <math.h>
using namespace std;

void format_term(string&);
float calculate_term(string term = "-12(x+15)^11", float x = 1);

int main() {
	string term1 = "(x+3)^0.5";
	format_term(term1);
	cout << term1 << endl;
	cout << calculate_term(term1);
	return 0;
}

void format_term(string& term) {
	// Removes f(x)=, whitespace, and capitalized variables
	string new_term;
	for (int i = 0; i < term.length(); i++) {
		if (term[i] == ' ') {
			continue;
		}
		new_term += tolower(term[i]);
	}
	term = new_term;
	new_term.clear();

	string coefficient;
	string constant;
	string exponent;
	int index_x = term.find('x');

	// Coefficient
	int end_of_coefficient;
	if (term.find('(') != string::npos)
		end_of_coefficient = term.find('(');
	else if (index_x != string::npos)
		end_of_coefficient = index_x;
	else
		end_of_coefficient = term.length();

	if (term.length() == 0) {
		coefficient = "+0";
		constant = "+0";
		exponent = "^0";
	}
	else if (term[0] == 'x' || term[0] == '(') {
		coefficient = "+1";
	}
	else if (term[0] == '-')
		if (term[1] == 'x' || term[1] == '(')
			coefficient = "-1";
		else
			coefficient = "-" + term.substr(1, end_of_coefficient - 1);
	else if (term[0] == '+')
		if (term[1] == 'x' || term[1] == '(')
			coefficient = "+1";
		else
			coefficient = "+" + term.substr(1, end_of_coefficient - 1);
	else {
		coefficient = "+" + term.substr(0, end_of_coefficient);
	}

	// Constant
	int end_of_constant = term.find(')');
	if (index_x == string::npos || index_x == term.length() - 1 || end_of_constant == string::npos)
		constant = "+0";
	else if (term[index_x + 1] == '-' || term[index_x + 1] == '+')
		constant = term.substr(index_x + 1, end_of_constant - (index_x + 1));

	// Exponent 
	if (index_x == string::npos)
		exponent = "^0";
	else if (term.find('^') == string::npos)
		exponent = "^1";
	else 
		exponent = term.substr(term.find('^'));

	// Formatted term
	term = coefficient + "(x" + constant + ")" + exponent;
}

float calculate_term(string term, float x) {
	float coefficient = stof(term.substr(0, term.find('(')));
	float constant = stof(term.substr(term.find('x') + 1, term.find(')') - (term.find('x') + 1)));
	float exponent = stof(term.substr(term.find('^') + 1));
	return coefficient * pow(x + constant, exponent);
}