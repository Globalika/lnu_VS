#pragma once
#ifndef _CART_TABLE_
#define _CART_TABLE_
#include <string>
#include <vector>
#include "BaseTable.h"
#include "..\products\CartProduct.h"

class CartTable : public Table <CartProduct>
{
public:
	CartTable();

	//bool IsProductExist(CartProduct& product) override;
	//void Create(CartProduct& product) override;
	//void Update(CartProduct& product) override;
	//CartProduct* GetById(int id) override;
	//std::vector<CartProduct*>* GetAll() override;
	//void Delete(int id) override;
	void DeleteAll();
	void Save() override;
	//Database* GetDatabase() override;

	~CartTable();


	const static std::string cartTableName;
private:
	//std::vector<std::vector<std::string>>* GetContentFromProductsVector(std::vector<CartProduct*>& products);
	//std::vector<CartProduct*>* products;
	//Database* database;
};
#endif _CART_TABLE_