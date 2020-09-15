#pragma once
#ifndef _MEDICINES_TABLE_
#define _MEDICINES_TABLE_
#include <string>
#include <vector>
#include "Database.h"
#include "MedicinesProduct.h"

class MedicinesTable /*public Table*/
{
public:
	MedicinesTable();
	bool IsProductExist(MedicinesProduct& product);
	void Create(MedicinesProduct product);
	void Update(MedicinesProduct& product);
	MedicinesProduct* GetById(int id);
	std::vector<MedicinesProduct> GetAll();
	void Delete(int id);
	void Save();
	std::vector<std::vector<std::string>>* GetContentFromProductsvector(std::vector<MedicinesProduct>& products);

	const static std::string tableName;
	Database* GetDatabase();
	~MedicinesTable();
private:
	std::vector<MedicinesProduct>* products;
	Database* database;
};
#endif _MEDICINES_TABLE_