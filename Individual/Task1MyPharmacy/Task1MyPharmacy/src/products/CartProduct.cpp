#include "CartProduct.h"
#include "BaseProduct.h"
#include <sstream>

CartProduct& CartProduct::operator=(const CartProduct& other)
{
	this->id = other.id;
	this->name = other.name;
	this->amount = other.amount;
	return *this;
}

std::vector<std::string> CartProduct::GetvectorStringFromProduct(CartProduct& product)
{

	std::vector<std::string> vector;
	vector.push_back(std::to_string(product.id));
	vector.push_back(product.name);
	vector.push_back(std::to_string(product.amount));
	return vector;
}

CartProduct* CartProduct::GetProductByStringVector(std::vector<std::string>& content)
{
	CartProduct* product = new CartProduct;
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