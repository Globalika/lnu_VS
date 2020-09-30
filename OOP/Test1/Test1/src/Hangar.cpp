#include "Hangar.h"

Hangar::Hangar(int capacity)
{
	planeList = new Plane[capacity];
	this->capacity = capacity;
	this->lastPlaneId = -1;
}

Hangar::Hangar(const Hangar& other)
{
	planeList = new Plane[capacity];
	this->capacity = other.capacity;
	for (int i = 0; i <= capacity; i++)
	{
		planeList[i] = other.planeList[i];
	}
}

Hangar& Hangar::operator=(const Hangar& other)
{
	for (int i = 0; i <= capacity; i++)
	{
		planeList[i] = other.planeList[i];
	}
	return *this;
}

Hangar& Hangar::operator+(Plane& plane)
{
	this->planeList[++lastPlaneId] = plane;
	return *this;
}

Hangar& Hangar::operator-(Plane& plane)
{
	delete &planeList[lastPlaneId--];
	return *this;
}

void Hangar::GetHangerInfo()
{
	for (int i = 0; i <= lastPlaneId - 1; i++)
	{
		std::cout << Plane::GetInfo(this->planeList[i]) << std::endl;
	}
}

Hangar::~Hangar()
{
	for (int i = 0; i <= capacity; i++)
	{
		delete &planeList[i];
	}
	delete planeList;
}
