#pragma once
#ifndef _COSMETICS_PRODUCT_
#define _COSMETICS_PRODUCT_
#include <vector>
#include <sstream>
#include "BaseProduct.h"

class CosmeticsProduct : public Product
{
public:
	CosmeticsProduct& operator=(const CosmeticsProduct& other);
	static std::vector<std::string> GetvectorStringFromProduct(CosmeticsProduct& product);
	static CosmeticsProduct* GetProductByStringVector(std::vector<std::string>& stringvector);
	~CosmeticsProduct() {}

	std::string storageFormType;
	int capacity;
};
#endif _COSMETICS_PRODUCT_