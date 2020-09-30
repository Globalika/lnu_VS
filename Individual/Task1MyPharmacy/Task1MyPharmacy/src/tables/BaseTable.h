#pragma once
#ifndef _TABLE_
#define _TABLE_
#include <string>
#include <vector>
#include "..\Database.h"
#include "..\products/BaseProduct.h"
class Table
{
public:
	virtual bool IsProductExist(Product& product) = 0;
	virtual void Create(Product& product) = 0;
	virtual void Update(Product& product) = 0;
	virtual Product* GetById(int id) = 0;
	virtual std::vector<Product*>* GetAll() = 0;
	virtual void Delete(int id) = 0;
	virtual void Save() = 0;
	virtual Database* GetDatabase() = 0;
	virtual ~Table(){};
};
#endif _TABLE_