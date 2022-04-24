#include "Func.h"

Circle input_C1()
{
	int in_r = NULL, out_r = NULL, cord_x, cord_y;

	do
	{
		cout << "Enter inner radius for C1-> ";
		cin >> in_r;

		cout << "Enter outer radius for C1-> ";
		cin >> out_r;

		if (in_r > out_r) { cout << "\nAttention! Inner radius can not be higher than outer radius, enter again!\n"; }
	} while(in_r > out_r);

	cout << "Enter cord X for C1-> "; cin >> cord_x;
	cout << "Enter cord y for C1-> "; cin >> cord_y;

	Circle C1(in_r, out_r, cord_x, cord_y);

	return C1;
}

Circle input_C2()
{
	int in_r = NULL, out_r = NULL;

	do
	{
		cout << "\nEnter inner radius for C2-> ";
		cin >> in_r;

		cout << "Enter outer radius for C2-> ";
		cin >> out_r;

		if (in_r > out_r) { cout << "\nAttention! Inner radius can not be higher than outer radius, enter again!\n"; }
	} while (in_r > out_r);
	
	Circle C2(in_r, out_r);

	return C2;
}

Circle input_C3()
{
	int in_r = NULL, out_r = NULL, cord_x, cord_y;
	do
	{
		cout << "\nEnter inner radius for C3-> ";
		cin >> in_r;

		cout << "Enter outer radius for C3-> ";
		cin >> out_r;

		if (in_r > out_r) { cout << "\nAttention! Inner radius can not be higher than outer radius, enter again!\n"; }
	} while (in_r > out_r);
	
	cout << "Enter cord X for C3-> "; cin >> cord_x;
	cout << "Enter cord y for C3-> "; cin >> cord_y;

	Circle C3;
	C3.set_inner_radius(in_r);
	C3.set_outer_radius(out_r);
	C3.set_x(cord_x);
	C3.set_y(cord_y);

	return C3;
}

void show_data(Circle C1, Circle C2, Circle C3)
{
	cout << "\n----------C1----------\n";
	cout << "Inner radius: " << C1.get_inner_radius() << "\nOuter radius: " << C1.get_outer_radius() << "\nCord X: " << C1.get_x() << "\nCord Y: " << C1.get_y() << "\nThickness: " << C1.calc_thickness();

	cout << "\n\n----------C2----------\n";
	cout << "Inner radius: " << C2.get_inner_radius() << "\nOuter radius: " << C2.get_outer_radius() << "\nCord X: " << C2.get_x() << "\nCord Y: " << C2.get_y() << "\nThickness: " << C2.calc_thickness();

	cout << "\n\n----------C3----------\n";
	cout << "Inner radius: " << C3.get_inner_radius() << "\nOuter radius: " << C3.get_outer_radius() << "\nCord X: " << C3.get_x() << "\nCord Y: " << C3.get_y() << "\nThickness: " << C3.calc_thickness();
}

void max_thickness(Circle C1, Circle C2, Circle C3)
{
	int max_thick = C1.calc_thickness();
	string name = "C1";

	if (C2.calc_thickness() > max_thick)
	{
		max_thick = C2.calc_thickness();
		name = "C2";
	}
	if (C3.calc_thickness() > max_thick)
	{
		max_thick = C2.calc_thickness();
		name = "C3";
	}

	cout << "\n\nMAX thickness circle: " << name;
}