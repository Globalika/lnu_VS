#include "Hangar.h"
#include "Plane.h"
#include <iostream>


int main()
{
	Plane* p = new Plane(3,4);
	Plane* p1 = new Plane(32, 55);
	Plane* p2 = new Plane(66, 3);
	std::cout << *p << std::endl << std::endl;

	Hangar* h = new Hangar(4);
	*h + p;
	*h + p1;
	*h + p2;
	
	h->GetHangerInfo();

	*h - 2;
	std::cout << std::endl;
	h->GetHangerInfo();

	Hangar* h1 = h;
	std::cout << std::endl;
	h1->GetHangerInfo();

	Hangar* h2 = new Hangar(4);
	*h2 = *h1;

	std::cout << std::endl;
	h2->GetHangerInfo();

	return 0;
}