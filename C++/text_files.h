#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

void input_text(const string name);
void print_file(const string name);
vector<string> create_linesArray(const string name);
void distribute_strings(const string start_file_name, const string first_file_name, const string second_file_name);
void sort_lines(const string name);