#include <iostream>
#include "Database.h"
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
//
std::ostream& operator<<(std::ostream& os, std::vector<std::string>& productVec)
{
	os << productVec.at(0) << ',' << productVec.at(1) << ',' 
	   << productVec.at(2) << ',' << productVec.at(3) << ',' << productVec.at(4);
	return os;
}
//
std::string Database::CreateTableFilePath(std::string tableName)
{
	return "tablefiles/" + tableName + ".txt";
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
		int i = 0;
		for (;i < content.size()-1;i++)
		{
			fout << content.at(i) << '\n';
		}
		fout << content.at(i);
	}
	fout.close();

}

std::vector<std::vector<std::string>>* Database::GetTableContent(std::string tableName)
{
	std::string filePath = Database::CreateTableFilePath(tableName);
	std::vector<std::vector<std::string>>* content = new std::vector<std::vector<std::string>>();
	std::vector<std::string> stringOfContent;//
	std::ifstream fin;
	fin.open(filePath);

	/*try
	{
		fin.open(filePath);
	}
	catch (const std::ifstream::failure& ex)
	{
		std::cout << ex.what() << std::endl;
		std::cout << ex.code() << std::endl;
		std::cout << "cannot open file" << std::endl;
	}*/

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
			while (str == "")
			{
				getline(fin, str);
			}
			std::istringstream ss(str);
			while (std::getline(ss, token, ','))
			{
				stringOfContent.push_back(token);		
			}
			content->push_back(stringOfContent);
			stringOfContent.clear();
		}
	}
	fin.close();

	return content;
}