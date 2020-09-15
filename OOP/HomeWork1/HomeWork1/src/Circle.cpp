#include "Circle.h"
#include "math.h"

Circle::Circle()
{
	this->radius = 0;
}

Circle::Circle(int radius)
{
	this->radius = radius;
}

void Circle::SetRadius(int radius)
{
	this->radius = radius;
}

int Circle::GetRadius()
{
	return this->radius;
}

double Circle::FindThePerimeterOfACircle()
{
	return 2 * PI * this->radius;
}

double Circle::FindTheAreaOfACircle()
{
	return PI * pow(this->radius, 2);
}
