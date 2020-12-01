#pragma once
#ifndef _COSMETICS_TABLE_
#define _COSMETICS_TABLE_
#include <string>
#include <vector>
#include "BaseTable.h"
#include "..\products/CosmeticsProduct.h"

class CosmeticsTable : public Table <CosmeticsProduct>
{
public:
	CosmeticsTable();
	void Save() override;
	~CosmeticsTable();

	const static std::string cosmeticsTableName;
private:
};
#endif _COSMETICS_TABLE_