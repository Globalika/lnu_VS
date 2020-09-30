#pragma once
#ifndef _HANGAR_
#define _HANGAR_
#include <string>;
#include "Plane.h"
class Hangar
{
public:
	Hangar(int capacity);
	Hangar(const Hangar& other);
	Hangar& operator=(const Hangar& other);
	Hangar& operator+(Plane& plane);
	Hangar& operator-(Plane& plane);
	void GetHangerInfo();
	~Hangar();
private:
	Plane* planeList;
	int lastPlaneId;
	int capacity;
};

#endif _HANGAR_