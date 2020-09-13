#include "circle.h"
#include "employee.h"
#include "phone.h"

#include <iostream>
using namespace std;

int main()
{
	Circle circle1;
	circle1.GetRadius();
	Circle circle2(3);
	circle2.FindThePerimeterOfACircle();
	circle2.FindTheAreaOfACircle();
	circle1.SetRadius(4);
	//////////////////////////
	Employee worker1(33,"efrer","everv");
	worker1.PrintEmployeeInfo();
	worker1.SetEmloyeeAge(34);
	std::string name;
	name = worker1.GetEmployeeSecondName();
	std::cout << name;
	///////////////////////////
	Phone phone1(34234,"rvev",43);
	Phone phone2(43523, "fgnhg", 43);
	if (phone1.GetPhoneDiagonal() == phone2.GetPhoneDiagonal())
	{
		std::cout << "Phones have same diagonal length!\n";
	}
	else
	{
		std::cout << "Phones have different diagonal length!\n";
	}
	std::cout << phone2.GetPhoneNumber() << '\n';
	system("pause");
	return 0;
}