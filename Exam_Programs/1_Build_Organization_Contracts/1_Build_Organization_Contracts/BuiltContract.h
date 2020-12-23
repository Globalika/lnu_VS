#pragma once
#include <iostream>
#include <string>
#include "bilateralcontract.h"
using namespace std;

class BuiltContract : public BilateralContract
{
public:
	int sum;

	BuiltContract() 
		: sum(sum), BilateralContract() {}
	BuiltContract(string name, int ID, int sum, string client, string performer) 
		: sum(sum),BilateralContract(name, ID, client, performer) {}
	BuiltContract& operator= (const BuiltContract& other)
	{
		this->contractId = other.contractId;
		this->signContract = other.signContract;
		this->client = other.client;
		this->performer = other.performer;
		this->name = other.name;
		this->sum = other.sum;
		return *this;
	}

	void SighContract()
	{ 
		*signContract = true;
	}
	void PrintInfo() override
	{
		cout << "Contract ID : " << contractId << " | name : " << name 
			<< " | client : " << client	<< " | performer : " << performer
			<< " | sum : " << sum << " |  : " << (*signContract ? " signed " : " unsighed ");
	}

	~BuiltContract() 
	{
		cout << "BuiltContract with name : '" << name <<"' has been deleted!" << endl;
	}
};