#include <iostream>
#include "Database.h"
#include <fstream>
#include <sstream>
//
std::ostream& operator<<(std::ostream& os, std::vector<std::string>& productVec)
{
	if (productVec.size() == 5)
	{
		os << productVec.at(0) << ',' << productVec.at(1) << ','
			<< productVec.at(2) << ',' << productVec.at(3) << ',' << productVec.at(4);
	}
	else if (productVec.size() == 6)
	{
		os << productVec.at(0) << ',' << productVec.at(1) << ','
			<< productVec.at(2) << ',' << productVec.at(3) << ',' 
			<< productVec.at(4) << ',' << productVec.at(5);
	}
	else if (productVec.size() == 3)
	{
		os << productVec.at(0) << ',' << productVec.at(1) << ',' << productVec.at(2);
	}
	return os;
}
//
std::string Database::CreateTableFilePath(std::string tableName)
{
	return "C:/Users/volod/source/lnu_VS/Individual/Task1MyPharmacy/Task1MyPharmacy/tablefiles/" + tableName + ".txt";
}


void Database::UpdateTableContent(std::vector<std::vector<std::string>>& content, std::string tableName)
{

	std::string filePath = CreateTableFilePath(tableName);
	std::ofstream fout;
	fout.open(filePath);

	if (!fout.is_open())
	{
		std::cout << "open file error" << std::endl;
	}
	else
	{
		if (content.size() != 0)
		{
			int i = 0;
			for (; i < content.size() - 1; i++)
			{
				fout << content.at(i) << '\n';
			}
			fout << content.at(i);
		}
	}
	fout.close();

}

std::vector<std::vector<std::string>>* Database::GetTableContent(std::string tableName)
{
	std::string filePath = Database::CreateTableFilePath(tableName);
	std::vector<std::vector<std::string>>* content = new std::vector<std::vector<std::string>>();
	std::vector<std::string> stringOfContent;//
	std::ifstream fin;
	fin.open(filePath);///

	if (!fin.is_open())
	{
		std::cout << "open file error" << std::endl;
	}
	else
	{
		std::string str, token;
		while (!fin.eof())
		{
			str = "";
			/*while (str == "")
			{
				getline(fin, str);
			}*/
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
			content->push_back(stringOfContent);
			stringOfContent.clear();
		}
	}
	fin.close();

	return content;
}