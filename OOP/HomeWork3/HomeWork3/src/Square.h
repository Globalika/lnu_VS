#pragma once
#ifndef _SQUARE_
#define _SQUARE_
#include "Rectangle.h"
class Square : public Rectangle
{
public:
	Square();
	Square(double a);

	void PrintFigureInfo() override;
	double GetTheAreaOfTheFigure() override;
	double GetThePerimeterOfTheFigure() override;
	void SetLength() override;

	~Square() {}
private:
	double a;
};




#endif _SQUARE_