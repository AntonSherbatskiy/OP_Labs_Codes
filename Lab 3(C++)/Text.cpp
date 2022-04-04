#include "Text.h"
#include <string>

using namespace std;

void Text::print_text()
{
	for (const string& line : lines_array)
	{
		cout << line;
	}
}

void Text::input_text()
{
	cout << "\nEnter text, press ctrl + X to stop!\n";

	while (true)
	{
		string line;
		getline(cin, line);

		if(int(line[0]) != 24)
		{
			line += '\n';
			lines_array.push_back(line);
		}
		else
		{
			break;
		}
	}
}

int Text::get_vowel_quantity()
{
	int quantity = 0;

	for (const string& line : lines_array)
	{
		for (const char& symbol : line)
		{
			if (symbol == 'a' || symbol == 'e' || symbol == 'i' || symbol == 'o' || symbol == 'u' || symbol == 'y')
			{
				quantity++;
			}
		}
	}

	return quantity;
}