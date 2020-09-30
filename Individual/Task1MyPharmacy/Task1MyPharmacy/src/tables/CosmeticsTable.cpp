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

bool CosmeticsTable::IsProductExist(Product& product)
{
	auto it = std::find_if(products->begin(), products->end(), [product](const Product* p)
		{
			return p->id == product.id;
		});
	return it == products->end();
}

void CosmeticsTable::Create(Product& product)
{
	CosmeticsProduct& cp = dynamic_cast<CosmeticsProduct&>(product);
	products->push_back(&cp);
	Save();
}

void CosmeticsTable::Update(Product& product)
{
	CosmeticsProduct* pr = dynamic_cast<CosmeticsProduct*>(&product);
	std::replace_if(products->begin(), products->end(), [pr](const CosmeticsProduct* p)
		{
			return (p->id == pr->id);
		}, pr);
	Save();
}

std::vector<Product*>* CosmeticsTable::GetAll()
{
	std::vector<Product*>* v = new std::vector<Product*>();
	for (auto it : *products)
	{
		Product* p = dynamic_cast<CosmeticsProduct*>(it);
		v->push_back(p);
	}
	return v;
}

Product* CosmeticsTable::GetById(int id)
{
	auto result = std::find_if(products->begin(), products->end(), [id](const Product* product)
		{
			return product->id == id;
		});
	return *result;
}

void CosmeticsTable::Delete(int id)
{
	auto result = std::remove_if(products->begin(), products->end(), [id](const Product* product)
		{
			return product->id == id;
		});
	products->erase(result, products->end());
	Save();
}

void CosmeticsTable::Save()
{
	database->UpdateTableContent(*GetContentFromProductsVector(*products), cosmeticsTableName);
}



std::vector<std::vector<std::string>>* CosmeticsTable::GetContentFromProductsVector(std::vector<CosmeticsProduct*>& products)
{
	std::vector<std::vector<std::string>>* vector = new std::vector<std::vector<std::string>>;
	std::vector<std::string> str;
	for (auto it :products)
	{
		CosmeticsProduct& cp = dynamic_cast<CosmeticsProduct&>(*it);
		str = CosmeticsProduct::GetvectorStringFromProduct(cp);
		vector->push_back(str);
		str.clear();
	}

	return vector;
}

Database* CosmeticsTable::GetDatabase()
{
	return this->database;
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