#include "Lab_2.h"
#include "Text.h"

vector<Text> create_textsArray(int quantity)
{
	vector<Text> texts;

	for (int i = 0; i < quantity; i++)
	{
		Text some_text;
		some_text.input_text();
		texts.push_back(some_text);
	}
	
	return texts;
}

void add_line(vector <Text> &texts)
{
	int index = NULL, if_continue = NULL;

	do
	{
		cout << "\nEnter the index of text which you want to add line-> "; cin >> index;
		index--;

		while (index > texts.size() || index < 0)
		{
			cout << "\nAttention! Index can`t be higher than " << texts.size() << "! Enter again-> "; cin >> index;
			index--;
		}
		cin.ignore();

		texts[index].input_text();

		cout << "\nIf you want to add another lines press 1 or else to stop-> "; cin >> if_continue;
	} while (if_continue == 1);
}

void print_texts(vector<Text> texts)
{
	for (int i = 0; i < texts.size(); i++)
	{
		cout << "\n-----------------Text " << i + 1 << "-----------------\n";
		texts[i].print_text();
	}
}

void compare_texts(vector<Text> texts)
{
	vector<int> each_text_vowels;
	int max_vowels = 0, index;

	cout << '\n';
	for (int i = 0; i < texts.size(); i++)
	{
		each_text_vowels.push_back(texts[i].get_vowel_quantity());

		cout << "Text " << i + 1 << " have " << texts[i].get_vowel_quantity() << " vowels\n";
	}

	for (int i = 0; i < each_text_vowels.size(); i++)
	{
		if (each_text_vowels[i] > max_vowels)
		{
			max_vowels = each_text_vowels[i];
			index = i;
		}
	}

	if (max_vowels != 0)
	{
		cout << "\nText " << index + 1 << " have " << max_vowels << " vowels(MAX)\n";
	}
	else
	{
		cout << "\nThere is`t text with vowels!\n";
	}
} 