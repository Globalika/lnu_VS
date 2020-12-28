#pragma once//ne vustachulo chasu vsi prosti pomulku vapravutu..
#include <iostream>
#include "CaseOfACitizen.h"
#include <vector>//konteiner
#include <fstream>
#include <sstream>
#include <algorithm>//dlya sort
#include <conio.h>//getch
using namespace std;
bool predicateSortByCase(const CaseOfACitizen* a, const CaseOfACitizen* b)
{
	return a->citizenCase > b->citizenCase;
}
//Miska Rada maye " has a " spusok clasu sprav
class CityCouncil//Miska Rada
{
public:
	int deadline;//kontrol chasu
	vector<CaseOfACitizen*>* contracts;

	void SordContractsByCase()//sortuvannya za spravamu+ce predukat
	{
		std::sort(contracts->begin(), contracts->end(), predicateSortByCase);
	}
	void SortContractsById()//sortuvannya za id + functor
	{
		sort(contracts->begin(), contracts->end(), [](const CaseOfACitizen* a, const CaseOfACitizen* b)
			{
				return a->statementId > b->statementId;
			});
	}
	CityCouncil(string filename, int money);
	CityCouncil()
	{
		contracts = new vector<CaseOfACitizen*>;
		deadline = 0;
	}
	void WriteInFile(string filename);//zapus u fail
	void RegisterStatementById(int ID)
	{
		for (auto it : *contracts)
		{
			if (it->statementId == ID)
			{
				it->RegisterStatement();
			}
		}
	}
	string MakePath(string name)
	{
		return name + ".txt";
	}
	CaseOfACitizen* CreateContractFromVector(vector<string> v);
	vector<string> CreateVectorFromContract(CaseOfACitizen& contract);
	void AddStatementToAProcess(CaseOfACitizen& statement)//kontrol chasu + try catch
	{
		bool isTrue = true;
		while (isTrue)
		{
			if (deadline < 0)
			{
				cout << "Council can`t affort that statement!" << endl;
				break;
			}
			try
			{
				isTrue = false;
				DeadlineCheck(deadline - statement.citizenCase);
			}
			catch (const std::exception& err)
			{
				cout << "Council won`t accept more cases! Are you sure u want to register this statement? | 1-Yes() 0-No()" << std::endl;
				if (_getch() - 48 != 0)
				{
					deadline -= statement.citizenCase;
				}
			}
		}
	}
	void DeadlineCheck(int amount)
	{
		if (amount < 0)
		{
			throw std::exception();
		}
	}
	int GetDeadline()
	{
		return deadline;
	}
	~CityCouncil()
	{
		for (auto it : *contracts)
		{
			delete it;
		}
		delete contracts;
		cout << "CityCouncil has been deleted!" << endl;
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
{//operator dlya zruchnosti vuvodu u txt fail
	os << vec.at(0) << ',' << vec.at(1) << ','
		<< vec.at(2) << ',' << vec.at(3);
	return os;
}

CityCouncil::CityCouncil(string filename, int deadline)
{
	contracts = new vector<CaseOfACitizen*>;
	deadline = deadline;
	try
	{
		fstream fin;
		fin.open(MakePath(filename));
		fin.exceptions( ifstream::failbit | ifstream::badbit);
		vector<string> stringOfContent;
		string str, token;
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
}

CaseOfACitizen* CityCouncil::CreateContractFromVector(vector<string> v)
{
	int ID, citizenCase;
	std::istringstream ss1(v.at(0));
	ss1 >> ID;
	ss1.clear();
	std::istringstream ss2(v.at(1));
	ss2 >> citizenCase;
	ss2.clear();
	CaseOfACitizen* statement = new CaseOfACitizen(ID, citizenCase, v.at(2), v.at(3));
	return statement;
}

vector<string> CityCouncil::CreateVectorFromContract(CaseOfACitizen& contract)
{
	vector<string> v;
	v.push_back(to_string(contract.statementId));
	v.push_back(contract.GetCase(contract.citizenCase));
	v.push_back(contract.citizen);
	v.push_back(contract.cityPerformer);
	return v;
}

void CityCouncil::WriteInFile(string filename)//zapus u fail + try catch
{
	ofstream fout;
	fout.open(MakePath(filename));
	if (!fout.is_open())
	{
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