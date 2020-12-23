#pragma once
#include <iostream>
#include "BuiltContract.h"
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <conio.h>
using namespace std;
bool predicateSortBySum(const BuiltContract* a, const BuiltContract* b)
{
	return a->sum > b->sum;
}
class BuildingOrganization
{
public:
	int budget;
	vector<BuiltContract*>* contracts;
	enum buildingProcessState {started, inProcess, ended};
	buildingProcessState state;

	void SetBuildingProcessState(buildingProcessState state)
	{
		this->state = state;
	}
	string GetBuildingProcessState()
	{
		int count = 0;
		for (auto it : *contracts)
		{
			if (*(it->signContract))
			{
				count++;
			}
		}
		if (count == 0)
		{
			SetBuildingProcessState(buildingProcessState::started);
			return "Buliding has been started!";
		}
		else if (count == contracts->size())
		{
			SetBuildingProcessState(buildingProcessState::ended);			
			return "Buliding has been ended!";
		}
		else
		{
			SetBuildingProcessState(buildingProcessState::inProcess);
			return "Buliding is in progress!";
		}
	}


	void SordContractsBySum()
	{
		std::sort(contracts->begin(),contracts->end(),predicateSortBySum);
	}
	void SortContractsById()
	{
		sort(contracts->begin(), contracts->end(), [](const BuiltContract* a,const BuiltContract* b)
			{
				return a->contractId > b->contractId;
			});
	}
	BuildingOrganization(string filename, int money);
	BuildingOrganization()
	{
		contracts = new vector<BuiltContract*>;
		budget = 0;
		buildingProcessState state = buildingProcessState::started;
	}
	void WriteInFile(string filename);
	void SignContractById(int ID)
	{
		for (auto it : *contracts)
		{
			if (it->contractId == ID)
			{
				it->SighContract();
			}
		}
	} 
	string MakePath(string name)
	{
		return name + ".txt";
	}
	BuiltContract* CreateContractFromVector(vector<string> v);
	vector<string> CreateVectorFromContract(BuiltContract& contract);
	void UpdateBudget(int amount)
	{
		bool isTrue = true;
		while (isTrue)
		{
			if (budget < 0)
			{
				cout << "Budget can`t affort that contract!" << endl;
				break;
			}
			try
			{
				isTrue = false;
				BudgetCheck(budget+amount);
			}
			catch (const std::exception& err)
			{
				cout << "Budget will be empty! Are you sure u want to sign this contract? | 1-Yes() 0-No()" << std::endl;
				if (_getch() - 48 != 0)
				{
					budget += amount;
				}
			}
		}
	}
	void BudgetCheck(int amount)
	{
		if (amount < 0)
		{
			throw std::exception();
		}
	}
	int GetBudget() 
	{ 
		return budget;
	}
	~BuildingOrganization() 
	{
		for (auto it : *contracts)
		{
			delete it;
		}
		delete contracts;
		cout << "BuildingOrganization has been deleted!" << endl;
	}

	void PrintInfo()
	{
		for (auto it : *contracts)
		{
			it->PrintInfo();
			cout << endl;
		}
	}

};

std::ostream& operator<<(std::ostream& os, std::vector<std::string>& vec)
{
	os << vec.at(0) << ',' << vec.at(1) << ','
		<< vec.at(2) << ',' << vec.at(3) << ',' << vec.at(4);
	return os;
}

BuildingOrganization::BuildingOrganization(string filename, int money)
{
	contracts = new vector<BuiltContract*>;
	budget = money;
	buildingProcessState state = buildingProcessState::started;
	//ifstream fin;
	//fin.open(MakePath(filename));
	try
	{
		fstream fin;
		fin.open(MakePath(filename));
		fin.exceptions(/*ifstream::eofbit |*/ ifstream::failbit | ifstream::badbit);
		vector<string> stringOfContent;
		string str,token;
		while (!fin.eof())
		{
			str = "";
			getline(fin, str);
			std::istringstream ss(str);
			while (std::getline(ss, token, ','))
			{
				stringOfContent.push_back(token);
			}
			if (stringOfContent.size() == 0)
			{
				break;
			}
			contracts->push_back(CreateContractFromVector(stringOfContent));//
			stringOfContent.clear();
		}
		fin.close();
	}
	catch (std::exception const& e)
	{
		cout << "There was an error: " << e.what() << endl;
	}
	//if (!fin.is_open())
	//{//trycatch
	//	cout << "open file error" << endl;
	//}
	//else
	//{
	//	cout << "file open" << endl;
	//	vector<string> stringOfContent;
	//	string str,token;
	//	while (!fin.eof())
	//	{
	//		str = "";
	//		getline(fin, str);
	//		std::istringstream ss(str);
	//		while (std::getline(ss, token, ','))
	//		{
	//			stringOfContent.push_back(token);
	//		}
	//		if (stringOfContent.size() == 0)
	//		{
	//			break;
	//		}
	//		contracts->push_back(CreateContractFromVector(stringOfContent));//
	//		stringOfContent.clear();
	//	}
	//}
	//fin.close();
}

BuiltContract* BuildingOrganization::CreateContractFromVector(vector<string> v)
{
	int ID, sum;
	std::istringstream ss1(v.at(1));
	ss1 >> ID;
	ss1.clear();
	std::istringstream ss2(v.at(2));
	ss2 >> sum;
	ss2.clear();
	BuiltContract* contract = new BuiltContract(v.at(0),ID,sum,v.at(3),v.at(4));
	return contract;
}

vector<string> BuildingOrganization::CreateVectorFromContract(BuiltContract& contract)
{
	vector<string> v;
	v.push_back(contract.name);
	v.push_back(to_string(contract.contractId));
	v.push_back(to_string(contract.sum));
	v.push_back(contract.client);
	v.push_back(contract.performer);
	return v;
}

void BuildingOrganization::WriteInFile(string filename)
{
	ofstream fout;
	fout.open(MakePath(filename));
	if (!fout.is_open())
	{//trycatch
		cout << "open file error" << endl;
	}
	else
	{
		cout << "file open" << endl;
		vector<string> vec;
		for (int i = 0; i < contracts->size(); i++)
		{
			vec = CreateVectorFromContract(*contracts->at(i));
			if (i == contracts->size() - 1)
				fout << vec;
			else
				fout << vec << "\n";
			vec.clear();
		}
	}
	fout.close();
}