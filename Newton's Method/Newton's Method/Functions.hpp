#pragma once
#include <iostream>
#include <string>
#include <cctype>
#include <math.h>
#include <cmath>
using namespace std;

/**
 * This function reformats a single-variable polynomial TERM to explicitly
 * show coefficients, constants, and exponents of each term.
 * @param reference: Polynomial TERM as string, must be already formatted such that
 * x is before the constant, and coefficients and exponents are either applied directly
 * to x or on a parenthesis if a constant is present.
 */
void format_term(string&);

/**
 * This function calculates the output of a polynomial TERM
 * @param poly: Polynomial TERM as string, should have formatting according to 
 * format_term() or format_polynomial()
 * @param x: Float input value used to solve the TERM.
 * @return: Float output of TERM using the input
 */
float calculate_term(string, float);

/**
 * This function reformats a single-variable polynomial EQUATION to explicitly
 * show coefficients, constants, and exponents of each term.
 * @param reference: Polynomial EQUATION as string, must be already formatted such that
 * x--if applicable--is before the constant, and coefficients and exponents are either 
 * applied directly to x or on a parenthesis if a constant is present. Terms do not
 * have to be ordered by the highest power.
 */
void format_polynomial(string&);

/**
 * This function calculates the output of a polynomial equation
 * @param poly: Polynomial equation as string, must be already formatted such that
 * x--if applicable--is before the constant, and coefficients and exponents are either 
 * applied directly to x or on a parenthesis if a constant is present. Terms do not
 * have to be ordered by the highest power.
 * @param x: Float input value used to solve the equation.
 * @return: Float output of equation using the input
 */
float calculate_polynomial(string, float);

/**
 * This function calculates the derivative of a polynomial TERM using the power rule
 * @param term: Polynomial TERM as string, must be already formatted such that
 * x--if applicable--is before the constant, and coefficients and exponents are either 
 * applied directly to x or on a parenthesis if a constant is present. Terms do not
 * have to be ordered by the highest power.
 * @return: Polynomial TERM as string
 */
string derivative_power_rule(string);

/**
 * This function calculates the derivative of a POLYNOMIAL EQUATION using the POWER RULE ONLY
 * @param poly: Polynomial equation as string, must be already formatted such that
 * x--if applicable--is before the constant, and coefficients and exponents are either
 * applied directly to x or on a parenthesis if a constant is present. Terms do not
 * have to be ordered by the highest power.
 * @return: Polynomial derivative as string
 */
string derivative(string);
float newtons_method(string, float, int);