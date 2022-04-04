#pragma once

#include <iostream>
#include <vector>
#include <iomanip>
#include <fstream>
#include <string>
#include "t_student.h"

using namespace std;

void input_data(const string file_name);

void print_data(const string file_name);

void print_data(vector<t_student> min_av_students_vector);

vector<t_student> create_students_vector(const string file_name);

vector<t_student> create_min_av_vector(vector<t_student> students_vector);

void distribute_data(const string file_name, vector<t_student> students_vector);

void title(char* full_name);