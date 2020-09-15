#pragma once
#include <string>

class Employee
{
public:
	Employee(int age, std::string firstName, std::string secondName);
	void SetEmloyeeAge(int age);
	void SetEmloyeeAge();
	void SetEmloyeeFirstName(int firstName);
	void SetEmloyeeSecondName(int secondName);
	void PrintEmployeeInfo();
	int GetEmployeeAge();
	std::string GetEmployeeFirstName();
	std::string GetEmployeeSecondName();
private:
	int age;
	std::string firstName;
	std::string secondName;
};