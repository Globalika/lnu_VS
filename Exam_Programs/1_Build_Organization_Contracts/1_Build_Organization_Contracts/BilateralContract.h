#pragma once
#include "contract.h"
#include <iostream>
#include <string>
using namespace std;

class BilateralContract : public Contract
{
public:
	int contractId;
	bool* signContract;

	BilateralContract() : client(""),performer("")
	{
		signContract = new bool(false);
		this->name = "";
	}
	BilateralContract(string name, int ID, string client, string performer) 
		:contractId(ID), client(client), performer(performer)
	{
		signContract = new bool(false);
		this->name = name;
	}
	BilateralContract & operator= (const BilateralContract& other)
	{
		this->contractId = other.contractId;
		this->signContract = other.signContract;
		this->client = other.client;
		this->performer = other.performer;
		this->name = other.name;
	}

	string client;
	string performer;

	void PrintInfo() override 
	{
		cout << "Contract ID : " << contractId << " | name : " << name << " | client : " << client
			<< " | performer : " << performer << " |  : " << (signContract ?  " signed ": " unsighed ");
	}
	~BilateralContract() 
	{
		cout << "BilateralContract with name : '" << name << "' has been deleted!" << endl;
	}
};