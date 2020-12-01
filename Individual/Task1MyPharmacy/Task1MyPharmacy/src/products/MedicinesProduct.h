#pragma once
#ifndef _MEDICINES_PRODUCT_
#define _MEDICINES_PRODUCT_
#include <vector>
#include <sstream>
#include "BaseProduct.h"
class MedicinesProduct : public Product
{
public:
	MedicinesProduct& operator=(const MedicinesProduct& other);
	static std::vector<std::string> GetvectorStringFromProduct(MedicinesProduct& product);
	static MedicinesProduct* GetProductByStringVector(std::vector<std::string>& stringvector);
	~MedicinesProduct() {}
	std::string expirationDate;
	int amount;
	int storageTemperature;
};
#endif _MEDICINES_PRODUCT_