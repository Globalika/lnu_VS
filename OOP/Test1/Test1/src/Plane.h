#pragma once
#ifndef _PLANE_
#define _PLANE_
#include <fstream>
#include <sstream>
#include <iostream>
class Plane 
{
public:
	Plane(double weight = 0, int capacity = 0);
	Plane& operator=(const Plane& other);
	void ConstructorCheck(const Plane& plane);
	static std::string GetInfo(const Plane& plane);
	int GetWeight();
	double GetCapacity();
	~Plane();

	friend std::ostream& operator<<(std::ostream& os, const Plane& plane);
private:
	double weight;
	int capacity;
};

#endif _PLANE_