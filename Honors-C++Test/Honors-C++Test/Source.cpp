#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <cstdlib>
#include "parser_items.h"
#include "classes.h"
#include "functions_for_test.h"
using namespace std;

int main() {
	// File parsing

	Test_Item set1[NUM_TEST_ITEMS];
	cout << extract_test_items(set1);
	/*
	cout << "\nTesting file parsing...\n";
	display_test_items(set1);
	*/

	
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

	// Test Creation
	srand(time(0)); 
	Test_Item my_test[NUM_TEST_ITEMS]; 
	create_test(my_test, my_settings, set1);  // populate my_test based on my_settings
	take_test(my_test, my_settings);  



	return 0;
}