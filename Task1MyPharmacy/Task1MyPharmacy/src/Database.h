#pragma once
//#include "BaseTable.h"
#ifndef _DATABASE_
#define _DATABASE_
#include <string>
#include <vector>
class Database
{
public:
	//Database() {}
	std::vector<std::vector<std::string>>* GetTableContent(std::string tableName);
	std::string CreateTableFilePath(std::string tableName);
	void UpdateTableContent(std::vector<std::vector<std::string>>& content, std::string tableName);
	
	//~Database() {}
private:

};

#endif _DATABASE_