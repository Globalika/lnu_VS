#pragma once
#include <iostream>
#include <string>
using namespace std;

class Contract
{
public:
	string name;
	virtual void PrintInfo() = 0;
};