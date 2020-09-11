#pragma once
#include <string>
#include <vector>

#include "Database.h"
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
	std::vector<std::vector<std::string>>* GetContentFromProductsvector(std::vector<MedicinesProduct>& products);

	const static std::string tableName;
	Database* GetDatabase();
private:
	std::vector<MedicinesProduct>* products;
	Database* database;
};
