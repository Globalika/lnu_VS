#include <iostream>
using namespace std;
#include "bilateralContract.h"
#include "Organization.h"
int main()
{
	BuildingOrganization myOrganization("contractsInfoInput", 1200);
	//cout << myOrganization.GetBuildingProcessState() << endl;
	myOrganization.PrintInfo();
	myOrganization.SignContractById(433);
	myOrganization.PrintInfo();
	//myOrganization.SortContractsById();
	myOrganization.SordContractsBySum();
	//cout << myOrganization.GetBuildingProcessState() << endl;
	myOrganization.PrintInfo();
	myOrganization.WriteInFile("contractsInfoOutput");
	return 0;
}