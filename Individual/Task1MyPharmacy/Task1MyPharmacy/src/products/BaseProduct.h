#pragma once
#ifndef _PRODUCT_
#define _PRODUCT_
#include <string>
class Product
{
public:
	int id;
	std::string name;
	virtual ~Product() {}
};
#endif _PRODUCT_