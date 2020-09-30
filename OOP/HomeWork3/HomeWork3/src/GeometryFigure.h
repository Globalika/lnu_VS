#pragma once
#ifndef _FIGURE_
#define _FIGURE_
#include <math.h>
#include <iostream>
class Figure
{
public:
	//Figure();
	virtual void PrintFigureInfo() = 0;
	virtual double GetTheAreaOfTheFigure() = 0;
	virtual double GetThePerimeterOfTheFigure() = 0;
	//~Figure();
protected:
	const double PI = 3.14159265359;
};




#endif _FIGURE_