#pragma once

#include "Text.h"

using namespace std;

vector<Text> create_textsArray(int quantity);

void print_texts(vector<Text> texts);

void add_line(vector <Text> &texts);

void compare_texts(vector<Text> texts);