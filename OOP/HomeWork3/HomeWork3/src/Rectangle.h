#pragma once
#ifndef _RECTANGLE_
#define _RECTANGLE_
#include "GeometryFigure.h"
class Rectangle : public Figure
{
public:
	Rectangle();
	Rectangle(double a, double b);

	void PrintFigureInfo() override;
	double GetTheAreaOfTheFigure() override;
	double GetThePerimeterOfTheFigure() override;
	virtual void SetLength();
	~Rectangle() {}
private:
	double a;
	double b;
};




#endif _RECTANGLE_