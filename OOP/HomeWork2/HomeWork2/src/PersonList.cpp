#include "PersonList.h"
#include <iostream>
using namespace std;

PersonList::PersonList(int maxLen)
{
	if (maxLen <= 0)
		throw "Max len should be greater then 0!!";

	persons = new Person[maxLen];
	lastPersonIdx = -1;
	this->maxLen = maxLen;
}


//-----------------------------------------------------COPY CONSTRUCTOR
PersonList::PersonList(const PersonList& other)
{
	this->lastPersonIdx = other.lastPersonIdx;
	this->maxLen = other.maxLen;
	
	this->persons = new Person[maxLen];
	for (int i = 0; i < maxLen; i++)
	{
		persons[i] = other.persons[i];
	}
}
//-------------------------------------------------------


PersonList::~PersonList()
{
	delete[]persons;
}

void PersonList::Add(const Person& p)
{
	if (lastPersonIdx >= maxLen)
		throw "No memory for persons!!";

	persons[++lastPersonIdx] = p;
}


void PersonList::Write()
{
	cout << "Persons: " << endl;
	for (int i = 0; i <= lastPersonIdx; i++)
	{
		persons[i].WriteToConsole();
	}
}