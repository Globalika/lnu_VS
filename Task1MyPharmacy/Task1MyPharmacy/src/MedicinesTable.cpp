#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>

#include "MedicinesTable.h"
#include "MedicinesProduct.h"
//#include "Database.h"

MedicinesTable::MedicinesTable()
{
	database = new Database();
	currentId = this->products->at(0).id;
	std::vector<std::vector<std::string>> stringvector = *database->GetTableContent(tableName);

	products = new std::vector<MedicinesProduct>;
	for (auto it : stringvector)
	{
		//product = product->GetProductByStringvector(&it);
		auto var = MedicinesProduct::GetProductByStringvector(it);
		////////
		Create(var);
		//products->push_back(var);
	}
}

bool MedicinesTable::IsProductExist(MedicinesProduct& product)
{
	auto it = std::find_if(products->begin(), products->end(), [product](const MedicinesProduct& p)
		{
			return p.id == product.id;
		});
	return it == products->end();
}

void MedicinesTable::Create(MedicinesProduct product)
{
	products->push_back(product);
}

void MedicinesTable::Update(MedicinesProduct& product)
{
	std::replace_if(products->begin(), products->end(), [product](const MedicinesProduct& p)
	{
		return (p.id == product.id);
	}, product);
}

std::vector<MedicinesProduct> MedicinesTable::GetAll()
{
	return *products;
}

MedicinesProduct* MedicinesTable::GetById(int id)
{
	auto result = std::find_if(products->begin(), products->end(), [id](const MedicinesProduct& product)
		{
			return product.id == id;
		});
		return &*result;
}

void MedicinesTable::Delete(int id)
{
	auto result = std::remove_if(products->begin(), products->end(), [id](const MedicinesProduct& product)
		{
				return product.id == id;
		});
	products->erase(result, products->end());
}

void MedicinesTable::Save()
{
	database->UpdateTableContent(*GetContentFromProductsvector(*products), tableName);
}

void MedicinesTable::MoveProbuctByIdDown()
{
	int k = this->currentId;
	auto i = std::find_if(this->products->begin(), products->end(), [k](const MedicinesProduct& m) {////////////
		return m.id == k;
		});
	i++;
}

void MedicinesTable::MoveProbuctByIdDown()
{
}

std::vector<std::vector<std::string>>* MedicinesTable::GetContentFromProductsvector(std::vector<MedicinesProduct>& products)
{
	std::vector<std::vector<std::string>>* vector = new std::vector<std::vector<std::string>>;
	std::vector<std::string> str;
	for (auto it : products)
	{

		str = MedicinesProduct::GetvectorStringFromProduct(it);
		vector->push_back(str);
		str.clear();
	}

	return vector;
}

Database* MedicinesTable::GetDatabase()
{
	return database;
}

const std::string MedicinesTable::tableName = "medicinesTable";