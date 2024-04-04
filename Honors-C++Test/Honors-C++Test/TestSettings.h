#pragma once
#include <iomanip>
using namespace std;

/**
 * This function displays a menu which allows the user to set the size of the test, 
 * difficulty of questions, and categories involved. 
 * @param int: Size of test (1-40)
 * @param int: Difficulty of test (1-3)
 * @param string[]: Categories of test questions
 * @param string[]: Types of test questions
 * @return: none
 */
void set_settings(int&, int&, string[], string[]);

/**
 * This function displays the test settings selected by the user
 * in a formatted manner.
 * @param int: Size of test (1-40)
 * @param int: Difficulty of test (1-3)
 * @param string[]: Categories of test questions
 * @param string[]: Types of test questions
 * @return: none
 */
void show_settings(int&, int&, string[], string[]);

// If the questions in the filtered pool is less than the size of the test, then other random questions are used to fill the empty space.