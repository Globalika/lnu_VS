#pragma once
#include "products/FlyweightProduct.h"
#include "products/CartProduct.h"
class FlyweightFactory
{
public:
	FlyweightProduct* GetCartFlyweight(CartProduct& c, int amount);

protected:
	std::vector<FlyweightProduct* > flyweightsArr;
};