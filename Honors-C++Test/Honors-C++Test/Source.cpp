#include <iostream>
#include <fstream>
#include <string>
#include "parser_items.h"
#include "classes.h"
using namespace std;

int main() {
	// File parsing
	Test_Item set1[NUM_TEST_ITEMS];
	cout << extract_test_items(set1);
	cout << "\nTesting file parsing...\n";
	/*
	for (Test_Item i : set1) {
		cout << i.m_number << endl;
		cout << i.get_type_name() << endl;
		cout << i.get_difficulty_name() << endl;
		cout << i.get_category_name(0) << endl;
		cout << i.m_question << endl;
		cout << i.m_answers << endl;
		cout << i.m_solution << endl << endl;
	}
	*/
	// Settings
	/*
	Settings my_settings;
	int confirm;

	cout << "\n*** C++ Test by Gavin Torrecampo ***\n";
	do {
		my_settings.select_settings();
		my_settings.show_settings();
		cout << "\n* Confirm settings? (0 no, 1 yes) *\n";
		cin >> confirm;
	} while (confirm != 1);
	*/



	return 0;
}