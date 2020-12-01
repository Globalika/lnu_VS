#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>

#include "CosmeticsTable.h"

CosmeticsTable::CosmeticsTable()
{
	database = new Database();
	std::vector<std::vector<std::string>> stringvector = *database->GetTableContent(cosmeticsTableName);
	products = new std::vector<CosmeticsProduct*>;

	for (auto it : stringvector)
	{
		auto var = CosmeticsProduct::GetProductByStringVector(it);
		products->push_back(var);
	}
}

void CosmeticsTable::Save()
{
	database->UpdateTableContent(*GetContentFromProductsVector(*products), cosmeticsTableName);
}

CosmeticsTable::~CosmeticsTable()
{
	delete database;
	for (auto it : *products)
	{
		delete it;
	}
	delete products;
}

const std::string CosmeticsTable::cosmeticsTableName = "cosmeticsTable";