#pragma once
#ifndef _MEDICINES_TABLE_
#define _MEDICINES_TABLE_
#include <string>
#include <vector>
#include "BaseTable.h"
#include "..\products/MedicinesProduct.h"

class MedicinesTable : public Table
{
public:
	MedicinesTable();

	bool IsProductExist(Product& product) override;
	void Create(Product& product) override;
	void Update(Product& product) override;
	Product* GetById(int id) override;
	std::vector<Product*>* GetAll() override;
	void Delete(int id) override;
	void Save() override;
	Database* GetDatabase() override;

	~MedicinesTable();


	const static std::string medicinesTableName;
private:
	std::vector<std::vector<std::string>>* GetContentFromProductsVector(std::vector<MedicinesProduct*>& products);
	std::vector<MedicinesProduct*>* products;
	Database* database;
};
#endif _MEDICINES_TABLE_