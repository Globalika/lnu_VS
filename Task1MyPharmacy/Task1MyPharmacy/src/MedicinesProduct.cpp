#include "MedicinesProduct.h"
#include <sstream>
std::vector<std::string> MedicinesProduct::GetvectorStringFromProduct(MedicinesProduct& product)
{
	std::vector<std::string> vector;
	vector.push_back(std::to_string(product.id));
	vector.push_back(product.expirationDate);
	vector.push_back(product.name);
	vector.push_back(product.storageTemperature);
	vector.push_back(std::to_string(product.amount));
	return vector;
}

MedicinesProduct MedicinesProduct::GetProductByStringvector(std::vector<std::string>& content)
{
	MedicinesProduct product;
	std::stringstream ss;
	ss << content.at(0);
	ss >> product.id;
	ss.clear();
	product.expirationDate = content.at(1);
	product.name = content.at(2);
	product.storageTemperature = content.at(3);
	ss << content.at(4);
	ss >> product.amount;
	ss.clear();
	return product;
}
