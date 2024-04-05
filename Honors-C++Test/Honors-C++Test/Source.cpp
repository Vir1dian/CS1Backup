#include <iostream>
#include <fstream>
#include <string>
#include "parser_items.h"
#include "classes.h"
using namespace std;

int main() {
	// File parsing
	Test_Item set1[NUM_TEST_ITEMS];
	// cout << extract_test_items(set1);

	
	// Settings
	Settings my_settings;
	int confirm;

	cout << "\n*** C++ Test by Gavin Torrecampo ***\n";
	do {
		my_settings.select_settings();
		my_settings.show_settings();
		cout << "\n* Confirm settings? (0 no, 1 yes) *\n";
		cin >> confirm;
	} while (confirm != 1);
	



	return 0;
}