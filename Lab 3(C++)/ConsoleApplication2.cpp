#include "Lab_2.h"
#include "Text.h"

int main()
{
	int quantity;
	cout << "Enter quantity of texts-> "; cin >> quantity;
	cin.ignore();

	vector<Text> texts = create_textsArray(quantity);
	print_texts(texts);

	add_line(texts);
	print_texts(texts);

	compare_texts(texts);
}