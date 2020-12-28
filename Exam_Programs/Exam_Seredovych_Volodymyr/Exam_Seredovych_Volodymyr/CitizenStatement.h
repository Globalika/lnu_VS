#pragma once
#include "Statement.h"
#include <iostream>
#include <string>
using namespace std;

class CitizenStatement : public Statement // bazovui class 
{// statements "as "housingIssues...
public:
	bool* registerStatement;
	enum citizenCaseState 
	{ 
		housingIssues, 
		utilities, 
		issuanceOfLicenses, 
		paymentOfTaxes, 
		grantingBenefits,
		none
	};
	citizenCaseState state;
	string citizen;
	string cityPerformer;

	void SetBuildingProcessState(citizenCaseState state)
	{
		this->state = state;
	}
	CitizenStatement() : citizen(""), cityPerformer("")
	{
		registerStatement = new bool(false);
		this->statementId = 0;
		state = citizenCaseState::none;
	}
	CitizenStatement(int ID, string client, string performer)
		:citizen(citizen), cityPerformer(cityPerformer)
	{
		registerStatement = new bool(false);
		this->statementId = ID;
		state = citizenCaseState::none;
	}
	CitizenStatement& operator= (const CitizenStatement& other)
	{
		this->statementId = other.statementId;
		this->registerStatement = other.registerStatement;
		this->citizen = other.citizen;
		this->cityPerformer = other.cityPerformer;
		this->state = other.state;
		return *this;
	}
	CitizenStatement(const CitizenStatement& other)
	{
		this->statementId = other.statementId;
		this->registerStatement = other.registerStatement;
		this->citizen = other.citizen;
		this->cityPerformer = other.cityPerformer;
		this->state = other.state;
	}

	void PrintInfo() override
	{
		cout << "Contract ID : " << statementId << " | client : " << citizen
			<< " | performer : " << cityPerformer << " |  : " << (registerStatement ? " registered " : " unregistered ");
	}
	~CitizenStatement()
	{
		cout << "CitizenStatement with ID : '" << statementId << "' has been deleted!" << endl;
	}
};