#pragma once
#ifndef _CART_PRODUCT_
#define _CART_PRODUCT_
#include <vector>
#include <sstream>
#include "products/CartProduct.h"

class FlyweightProduct
{
public:
	FlyweightProduct(CartProduct& flyw, int amount);
	FlyweightProduct() {}
	FlyweightProduct& operator=(const FlyweightProduct& other);
	static std::vector<std::string> GetvectorStringFromProduct(FlyweightProduct& product);
	static FlyweightProduct* GetProductByStringVector(std::vector<std::string>& stringvector);
	~FlyweightProduct() {}

	int id;
	std::string name;
	int amount;
};

#endif _CART_PRODUCT_