#include <iostream>
using namespace std;

#include "CaseOfACitizen.h"
#include "СityСouncil.h"
int main()
{
	CityCouncil council("caseOfCitizenInput",43);
	council.PrintInfo();
	council.RegisterStatementById(7854);
	council.SordContractsByCase();
	council.WriteInFile("caseOfCitizenOutput");
	return 0;
}