#pragma once
#include<string>
#include "Person.h"

using namespace std;

#ifndef _PERSONLIST_H_
#define _PERSONLIST_H_
//
class PersonList
{
private:
	Person* persons;
	int lastPersonIdx;
	int maxLen;
public:
	PersonList(int maxLen);
	PersonList(const PersonList& other);
	~PersonList();

	void Add(const Person& p);
	void Write();
};

#endif _PERSONLIST_H_