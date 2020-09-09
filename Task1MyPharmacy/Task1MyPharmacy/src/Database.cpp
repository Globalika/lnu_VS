#include <iostream>
#include "Database.h"
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

std::string Database::CreateTableFilePath(std::string tableName)
{
	return "tablefiles/" + tableName + ".txt";
}


void Database::UpdateTableContent(std::vector<std::vector<std::string>>& content, std::string tableName)////////////
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
		std::cout << "open file" << std::endl;
		for (auto i : content)
		{
			for (auto it : i)
			{
				fout << it + ',';
			}
			fout << '\n';
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
	fin.open(filePath);
	if (!fin.is_open())
	{
		std::cout << "open file error" << std::endl;
	}
	else
	{
		std::cout << "file open" << std::endl;
		std::string str, token;
		while (!fin.eof())
		{
			str = "";
			getline(fin, str);
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