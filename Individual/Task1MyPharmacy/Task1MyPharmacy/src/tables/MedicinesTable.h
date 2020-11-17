#pragma once
#ifndef _MEDICINES_TABLE_
#define _MEDICINES_TABLE_
#include <string>
#include <vector>
#include "BaseTable.h"
#include "..\products/MedicinesProduct.h"

class MedicinesTable : public Table <MedicinesProduct>
{
public:
	MedicinesTable();

	//bool IsProductExist(MedicinesProduct& product) override;
	//void Create(MedicinesProduct& product) override;
	//void Update(MedicinesProduct& product) override;
	//MedicinesProduct* GetById(int id) override;
	//std::vector<MedicinesProduct*>* GetAll() override;
	//void Delete(int id) override;
	void Save() override;
	//Database* GetDatabase() override;

	~MedicinesTable();


	const static std::string medicinesTableName;
private:
	//std::vector<std::vector<std::string>>* GetContentFromProductsVector(std::vector<MedicinesProduct*>& products);
	//std::vector<MedicinesProduct*>* products;
	//Database* database;
};
#endif _MEDICINES_TABLE_