#include <vector>
#include <iostream>
#pragma once

class Text
{
public:
	void print_text();
	void input_text();
	int get_vowel_quantity();

private:
	std::vector<std::string> lines_array;
};

