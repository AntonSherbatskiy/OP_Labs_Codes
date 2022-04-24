#include <iostream>
#include "Func.h"

int main()
{
	Circle C1 = input_C1();
	Circle C2 = input_C2();
	Circle C3 = input_C3();

	cout << "\nBEFORE INCREMENT\n";
	show_data(C1, C2, C3);


	++C1;

	C2++;

	C3 *= 2;

	cout << "\n\nAFTER INCREMENT\n";
	show_data(C1, C2, C3);

	max_thickness(C1, C2, C3);
}
