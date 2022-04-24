#include "Circle.h"
#include <iostream>

Circle::Circle(int inner_radius, int outer_radius)
{
	this->inner_radius = inner_radius;
	this->outer_radius = outer_radius;
	x = 0;
	y = 0;
}

Circle::Circle()
{
	outer_radius = 0;
	inner_radius = 0;
	x = 0;
	y = 0;
}

Circle::Circle(int inner_radius_value, int outer_radius_value, int x_value , int y_value)
	: inner_radius(inner_radius_value), outer_radius(outer_radius_value), x(x_value), y(y_value){}

int Circle::calc_thickness() 
{ 
	return outer_radius - inner_radius;
}