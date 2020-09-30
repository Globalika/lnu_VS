#include "CosmeticsProduct.h"
#include <sstream>

CosmeticsProduct& CosmeticsProduct::operator=(const CosmeticsProduct& other)
{
	this->id = other.id;
	this->expirationDate = other.expirationDate;
	this->name = other.name;
	this->storageFormType = other.storageFormType;
	this->capacity = other.capacity;
	this->amount = other.amount;
	return *this;
}


std::vector<std::string> CosmeticsProduct::GetvectorStringFromProduct(CosmeticsProduct& product)
{
	std::vector<std::string> vector;
	vector.push_back(std::to_string(product.id));
	vector.push_back(product.expirationDate);
	vector.push_back(product.name);
	vector.push_back(product.storageFormType);
	vector.push_back(std::to_string(product.capacity));
	vector.push_back(std::to_string(product.amount));
	return vector;
}

CosmeticsProduct* CosmeticsProduct::GetProductByStringVector(std::vector<std::string>& content)
{
	CosmeticsProduct* product = new CosmeticsProduct;
	std::stringstream ss;
	ss << content.at(0);
	ss >> product->id;
	ss.clear();
	product->expirationDate = content.at(1);
	product->name = content.at(2);
	product->storageFormType = content.at(3);
	ss << content.at(4);
	ss >> product->capacity;
	ss.clear();
	ss << content.at(5);
	ss >> product->amount;
	ss.clear();
	return product;
}