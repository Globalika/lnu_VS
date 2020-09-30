#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>

#include "MedicinesTable.h"
//#include "..\products\MedicinesProduct.h"

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

bool MedicinesTable::IsProductExist(Product& product)
{
	auto it = std::find_if(products->begin(), products->end(), [product](const Product* p)
		{
			return p->id == product.id;
		});
	return it == products->end();
}

void MedicinesTable::Create(Product& product)
{
	MedicinesProduct& mp = dynamic_cast<MedicinesProduct&>(product);
	products->push_back(&mp);
	Save();
}

void MedicinesTable::Update(Product& product)
{
	MedicinesProduct* pr = dynamic_cast<MedicinesProduct*>(&product);
	std::replace_if(products->begin(), products->end(), [pr](const MedicinesProduct* p)
	{
		return (p->id == pr->id);
	}, pr);
	Save();
}

std::vector<Product*>* MedicinesTable::GetAll()
{
	std::vector<Product*>* v = new std::vector<Product*>();
	for (auto it : *products)
	{
		Product* p = dynamic_cast<MedicinesProduct*>(it);
		v->push_back(p);
	}
	return v;
}

Product* MedicinesTable::GetById(int id)
{
	auto result = std::find_if(products->begin(), products->end(), [id](const Product* product)
		{
			return product->id == id;
		});
		return *result;
}

void MedicinesTable::Delete(int id)
{
	auto result = std::remove_if(products->begin(), products->end(), [id](const Product* product)
		{
				return product->id == id;
		});
	products->erase(result, products->end());
	Save();
}

void MedicinesTable::Save()
{
	database->UpdateTableContent(*GetContentFromProductsVector(*products), medicinesTableName);
}



std::vector<std::vector<std::string>>* MedicinesTable::GetContentFromProductsVector(std::vector<MedicinesProduct*>& products)
{
	std::vector<std::vector<std::string>>* vector = new std::vector<std::vector<std::string>>;
	std::vector<std::string> str;
	for (auto it : products)
	{
		MedicinesProduct& mp = dynamic_cast<MedicinesProduct&>(*it);
		str = MedicinesProduct::GetvectorStringFromProduct(mp);
		vector->push_back(str);
		str.clear();
	}

	return vector;
}

Database* MedicinesTable::GetDatabase()
{
	return this->database;
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