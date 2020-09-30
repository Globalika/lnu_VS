#pragma once
#ifndef _COSMETICS_TABLE_
#define _COSMETICS_TABLE_
#include <string>
#include <vector>
#include "BaseTable.h"
#include "..\products/CosmeticsProduct.h"

class CosmeticsTable : public Table
{
public:
	CosmeticsTable();

	bool IsProductExist(Product& product) override;
	void Create(Product& product) override;
	void Update(Product& product) override;
	Product* GetById(int id) override;
	std::vector<Product*>* GetAll() override;
	void Delete(int id) override;
	void Save() override;
	Database* GetDatabase() override;

	~CosmeticsTable();

	const static std::string cosmeticsTableName;
private:
	std::vector<std::vector<std::string>>* GetContentFromProductsVector(std::vector<CosmeticsProduct*>& products);
	std::vector<CosmeticsProduct*>* products;
	Database* database;
};
#endif _COSMETICS_TABLE_