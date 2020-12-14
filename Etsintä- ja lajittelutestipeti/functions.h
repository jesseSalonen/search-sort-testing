#pragma once
#include "List.h"
#include "Random.h"
#include "Record.h"
#include "Timer.h"

void test_search(int searches, List& the_list, int submenu);
Error_code sequential_search(const List& the_list,
    const Key& target, int& position);
void print_out(const string& result, const double& elapsed_time, const int& comparisons, const int& searches, int submenu);
Error_code recursive_binary_1(const List& the_list, const Key& target,
    int bottom, int top, int& position);


