#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>

#include "CartTable.h"
//#include "..\products\CartProduct.h"

CartTable::CartTable()
{
	database = new Database();
	std::vector<std::vector<std::string>> stringvector = *database->GetTableContent(cartTableName);
	products = new std::vector<CartProduct*>;

	for (auto it : stringvector)
	{
		auto var = CartProduct::GetProductByStringVector(it);
		products->push_back(var);
	}
}

//bool CartTable::IsProductExist(CartProduct& product)
//{
//	auto it = std::find_if(products->begin(), products->end(), [product](const CartProduct* p)
//		{
//			return p->id == product.id;
//		});
//	return it == products->end();
//}
//
//void CartTable::Create(CartProduct& product)
//{
//	CartProduct& mp = dynamic_cast<CartProduct&>(product);
//	products->push_back(&mp);
//	Save();
//}
//
//void CartTable::Update(CartProduct& product)
//{
//	CartProduct* pr = dynamic_cast<CartProduct*>(&product);
//	std::replace_if(products->begin(), products->end(), [pr](const CartProduct* p)
//		{
//			return (p->id == pr->id);
//		}, pr);
//	Save();
//}
//
//std::vector<CartProduct*>* CartTable::GetAll()
//{
//	std::vector<CartProduct*>* v = new std::vector<CartProduct*>();
//	for (auto it : *products)
//	{
//		CartProduct* p = it;
//		v->push_back(p);
//	}
//	return v;
//}
//
//CartProduct* CartTable::GetById(int id)
//{
//	auto result = std::find_if(products->begin(), products->end(), [id](const CartProduct* product)
//		{
//			return product->id == id;
//		});
//	return *result;
//}
//
//void CartTable::Delete(int id)
//{
//	auto result = std::remove_if(products->begin(), products->end(), [id](const CartProduct* product)
//		{
//			return product->id == id;
//		});
//	products->erase(result, products->end());
//	Save();
//}
//
void CartTable::DeleteAll()
{
	products->clear();
	Save();
}

void CartTable::Save()
{
	database->UpdateTableContent(*GetContentFromProductsVector(*products), cartTableName);
}
//
//
//
//std::vector<std::vector<std::string>>* CartTable::GetContentFromProductsVector(std::vector<CartProduct*>& products)
//{
//	std::vector<std::vector<std::string>>* vector = new std::vector<std::vector<std::string>>;
//	std::vector<std::string> str;
//	for (auto it : products)
//	{
//		CartProduct& mp = dynamic_cast<CartProduct&>(*it);
//		str = CartProduct::GetvectorStringFromProduct(mp);
//		vector->push_back(str);
//		str.clear();
//	}
//
//	return vector;
//}
//
//Database* CartTable::GetDatabase()
//{
//	return this->database;
//}
//
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