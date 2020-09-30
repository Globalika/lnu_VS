#include "Rectangle.h"

Rectangle::Rectangle()
{
	this->a = 0;
	this->b = 0;
}

Rectangle::Rectangle(double a, double b)
{
	this->a = a;
	this->b = b;
}

void Rectangle::PrintFigureInfo()
{
	std::cout << "Rectangle with A = " << a << " and B = " << b 
		<< " ||| Perimeter = " << GetThePerimeterOfTheFigure() 
		<< " Area = " << GetTheAreaOfTheFigure() << "." << std::endl;
}

double Rectangle::GetTheAreaOfTheFigure()
{
	return a * b;
}

double Rectangle::GetThePerimeterOfTheFigure()
{
	return 2 * (a + b);
}

void Rectangle::SetLength()
{
	std::cout << "Input A : ";
	std::cin >> a;
	std::cout << "Input B : ";
	std::cin >> b;
}
