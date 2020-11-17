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
//
//bool MedicinesTable::IsProductExist(MedicinesProduct& product)
//{
//	auto it = std::find_if(products->begin(), products->end(), [product](const MedicinesProduct* p)
//		{
//			return p->id == product.id;
//		});
//	return it == products->end();
//}
//
//void MedicinesTable::Create(MedicinesProduct& product)
//{
//	MedicinesProduct& mp = dynamic_cast<MedicinesProduct&>(product);
//	products->push_back(&mp);
//	Save();
//}
//
//void MedicinesTable::Update(MedicinesProduct& product)
//{
//	MedicinesProduct* pr = dynamic_cast<MedicinesProduct*>(&product);
//	std::replace_if(products->begin(), products->end(), [pr](const MedicinesProduct* p)
//	{
//		return (p->id == pr->id);
//	}, pr);
//	Save();
//}
//
//std::vector<MedicinesProduct*>* MedicinesTable::GetAll()
//{
//	std::vector<MedicinesProduct*>* v = new std::vector<MedicinesProduct*>();
//	for (auto it : *products)
//	{
//		MedicinesProduct* p = /*dynamic_cast<MedicinesProduct*>(it)*/it;
//		v->push_back(p);
//	}
//	return v;
//}
//
//MedicinesProduct* MedicinesTable::GetById(int id)
//{
//	auto result = std::find_if(products->begin(), products->end(), [id](const MedicinesProduct* product)
//		{
//			return product->id == id;
//		});
//		return *result;
//}
//
//void MedicinesTable::Delete(int id)
//{
//	auto result = std::remove_if(products->begin(), products->end(), [id](const MedicinesProduct* product)
//		{
//				return product->id == id;
//		});
//	products->erase(result, products->end());
//	Save();
//}
//
void MedicinesTable::Save()
{
	database->UpdateTableContent(*GetContentFromProductsVector(*products), medicinesTableName);
}
//
//
//
//std::vector<std::vector<std::string>>* MedicinesTable::GetContentFromProductsVector(std::vector<MedicinesProduct*>& products)
//{
//	std::vector<std::vector<std::string>>* vector = new std::vector<std::vector<std::string>>;
//	std::vector<std::string> str;
//	for (auto it : products)
//	{
//		MedicinesProduct& mp = dynamic_cast<MedicinesProduct&>(*it);
//		str = MedicinesProduct::GetvectorStringFromProduct(mp);
//		vector->push_back(str);
//		str.clear();
//	}
//
//	return vector;
//}
//
//Database* MedicinesTable::GetDatabase()
//{
//	return this->database;
//}
//
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