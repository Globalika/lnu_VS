#include "Circle.h"
Circle::Circle()
{
	this->radius = 0;
}

Circle::Circle(double radius)
{
	this->radius = radius;
}

void Circle::PrintFigureInfo()
{
	while (radius <= 0)
	{
		std::cout << "Incorrect radius. Input new: ";
		std::cin >> radius;
	}
	std::cout << "Circle with radius = " << radius <<" ||| Perimeter = " << GetThePerimeterOfTheFigure() << " Area = " << GetTheAreaOfTheFigure() << "." << std::endl;
}

void Circle::SetRadius(double radius)
{
	this->radius = radius;
}

double Circle::GetTheAreaOfTheFigure()
{
	while (radius <= 0)
	{
		std::cout << "Incorrect radius. Input new: ";
		std::cin >> radius;
	}
	return PI * pow(radius,2);
}

double Circle::GetThePerimeterOfTheFigure()
{
	return 2 * PI * radius;
}
