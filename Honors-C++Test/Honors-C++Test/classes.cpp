#include <iostream>
#include "classes.h"
using namespace std;

void Settings::select_settings() {
	int select_cat, select_type; // Temp values used to add selected items to arrays
	bool stop_select_cat = false, stop_select_type = false; // Flags used to end while loops
	int categories_length = 0, types_length = 0; // Index used to add selected items to arrays
	reset_settings(); // Empty m_categories and m_types

	cout << "\n# Select test size(1-20): ";
	cin >> m_test_size;
	while (m_test_size < 1 || m_test_size > 20) {
		cout << "(!) Invalid number, pick again...";
		cin >> m_test_size;
	}

	cout << "\n# Select difficulty (1 easy, 2 moderate, 3 challenging): ";
	cin >> m_difficulty;
	while (m_difficulty < 1 || m_difficulty > 3) {
		cout << "(!) Invalid number, pick again...";
		cin >> m_difficulty;
	}

	cout << "\n# Select categories . . . \n";
	// Display all categories
	for (int i = 0; i < NUM_CATEGORY; i++) { 
		cout << i + 1 << " : " << all_categories[i] << endl;
	}
	cout << "12 : * End Selection (All Categories if nothing is selected) *\n\n";

	// Select one or more categories
	while (!stop_select_cat && categories_length < NUM_CATEGORY) {
		cin >> select_cat;
		if (select_cat > 0 && select_cat <= NUM_CATEGORY)
			m_categories[categories_length++] = select_cat;
		else if (select_cat == 12 && categories_length == 0) {
			for (int i = 0; i < NUM_CATEGORY; i++) {
				m_categories[i] = i + 1;
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
	// Display all question types
	for (int i = 0; i < NUM_TYPE; i++) {
		cout << i + 1 << " : " << all_types[i] << endl;
	}
	cout << "6 : * End Selection (All Types if nothing is selected) *\n\n";

	// Select one or more question types
	while (!stop_select_type && types_length < NUM_TYPE) {
		cin >> select_type;
		if (select_type > 0 && select_type <= NUM_TYPE)
			m_types[types_length++] = select_type;
		else if (select_type == 6 && types_length == 0) {
			for (int i = 0; i < NUM_TYPE; i++) {
				m_types[i] = i + 1;
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

void Settings::show_settings() {
	cout << "\n(i) Your settings . . . " <<
		"\n# Test Size: " << m_test_size <<
		"\n# Difficulty: ";
	if (m_difficulty == 1)
		cout << "Easy";
	else if (m_difficulty == 2)
		cout << "Moderate";
	else
		cout << "Challenging";
	cout << "\n# Categories: \n";
	for (int i = 0; i < NUM_CATEGORY; i++) {
		if (m_categories[i] == 0)
			break;
		cout << " + " << m_categories[i] << " : " << all_categories[m_categories[i] - 1] << endl;
	}
	cout << "\n# Question Types: \n";
	for (int i = 0; i < NUM_TYPE; i++) {
		if (m_types[i] == 0)
			break;
		cout << " + " << m_types[i] << " : " << all_types[m_types[i] - 1] << endl;
	}
}

void Settings::reset_settings() {
	for (int i = 0; i < NUM_CATEGORY; i++)
		m_categories[i] = 0;
	for (int i = 0; i < NUM_TYPE; i++)
		m_types[i] = 0;
}

string Test_Item::get_type_name() const {
	for (int i = 0; i < NUM_TYPE; i++) {
		if (m_type - 1 == i) {  // m_type can only be numbers 1-5
			return all_types[i];
		}
	}
}

string Test_Item::get_difficulty_name() const {
	switch (m_difficulty) {  // m_difficulty can only be numbers 1-3
	case 1:
		return "Easy";
	case 2:
		return "Moderate";
	default:
		return "Challenging";
	}
}

string Test_Item::get_category_name(int index) const {
	if (m_categories[index] == 0) {  // m_categories can only be numbers 0-5, 0 means empty
		return "";
	}
	for (int i = 0; i < NUM_CATEGORY; i++) {
		if (m_categories[index] - 1 == i) {
			return all_categories[i];
		}
	}
}
