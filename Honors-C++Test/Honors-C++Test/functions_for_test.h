#pragma once
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>
#include "classes.h"

bool has_common_categories(const int[NUM_CATEGORY], const int[NUM_CATEGORY]);

void create_test(Test_Item[NUM_TEST_ITEMS], const Settings, const Test_Item[NUM_TEST_ITEMS]);

void take_test(const Test_Item[NUM_TEST_ITEMS], const Settings);

void grade_test(const Test_Item[NUM_TEST_ITEMS], const Settings, const string[NUM_TEST_ITEMS]);