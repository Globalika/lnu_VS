#include "FlyweightProduct.h"

FlyweightProduct::FlyweightProduct(CartProduct& flyw, int amount)
{
	this->amount = amount;
	this->id = flyw.id;
	this->name = flyw.name;
}

FlyweightProduct& FlyweightProduct::operator=(const FlyweightProduct& other)
{
	this->amount = other.amount;
	this->id = other.id;
	this->name = other.name;
	return *this;
}

std::vector<std::string> FlyweightProduct::GetvectorStringFromProduct(FlyweightProduct& product)
{

	std::vector<std::string> vector;
	vector.push_back(std::to_string(product.id));
	vector.push_back(product.name);
	vector.push_back(std::to_string(product.amount));
	return vector;
}

FlyweightProduct* FlyweightProduct::GetProductByStringVector(std::vector<std::string>& content)
{
	FlyweightProduct* product = new FlyweightProduct();
	std::stringstream ss;

	ss << content.at(0);
	ss >> product->id;
	ss.clear();

	product->name = content.at(1);

	ss << content.at(2);
	ss >> product->amount;
	ss.clear();

	return product;
}

