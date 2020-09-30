#pragma once
#ifndef _PRODUCT_
#define _PRODUCT_
#include <string>
class Product
{
public:
	int id;
	std::string name;
	std::string expirationDate;
	int amount;
	virtual ~Product() {}
};
#endif _PRODUCT_