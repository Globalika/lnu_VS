#include <iostream>
#include "Circle.h"
#include "Rectangle.h"
#include "Square.h"
int main()
{
	Circle c;
	c.PrintFigureInfo();
	c.SetRadius(5);
	c.PrintFigureInfo();
	Circle c1(3);
	double k = c1.GetTheAreaOfTheFigure();
	std::cout << k << std::endl;

	Rectangle r;
	r.SetLength();
	r.PrintFigureInfo();
	
	Square s(4);
	s.PrintFigureInfo();

	system("pause");
	return 0;
}