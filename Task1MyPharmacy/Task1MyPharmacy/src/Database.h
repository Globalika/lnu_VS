#pragma once
#ifndef _DATABASE_
#define _DATABASE_
#include <vector>
class Database
{
public:
	std::vector<std::vector<std::string>>* GetTableContent(std::string tableName);
	std::string CreateTableFilePath(std::string tableName);
	void UpdateTableContent(std::vector<std::vector<std::string>>& content, std::string tableName);
private:

};

#endif _DATABASE_