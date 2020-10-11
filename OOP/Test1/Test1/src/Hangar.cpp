#include "Hangar.h"
//#include <string>;
Hangar::Hangar(int capacity)
{
	planeList = new Plane*[capacity];
	for (int i = 0; i < capacity; i++)
	{
		planeList[i] = new Plane;
	}
	this->capacity = capacity;
	this->lastPlaneId = -1;
}

Hangar::Hangar(const Hangar& other)
{
	for (int i = 0; i <= capacity; i++)
	{
		delete& planeList[i];
	}
	delete planeList;

	planeList = new Plane*[other.capacity];
	for (int i = 0; i < capacity; i++)
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

Hangar& Hangar::operator+(Plane* plane)
{
	this->planeList[++lastPlaneId] = plane;
	return *this;
}

Hangar& Hangar::operator-(int i)
{
	delete planeList[i];
	return *this;
}

void Hangar::GetHangerInfo()
{
	for (int i = 0; i <= lastPlaneId; i++)
	{
		if (planeList[i]->GetCapacity() > 0 || planeList[i]->GetWeight() > 0)
		{
			std::cout << Plane::GetInfo(*planeList[i]) << std::endl;
		}
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
