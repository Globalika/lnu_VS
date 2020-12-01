#pragma once
#ifndef _CART_TABLE_
#define _CART_TABLE_
#include <string>
#include <vector>
#include "BaseTable.h"
#include "products/FlyweightProduct.h"

class CartTable : public Table <FlyweightProduct>
{
public:
	CartTable();
	void DeleteAll();
	void Save() /*override*/;
	~CartTable();
	const static std::string cartTableName;
};
#endif _CART_TABLE_