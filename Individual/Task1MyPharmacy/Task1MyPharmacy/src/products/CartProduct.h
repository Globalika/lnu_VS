#pragma once
#ifndef _CART_PRODUCT_
#define _CART_PRODUCT_
#include <vector>
#include <sstream>
#include "BaseProduct.h"
class CartProduct : public Product
{
public:
	CartProduct& operator=(const CartProduct& other);
	static std::vector<std::string> GetvectorStringFromProduct(CartProduct& product);
	static CartProduct* GetProductByStringVector(std::vector<std::string>& stringvector);
	~CartProduct() {}

	int storageTemperature;
};
#endif _CART_PRODUCT_