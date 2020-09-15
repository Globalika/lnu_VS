#pragma once
#include<string>
using namespace std;

#ifndef _PERSON_H_
#define _PERSON_H_

class Person
{
public:
	//constructor
	Person(string firstName = "", string = "", const char* middleName = "", int = 0);
	Person(const Person& other);

	//assignment operator
	Person& operator= (const Person& other);

	//methods
	string GetFullName() const;
	void WriteToConsole();
	int GetAge() const;
	void SetAge(int);
	static int GetMaxAge();
	~Person();
private:
	string firstName;
	string lastName;
	char* middleName;
	int age;

	string getReverseFullName();
	void Init(string firstName, string, const char*, int);
};

#endif _PERSON_H_