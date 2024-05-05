#pragma once
#include <fstream>
#include <string>
#include "classes.h"

void extract_line_parser(string, Test_Item&, string);

int extract_test_items(Test_Item[NUM_TEST_ITEMS]);

void display_test_items(Test_Item[NUM_TEST_ITEMS]);

int add_test_items();