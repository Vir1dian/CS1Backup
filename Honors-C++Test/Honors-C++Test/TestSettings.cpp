#include <iostream>
#include <iomanip>
#include "TestSettings.h"
using namespace std;

const int NUM_CATEGORY = 11, NUM_TYPE = 5;
int categories_length, types_length;
const string all_categories[NUM_CATEGORY] =
{ "Introduction/Other", "Making Decisions", "Loops", "Files",
  "Binary/Hexadecimal", "Functions", "Arrays", "Text Files",
  "C Strings/String", "Structures", "Binary Files" };
const string all_types[NUM_TYPE] = { "Conceptual", "Debugging", "Comparison", "FIB", "TOF" };

void set_settings(int& test_size, int& difficulty, string categories[], string types[]) {
	int select_cat, select_type; // Temp values used to add selected items to arrays
	bool stop_select_cat = false, stop_select_type = false; // Flags to end while loops
	categories_length = 0, types_length = 0;

	cout << "\n# Select test size(1-40): ";
	cin >> test_size;
	while (test_size < 1 || test_size > 40) {
		cout << "(!) Invalid number, pick again...";
		cin >> test_size;
	}

	cout << "\n# Select difficulty (1 easy, 2 moderate, 3 challenging): ";
	cin >> difficulty;
	while (difficulty < 1 || difficulty > 3) {
		cout << "(!) Invalid number, pick again...";
		cin >> difficulty;
	}

	cout << "\n# Select categories . . . \n";
	for (int i = 0; i < NUM_CATEGORY; i++) {
		cout << i + 1 << " : " << all_categories[i] << endl;
	}
	cout << "12 : * End Selection (All Categories if nothing is selected) *\n\n";

	while (!stop_select_cat) {
		cin >> select_cat;
		if (select_cat > 0 && select_cat <= NUM_CATEGORY) {
			for (int i = 0; i < NUM_CATEGORY; i++) {
				if (i == select_cat - 1)
					categories[categories_length++] = all_categories[i];
			}
		} 
		else if (select_cat == 12 && categories_length == 0) {
			for (int i = 0; i < NUM_CATEGORY; i++) {
				categories[i] = all_categories[i];
			}
			categories_length = NUM_CATEGORY;
			stop_select_cat = true;
		}
		else if (select_cat == 12) {
			stop_select_cat = true;
		}
		else {
			cout << "(!) Invalid number, pick again...";
		}
	}

	cout << "\n# Select question types . . . \n";
	for (int i = 0; i < NUM_TYPE; i++) {
		cout << i + 1 << " : " << all_types[i] << endl;
	}
	cout << "6 : * End Selection (All Types if nothing is selected) *\n\n";

	while (!stop_select_type) {
		cin >> select_type;
		if (select_type > 0 && select_type <= NUM_TYPE) {
			for (int i = 0; i < NUM_TYPE; i++) {
				if (i == select_type - 1)
					types[types_length++] = all_types[i];
			}
		}
		else if (select_type == 6 && types_length == 0) {
			for (int i = 0; i < NUM_TYPE; i++) {
				types[i] = all_types[i];
			}
			types_length = NUM_TYPE;
			stop_select_type = true;
		}
		else if (select_type == 6) {
			stop_select_type = true;
		}
		else {
			cout << "(!) Invalid number, pick again...";
		}
	}
}

void show_settings(int& test_size, int& difficulty, string categories[], string types[]) {
	cout << "\n(i) Your settings . . . " <<
		"\n# Test Size: " << test_size <<
		"\n# Difficulty: ";
	if (difficulty == 1)
		cout << "Easy";
	else if (difficulty == 2)
		cout << "Moderate";
	else
		cout << "Challenging";
	cout << "\n# Categories: \n";
	for (int i = 0; i < categories_length; i++)
		cout << " + " << categories[i] << endl;
	cout << "\n# Question Types: \n";
	for (int i = 0; i < types_length; i++)
		cout << " + " << types[i] << endl;
}