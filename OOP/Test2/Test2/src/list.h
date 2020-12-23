#pragma once
#include <math.h>
#include <iostream>
#define PI 3.14159265359
class Figure
{
public:
	virtual void PrintFigureInfo() = 0;
	virtual double GetTheAreaOfTheFigure() = 0;
protected:
	//const double PI = 3.14159265359;
};

class Square : public Figure
{
public:
	Square(double a) : a(a) {}
	void PrintFigureInfo() override
	{
		std::cout << "area of square is " << GetTheAreaOfTheFigure() << "  " << std::endl;
	}
	double GetTheAreaOfTheFigure() override
	{
		return a * a;
	}
private:
	double a;
};


class Circle : public Figure
{
public:
	Circle(double radius): radius(radius) {}

	void PrintFigureInfo() override
	{
		std::cout << "area of circle is " << GetTheAreaOfTheFigure() << "  " << std::endl;
	}
	double GetTheAreaOfTheFigure() override
	{
		return PI * radius * radius;
	}
	~Circle() {}
	double GetRadius() 
	{
		return this->radius;
	}
private:
	double radius;
};



class Triangle : public Figure
{
public:
	Triangle(double a, double b, double c): a(a),b(b),c(c) {}
	void PrintFigureInfo() override
	{
		std::cout << "area of triangle is " << GetTheAreaOfTheFigure() << "  " << std::endl;
	}
	double GetTheAreaOfTheFigure() override
	{
		double p = (a + b + c) / 2;
		return sqrt(p*(p-a)*(p-b)*(p-c));
	}
	~Triangle() {}
private:
	double a;
	double b;
	double c;
};
