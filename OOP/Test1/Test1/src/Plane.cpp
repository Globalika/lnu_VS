#include "Plane.h"
#include <iostream>

Plane::Plane(double weight, int capacity)
{
	try
	{
		this->weight = weight;
		this->capacity = capacity;
		ConstructorCheck(*this);
	}
	catch (const std::exception& err)
	{
		std::cout << "Wrong! Please, try again." << std::endl;
	}
}

Plane& Plane::operator=(const Plane& other)
{
	this->capacity = other.capacity;
	this->weight = other.weight;
	return *this;
}

void Plane::ConstructorCheck(const Plane& plane)
{
	if (plane.weight < 0 || plane.capacity < 0)
	{
		throw std::exception();
	}
}

std::string Plane::GetInfo(const Plane& plane)
{
	return "Plane | with capacity : " + std::to_string(plane.capacity) + " and weight : " + std::to_string(plane.weight);
}

std::ostream& operator<<(std::ostream& os, const Plane& plane)
{
	os << Plane::GetInfo(plane);
	return os;
}


int Plane::GetWeight()
{
	return this->weight;
}

double Plane::GetCapacity()
{
	return this->capacity;
}

Plane::~Plane()
{
	delete[] this;
}
