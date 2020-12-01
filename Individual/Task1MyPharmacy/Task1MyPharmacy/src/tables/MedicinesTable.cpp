#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>

#include "MedicinesTable.h"

MedicinesTable::MedicinesTable()
{
	database = new Database();
	std::vector<std::vector<std::string>> stringvector = *database->GetTableContent(medicinesTableName);
	products = new std::vector<MedicinesProduct*>;

	for (auto it : stringvector)
	{
		auto var = MedicinesProduct::GetProductByStringVector(it);
		products->push_back(var);
	}
}
void MedicinesTable::Save()
{
	database->UpdateTableContent(*GetContentFromProductsVector(*products), medicinesTableName);
}
MedicinesTable::~MedicinesTable()
{
	delete database;
	for (auto it : *products)
	{
		delete it;
	}
	delete products;
}

const std::string MedicinesTable::medicinesTableName = "medicinesTable";