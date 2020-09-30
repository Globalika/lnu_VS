#include "Square.h"

Square::Square()
{
	this->a = 0;
}

Square::Square(double a)
{
	this->a = a;
}

void Square::PrintFigureInfo()
{
	std::cout << "Square with A = " << a 
		<< " ||| Perimeter = " << GetThePerimeterOfTheFigure()
		<< " Area = " << GetTheAreaOfTheFigure() << "." << std::endl;
}

double Square::GetTheAreaOfTheFigure()
{
	return pow(a,2);
}

double Square::GetThePerimeterOfTheFigure()
{
	return 4 * a;
}

void Square::SetLength()
{
	std::cout << "Input A : ";
	std::cin >> a;
}
