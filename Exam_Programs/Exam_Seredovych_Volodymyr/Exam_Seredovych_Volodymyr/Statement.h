#pragma once
#include <iostream>
#include <string>
using namespace std;

class Statement //abstractnui class
{
public:
	int statementId;
	virtual void PrintInfo() = 0;
};