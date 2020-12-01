#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>

#include "CartTable.h"

CartTable::CartTable()
{
	database = new Database();
	std::vector<std::vector<std::string>> stringvector = *database->GetTableContent(cartTableName);

	products = new std::vector<FlyweightProduct*>;

	for (auto it : stringvector)
	{
		auto var = FlyweightProduct::GetProductByStringVector(it);
		products->push_back(var);
	}
}

void CartTable::DeleteAll()
{
	products->clear();
	Save();
}

void CartTable::Save()
{
	database->UpdateTableContent(*GetContentFromProductsVector(*products), cartTableName);
}

CartTable::~CartTable()
{
	delete database;
	for (auto it : *products)
	{
		delete it;
	}
	delete products;
}

const std::string CartTable::cartTableName = "cartTable";