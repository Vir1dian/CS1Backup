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
void extract_line_parser(string line, Test_Item& item, string field) {

	if (field == "Attributes") {
		if (line[0] == '*') {  // Categories Involved
			// Handles differently from other attributes because it can have 
			// multiple numbers.
			if (line.find(',') == string::npos)
				item.m_categories[0] = stoi(line.substr(1, line.find('.')));
			else {
				// Explodes the string into individual numbers betweem each comma until the period
				// Then, numbers are processed into name equivalents according to all_categories from classes.h
				int temp_attr, start = 1, end = line.find(',') != string::npos ? line.find(',') : line.find('.'), categories_length = 0;
				temp_attr = stoi(line.substr(start, end));
				item.m_categories[categories_length++] = temp_attr;
				while (end != line.find('.')) {
					start = end + 1;
					end = line.find(',', start + 1) != string::npos ? line.find(',', start + 1) : line.find('.');
					temp_attr = stoi(line.substr(start, end));
					item.m_categories[categories_length++] = temp_attr; 
				}
			}
		}
		else {
			// Number after the attribute symbol # & or >
			int attr = stoi(line.substr(1, line.find('.')));
			if (line[0] == '#')  // Question Number
				item.m_number = attr;
			else if (line[0] == '&') // Question type
				item.m_type = attr;
			else if (line[0] == '>') // Question Difficulty
				item.m_difficulty = attr;
		}
	}
	else if (field == "Question")
		item.m_question += line + "\n";
	else if (field == "Answers")
		item.m_answers += line + "\n";
	else if (field == "Solution")
		item.m_solution += line + "\n";
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
	while (!fin.eof() && item_index < NUM_TEST_ITEMS) {
		// Parsing component
		line_number++;
		getline(fin, line);
		if (line_number <= 10 || line.length() == 0)
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
		// cout << line_number << " " << item_index << " " << item_field << " " << line << endl;
	}
	fin.close();
	return 0;
}

void display_test_items(Test_Item items[NUM_TEST_ITEMS]) {
	cout << "\nNumber of test items: " << NUM_TEST_ITEMS << endl;
	for (int i = 0; i < NUM_TEST_ITEMS; i++) {
		cout << "\n{\nItem Number: " << items[i].m_number << ",";
		cout << "\nQuestion Type: " << items[i].get_type_name() << ",";
		cout << "\nQuestion Difficulty: " << items[i].get_difficulty_name() << ",";
		cout << "\nConcepts Involved: \n{";
		for (int j = 0; j < NUM_CATEGORY; j++) {
			cout << items[i].get_category_name(j);
			if (j < NUM_CATEGORY - 1)
				cout << ", ";
		}
		cout << "},\nQuestion: \n" << items[i].m_question << ",";
		cout << "\nAnswers: \n" << items[i].m_answers << ",";
		cout << "\nSolution: " << items[i].m_solution << "\n}";
		if (i < NUM_TEST_ITEMS - 1) {
			cout << ",";
		}
	}
}

int add_test_items() {
	ofstream fout;
	fout.open("test_items.txt", ios::app);
	if (!fout) {
		cout << "\n(!) File not found (!)\n";
		return 1;
	}
	// Code here
	fout.close();
	return 0;
}