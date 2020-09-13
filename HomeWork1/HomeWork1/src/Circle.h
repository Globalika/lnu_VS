#pragma once
#define PI 3.14

class Circle 
{
public:
	Circle();
	Circle(int radius);

	void SetRadius(int radius);
	int GetRadius();
	double FindTheAreaOfACircle();
	double FindThePerimeterOfACircle();
private:
	int radius;
};