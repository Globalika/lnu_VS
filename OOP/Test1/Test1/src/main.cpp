#include "Hangar.h"
#include "Plane.h"
#include <iostream>


int main()
{
	Plane* p = new Plane(3,4);
	std::cout << *p << std::endl;

	Hangar* h = new Hangar(4);
	*h + *p;
	*h + *p;
	*h - *p;
	h->GetHangerInfo();
	return 0;
}