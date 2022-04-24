#pragma once
class Circle
{
private:
	int inner_radius;
	int outer_radius;
	int x;
	int y;

public:
	Circle(int inner_radius, int outer_radius, int x, int y);
	Circle();
	Circle(int inner_radius, int outer_radius);

	void set_inner_radius(int inner_radius){ this->inner_radius = inner_radius; }
	void set_outer_radius(int outer_radius) { this->outer_radius = outer_radius; }
	void set_x(int x) { this->x = x; }
	void set_y(int y) { this->y = y; }

	int get_inner_radius() { return inner_radius; }
	int get_outer_radius() { return outer_radius; }
	int get_x() { return x; }
	int get_y() { return y; }

	int calc_thickness();

	Circle & operator ++()
	{
		this->inner_radius++;
		return *this;
	}
	Circle & operator ++(int value)
	{
		Circle temp(*this);

		this->outer_radius++;

		return temp;
	}
	Circle & operator *=(int value)
	{
		Circle temp(*this);

		this->outer_radius *= value;

		return temp;
	}
};