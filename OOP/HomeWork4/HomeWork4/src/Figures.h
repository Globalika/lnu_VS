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
	virtual double GetThePerimeterOfTheFigure() = 0;
	//~Figure();
protected:
	const double PI = 3.14159265359;
};
class Circle : public Figure
{
public:
	Circle(double radius) { this->radius = radius; }

	void PrintFigureInfo() override {
		std::cout << "Circle with radius = " 
		<< radius << " ||| Perimeter = " 
		<< GetThePerimeterOfTheFigure() << std::endl;
	}
	double GetThePerimeterOfTheFigure() override 
	{
		return 2 * PI * radius;
	}

	void SetRadius(double radius) 
	{
		this->radius = radius;
	}
	~Circle() {}
private:
	double radius;
};

class Rectangle : public Figure
{
public:
	Rectangle(double a, double b) 
	{
		this->a = a;
		this->b = b;
	}

	void PrintFigureInfo() override 
	{
		std::cout << "Rectangle with A = " << a << " and B = " << b
			<< " ||| Perimeter = " << GetThePerimeterOfTheFigure() << std::endl;
	}
	double GetThePerimeterOfTheFigure() override 
	{
		return 2 * (a + b);
	}
	virtual void SetLength() 
	{
		std::cout << "Input A : ";
		std::cin >> a;
		std::cout << "Input B : ";
		std::cin >> b;
	}
	~Rectangle() {}
private:
	double a;
	double b;
};
#endif _FIGURE_