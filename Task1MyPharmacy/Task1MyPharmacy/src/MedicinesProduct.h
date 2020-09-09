#pragma once
#include "Product.h"
#include <vector>

class MedicinesProduct /*: public Product*/
{
public:
	static std::vector<std::string> GetvectorStringFromProduct(MedicinesProduct& product);
	static MedicinesProduct GetProductByStringvector(std::vector<std::string>& stringvector);

public:
	int id;
	std::string expirationDate;
	std::string name;
	std::string storageTemperature;
	int amount;
};
