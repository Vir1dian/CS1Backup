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
		if (line[0] == '*') {  // Categories Involved
			// Handles differently from other attributes because it can have 
			// multiple numbers.
			if (line.find(",") == string::npos)
				item.m_categories[0] = stoi(line.substr(1, line.find(".")));
			else {
				// Explodes the string into individual numbers betweem each comma until the period
				// Then, numbers are processed into name equivalents according to all_categories from classes.h
				int temp_attr, start = 1, end = line.find(","), categories_length = 0;
				temp_attr = stoi(line.substr(start, end));
				item.m_categories[categories_length++] = temp_attr;
				while (end != line.find(".")) {
					start = line.find(",") + 1;
					end = line.find(",", line.find(",")) != string::npos ? line.find(",", line.find(",")) : line.find(".");
					temp_attr = stoi(line.substr(start, end));
					item.m_categories[categories_length++] = temp_attr;
				}
			}
		}
		else {
			// Number after the attribute symbol # & or >
			int attr = stoi(line.substr(1, line.find(".")));
			if (line[0] == '#')  // Question Number
				item.m_number = attr;
			else if (line[0] == '&') // Question type
				item.m_type = attr;
			else if (line[0] == '>') // Question Difficulty
				item.m_difficulty = attr;
		}
	}
	else if (field == "Question")
		item.m_question += line;
	else if (field == "Answers")
		item.m_answers += line;
	else if (field == "Solution")
		item.m_solution += line;
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
		if (line_number <= 10)
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
		/*
		else
			extract_line_parser(line, all_items[item_index], item_field); */

		cout << line_number << " " << item_index << " " << item_field << " " << line << endl;
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