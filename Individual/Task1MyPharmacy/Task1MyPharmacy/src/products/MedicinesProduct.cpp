#include "MedicinesProduct.h"
#include "BaseProduct.h"
#include <sstream>

MedicinesProduct& MedicinesProduct::operator=(const MedicinesProduct& other)
{
	this->id = other.id;
	this->expirationDate = other.expirationDate;
	this->name = other.name;
	this->storageTemperature = other.storageTemperature;
	this->amount = other.amount;
	return *this;
}

std::vector<std::string> MedicinesProduct::GetvectorStringFromProduct(MedicinesProduct& product)
{

	std::vector<std::string> vector;
	vector.push_back(std::to_string(product.id));
	vector.push_back(product.expirationDate);
	vector.push_back(product.name);
	vector.push_back(std::to_string(product.storageTemperature));
	vector.push_back(std::to_string(product.amount));
	return vector;
}

MedicinesProduct* MedicinesProduct::GetProductByStringVector(std::vector<std::string>& content)
{
	MedicinesProduct* product = new MedicinesProduct;
	std::stringstream ss;

	ss << content.at(0);
	ss >> product->id;
	ss.clear();

	product->expirationDate = content.at(1);

	product->name = content.at(2);

	ss << content.at(3);
	ss >> product->storageTemperature;
	ss.clear();

	ss << content.at(4);
	ss >> product->amount;
	ss.clear();

	return product;
}