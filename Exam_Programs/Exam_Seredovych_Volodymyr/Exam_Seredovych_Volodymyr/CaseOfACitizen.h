#pragma once
#include <iostream>
#include <string>
#include "CitizenStatement.h"
using namespace std;

class CaseOfACitizen : public CitizenStatement // class naschadok 
{// "is a" statement..
public:
	int citizenCase;
	CaseOfACitizen()
		: citizenCase(0), CitizenStatement() {}
	CaseOfACitizen( int ID, int citizenCase, string citizen, string performer)
		: citizenCase(citizenCase), CitizenStatement(ID, citizen, performer) {}
	CaseOfACitizen& operator= (const CaseOfACitizen& other)
	{
		this->statementId = other.statementId;
		this->registerStatement = other.registerStatement;
		this->citizen = other.citizen;
		this->cityPerformer = other.cityPerformer;
		this->citizenCase = other.citizenCase;
		return *this;
	}
	CaseOfACitizen (const CaseOfACitizen& other)
	{
		this->statementId = other.statementId;
		this->registerStatement = other.registerStatement;
		this->citizen = other.citizen;
		this->cityPerformer = other.cityPerformer;
		this->citizenCase = other.citizenCase;
	}
	string GetCase(int state)
	{
		switch (citizenCase)
		{
			case 1:
			{
				return "housingIssues";
				break;
			}
			case 2:
			{
				return "utilities";
				break;
			}
			case 3:
			{
				return "issuanceOfLicenses";
				break;
			}
			case 4:
			{
				return "paymentOfTaxes";
				break;
			}
			case 5:
			{
				return "grantingBenefits";
				break;
			}
			default :
			{
				return "none";
				break;
			}
		}
	}
	void RegisterStatement()
	{
		*registerStatement = true;
	}
	void PrintInfo() override
	{
		cout << "Statement ID : " << statementId << " | Citizen Case : " << GetCase(citizenCase)
			<< " | citizen : " << citizen << " | performer : " << cityPerformer
			<< " |  : " << (*registerStatement ? " registered " : " unregistered ");
	}

	~CaseOfACitizen()
	{
		cout << "CaseOfACitizen with ID : '" << statementId << "' has been deleted!" << endl;
	}
};