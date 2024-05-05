#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>
#include "classes.h"
#include "functions_for_test.h"
using namespace std;

// Helper for create_test, finds the common numbers between arrays setting_cats and items_cats
bool has_common_categories(const int setting_cats[NUM_CATEGORY], const int items_cats[NUM_CATEGORY]) {
	for (int i = 0; setting_cats[i] != 0 && i < NUM_CATEGORY; i++) {
		for (int j = 0; items_cats[j] != 0 && j < NUM_CATEGORY; j++) {
			if (setting_cats[i] == items_cats[j])
				return true;
		}
	}
	return false;
}

void create_test(Test_Item test[NUM_TEST_ITEMS], const Settings setting, const Test_Item items[NUM_TEST_ITEMS]) {
	Test_Item included[NUM_TEST_ITEMS], excluded[NUM_TEST_ITEMS];
	int in_index = 0, ex_index = 0;

	// Filter by category
	for (int i = 0; i < NUM_TEST_ITEMS; i++) {
		if (has_common_categories(setting.m_categories, items[i].m_categories))
			included[in_index++] = items[i];
		else
			excluded[ex_index++] = items[i];
	}

	// Filter by difficulty 
	for (int i = 0; included[i].m_number != 0 && i < NUM_TEST_ITEMS; i++) {
		if (included[i].m_difficulty != setting.m_difficulty) {
			// Move to excluded and remove from included, shift subsequent elements back
			excluded[ex_index++] = included[i];
			for (int j = i; j + 1 < NUM_TEST_ITEMS; j++) {
				included[j] = included[j + 1];
				included[NUM_TEST_ITEMS - 1] = {};
			}
			in_index--;
			i--;
		}
	}

	// Filter by type
	for (int i = 0; included[i].m_number != 0 && i < NUM_TEST_ITEMS; i++) {
		bool has_type = false;
		for (int j = 0; setting.m_types[j] != 0 && j < NUM_TYPE; j++) {
			if (setting.m_types[j] == included[i].m_type) {
				has_type = true;
				break;
			}
		}
		if (!has_type) {
			// Move to excluded and remove from included, shift subsequent elements back
			excluded[ex_index++] = included[i];
			for (int j = i; j + 1 < NUM_TEST_ITEMS; j++) {
				included[j] = included[j + 1];
				included[NUM_TEST_ITEMS - 1] = {};
			}
			in_index--;
			i--;
		}
	}

	// Shuffle included & excluded
	for (int i = 0; included[i].m_number != 0 && i < NUM_TEST_ITEMS; i++) {
		int j = rand() % (in_index);
		Test_Item temp;
		temp = included[i];
		included[i] = included[j];
		included[j] = temp;
	}
	for (int i = 0; excluded[i].m_number != 0 && i < NUM_TEST_ITEMS; i++) {
		int j = rand() % (ex_index);
		Test_Item temp;
		temp = excluded[i];
		excluded[i] = excluded[j];
		excluded[j] = temp;
	}

	// Add items from included, fill in remaining with excluded if possible
	int test_index = 0;
	for (int i = 0; included[i].m_number != 0 && i < setting.m_test_size; i++)
		test[test_index++] = included[i];
	in_index = test_index;
	for (int i = 0; i < setting.m_test_size - in_index; i++)
		test[test_index++] = excluded[i];

}

void take_test(const Test_Item test[NUM_TEST_ITEMS], const Settings setting) {
	string user_answers[NUM_TEST_ITEMS];

	cout << "\n\n************************\n"
		<< "Greetings, test taker. The following test has questions based on your \n"
		<< "selected settings. Due to the limited question pool available, some \n"
		<< "questions that do not fit your preferences may appear if your selected \n"
		<< "test size is large enough.\n\nInstructions: \n"
		<< "For multiple choice questions, type the exact character that matches the \n"
		<< "best answer. For Fill-in-the-blank (FIB) questions, type the exact word \n"
		<< "or code that completes the sentence. For True-or-False (TOF) questions, \n"
		<< "type 'true' or 'false'. Good luck!   ";
	cin.get(); 
	cin.ignore();

	for (int i = 0; i < setting.m_test_size; i++) {
		cout << "\n\n(#" << i + 1 << "): \n" << test[i].m_question << "\n" 
			<< test[i].m_answers << endl;

		getline(cin, user_answers[i]);
		char confirm = 'n';
		cout << "\n + Confirm answer? (y/n): ";
		cin >> confirm;
		cin.ignore();
		while (confirm != 'y') {
			cout << "\n + Retype your answer: ";
			getline(cin, user_answers[i]);
			cout << "\n + Confirm answer? (y/n): ";
			cin >> confirm;
			cin.ignore();
		}
	}

	// Show results
	grade_test(test, setting, user_answers);
	
}

void grade_test(const Test_Item test[NUM_TEST_ITEMS], const Settings setting, const string user_answers[NUM_TEST_ITEMS]) {
	cout << "\n************************\n\n(!) You have completed the test! Your grade is ... \n";
	cin.get();

	int max_score = setting.m_test_size, user_score = 0;
	for (int i = 0; i < setting.m_test_size; i++) {
		if (test[i].m_solution.find(user_answers[i]) != string::npos)
			user_score++;
	}
	float grade = float(user_score) * 100.0 / max_score;

	cout << grade << " out of 100!";
	if (grade > 90)
		cout << "\nAmazing!";
	else if (grade > 80)
		cout << "\nGood job.";
	else if (grade > 70)
		cout << "\nJust a little more!";
	else
		cout << "\nYou'll have to study a lot.";

	cout << "\nYour answers: \n";
	for (int i = 0; i < setting.m_test_size; i++) {
		cout << "\n(# " << i + 1 << ") Correct Answer: " << test[i].m_solution 
			<< ", Your Answer: " << user_answers[i] << "   ";
		if (test[i].m_solution.find(user_answers[i]) != string::npos)
			cout << "CORRECT";
		else
			cout << "INCORRECT";
	}
	cout << "\n\n * Thank you for taking the test! * \n************************\n";
}