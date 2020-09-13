#pragma once
#ifndef _MEDICINES_PRODUCT_
#define _MEDICINES_PRODUCT_
#include <vector>
#include <sstream>

class MedicinesProduct /*: public Product*/
{
public:
	MedicinesProduct& operator=(const MedicinesProduct& other);
	static std::vector<std::string> GetvectorStringFromProduct(MedicinesProduct& product);
	static MedicinesProduct GetProductByStringvector(std::vector<std::string>& stringvector);
public:
	int id;
	std::string expirationDate;
	std::string name;
	std::string storageTemperature;
	int amount;
};
#endif _MEDICINES_PRODUCT_