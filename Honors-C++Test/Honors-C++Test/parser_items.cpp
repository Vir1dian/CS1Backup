#include <iostream>
#include <fstream>
#include <string>
#include "classes.h"
#include "parser_items.h"
using namespace std;

/**
 * This function is solely used for the extract_test_items() function. 
 * It is used to parse a line to determine what to add to a Test_Item
 * object.
 * @param string: line to be parsed 
 * @param Test_Item: Object to be updated by line data
 * @param string: field of data the line is associated with in 
 * the file ("Attributes","Question","Answers", or "Solution")
 */
void extract_line_parser(string line, Test_Item item, string field) {
	if (field == "Attributes") {
		int attr = stoi(line.substr(1, line.find(" ") != string::npos ? line.find(" ") : line.length()));
		if (line[0] == '#')
			item.number = attr;
		else if (line[0] == '&') {
			for (int i = 0; i < NUM_TYPE; i++) {
				if (attr - 1 == i) {
					item.type = all_types[i + 1];
					break;
				}
			}
		}
		else if (line[0] == '>') {
			if (attr == 1)
				item.difficulty = "Easy";
			else if (attr == 2)
				item.difficulty = "Moderate";
			else
				item.difficulty = "Challenging";
		}
		else if (line[0] == '*') {
			for (int i = 1; i < )
		}
	}
}

int extract_test_items(Test_Item all_items[NUM_TEST_ITEMS]) {
	ifstream fin;
	fin.open("test_items.txt");
	if (!fin) {
		cout << "\n(!) File not found (!)\n";
		return 1;
	}

	string line, item_field;
	int line_number = 0, item_index = -1;
	while (!fin.eof()) {
		// Parsing component
		line_number++;
		getline(fin, line);
		if (line_number <= 9)
			continue;
		if (line.find("Attributes:") != string::npos) {
			item_index++;
			item_field = "Attributes";
			continue;
		}
		else if (line.find("Question:") != string::npos) {
			item_field = "Question";
			continue;
		}
		else if (line.find("Answers:") != string::npos) {
			item_field = "Answers";
			continue;
		}
		else if (line.find("Solution:") != string::npos) {
			item_field = "Solution";
			continue;
		}
		else
			extract_line_parser(line, all_items[item_index], item_field);

		// cout << line_number << " " << line << endl;
	}

	fin.close();
	return 0;
}

int add_test_items() {
	ofstream fout;
	fout.open("test_items.txt", ios::app);
	if (!fout) {
		cout << "\n(!) File not found (!)\n";
		return 1;
	}
	fout.close();
	return 0;
}