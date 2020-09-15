#include <string>
#include <iostream>
#include <cstring>
#include"Person.h"

using namespace std;


void Person::Init(string firstName, string lastName, const char* middleName, int age)
{
	this->firstName = firstName;
	this->lastName = lastName;
	this->age = age;

	int mnLen = strlen(middleName);
	this->middleName = new char[mnLen + 1]; //add '\0'
	strcpy_s(this->middleName, mnLen + 1, middleName);
}

Person::Person(string firstName, string lastName, const char* middleName, int age)
{
	cout << "Usual ctor" << endl;
	Init(firstName, lastName, middleName, age);
}

Person::Person(const Person& other)
{
	cout << "Copy ctor" << endl;
	Init(other.firstName, other.lastName, other.middleName, other.age);
}

Person& Person::operator= (const Person& other)
{
	cout << "Assignment operator" << endl;
	if (this == &other)
		return *this;

	delete[]middleName;
	Init(other.firstName, other.lastName, other.middleName, other.age);

	return *this;
}

string Person::GetFullName() const
{
	return firstName + " " + lastName;
}

void Person::WriteToConsole()
{
	cout << "Person: " << firstName << " " << middleName << " "
		<< lastName << ", age: " << age << endl;
}

int Person::GetAge() const
{
	return age;
}

void Person::SetAge(int age)
{
	this->age = age;
}

int Person::GetMaxAge()
{
	return 120;
}

string Person::getReverseFullName()
{
	return lastName + " " + firstName;
}

Person::~Person()
{
	delete[]middleName;
	cout << "Person: " << GetFullName() << " destroied!" << endl;
}
