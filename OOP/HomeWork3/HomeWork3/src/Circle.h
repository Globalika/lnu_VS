#pragma once
#ifndef _CIRCLE_
#define _CIRCLE_
#include "GeometryFigure.h"
class Circle : public Figure
{
public:
	Circle();
	Circle(double radius);

	void PrintFigureInfo() override;
	double GetTheAreaOfTheFigure() override;
	double GetThePerimeterOfTheFigure() override;

	void SetRadius(double radius);
	~Circle() {}
private:
	double radius;
};




#endif _CIRCLE_