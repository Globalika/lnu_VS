#pragma once
#include <string>
#include <vector>

#include "Database.h"
//#include "BaseTable.h"
#include "MedicinesProduct.h"

class MedicinesTable /*: public Table*/
{
public:
	MedicinesTable();
	bool IsProductExist(MedicinesProduct& product);////////////////////////
	void Create(MedicinesProduct product);
	void Update(MedicinesProduct& product);
	MedicinesProduct* GetById(int id);
	std::vector<MedicinesProduct> GetAll();
	void Delete(int id);
	void Save();
	void MoveProbuctByIdUp();
	void MoveProbuctByIdDown();
	std::vector<std::vector<std::string>>* GetContentFromProductsvector(std::vector<MedicinesProduct>& products);

	const static std::string tableName;
	Database* GetDatabase();
private:
	int currentId;
	std::vector<MedicinesProduct>* products;
	Database* database;
};
