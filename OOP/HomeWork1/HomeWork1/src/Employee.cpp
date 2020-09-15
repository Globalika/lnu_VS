#include <iostream>
#include "Employee.h"

Employee::Employee(int age, std::string firstName, std::string secondName)
{
	this->age = age;
	this->firstName = firstName;
	this->secondName = secondName;
}

void Employee::SetEmloyeeAge(int age)
{
	this->age = age;
}

void Employee::SetEmloyeeAge()
{
	int age;
	std::cin >> age;
	this->age = age;
}

void Employee::SetEmloyeeFirstName(int firstName)
{
	this->firstName = firstName;
}

void Employee::SetEmloyeeSecondName(int secondName)
{
	this->secondName = secondName;
}

void Employee::PrintEmployeeInfo()
{
	std::cout << "Employee First Name : " << this->firstName
		<< " Second Name : " << this->secondName
		<< " Age : " << this->age << std::endl;
}

int Employee::GetEmployeeAge()
{
	return this->age;
}

std::string Employee::GetEmployeeFirstName()
{
	return this->firstName;
}

std::string Employee::GetEmployeeSecondName()
{
	return this->secondName;
}
