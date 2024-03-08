#include <iostream>
#include <string>
#include <cctype>
#include <cmath>
#include <math.h>
#include "Functions.hpp"
using namespace std;

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
	format_term(term);
	float coefficient = stof(term.substr(0, term.find('(')));
	float constant = stof(term.substr(term.find('x') + 1, term.find(')') - (term.find('x') + 1)));
	float exponent = stof(term.substr(term.find('^') + 1));
	return coefficient * pow(x + constant, exponent);
}

void format_polynomial(string& poly) {
	poly += ' '; // band aid fix for parsing issue at end of string
	string new_poly;
	string term;
	bool is_in_parenthesis = false;

	// Splitting up all terms and formatting them with format_term()
	for (int i = 0; i < poly.length(); i++) {
		if (poly[i] == '(')
			is_in_parenthesis = true;
		if (poly[i] == ')')
			is_in_parenthesis = false;
		if ((poly[i] == '+' || poly[i] == '-' || i == poly.length() - 1) && !is_in_parenthesis && i != 0) {
			if (poly[i-1] != '^') {
				format_term(term);
				new_poly += term;
				term.clear();
			}
		}
		term += poly[i];
	}
	poly = new_poly;
}


float calculate_polynomial(string poly, float x) {
	format_polynomial(poly);
	float f_of_x = 0;
	poly += ' '; // band aid fix for parsing issue at end of string
	string term;
	bool is_in_parenthesis = false;

	// Splitting up all terms by finding + and - that are not associated
	// inside a set of parenthesis OR is used for the exponents
	// and solving with calculate_term() individually
	for (int i = 0; i < poly.length(); i++) {
		if (poly[i] == '(')
			is_in_parenthesis = true;
		if (poly[i] == ')')
			is_in_parenthesis = false;
		if ((poly[i] == '+' || poly[i] == '-' || i == poly.length() - 1) && !is_in_parenthesis && i != 0) {
			if (poly[i - 1] != '^') { 
				f_of_x += calculate_term(term, x);
				// cout << term << endl << calculate_term(term, x) << endl;
				term.clear();
			}
		}
		term += poly[i];
	}
	return f_of_x;
}

string derivative_power_rule(string term) {
	string new_term = term;
	format_term(new_term);
	float coefficient = stof(new_term.substr(0, new_term.find('(')));
	float constant = stof(new_term.substr(new_term.find('x') + 1, new_term.find(')') - (new_term.find('x') + 1)));
	float exponent = stof(new_term.substr(new_term.find('^') + 1));
	coefficient *= exponent;
	exponent--;
	string sign_of_coefficient = coefficient >= 0 ? "+" : "";
	string sign_of_constant = constant >= 0 ? "+" : "";
	return sign_of_coefficient + to_string(coefficient) + "(x" + sign_of_constant + to_string(constant) + ")^" + to_string(exponent);
}

string derivative(string poly) {
	poly += ' ';
	string new_poly;
	string term;
	bool is_in_parenthesis = false;

	// Splitting up all terms and formatting them with format_term(), then applying power rule
	for (int i = 0; i < poly.length(); i++) {
		if (poly[i] == '(')
			is_in_parenthesis = true;
		if (poly[i] == ')')
			is_in_parenthesis = false;
		if ((poly[i] == '+' || poly[i] == '-' || i == poly.length() - 1) && !is_in_parenthesis && i != 0) {
			if (poly[i - 1] != '^') {
				format_term(term);
				new_poly += derivative_power_rule(term);
				term.clear();
			}
		}
		term += poly[i];
	}
	return new_poly;
}

float newtons_method(string poly, float xn, int reps) {
	if (reps > 0) {
		float xn1 = xn - (calculate_polynomial(poly, xn) / calculate_polynomial(derivative(poly), xn));
		return newtons_method(poly, xn1, reps - 1);
	}
	else {
		return xn - (calculate_polynomial(poly, xn) / calculate_polynomial(derivative(poly), xn));
	}
}