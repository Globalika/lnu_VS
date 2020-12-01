#include "FlyweightFactory.h"
FlyweightProduct* FlyweightFactory::GetCartFlyweight(CartProduct& product, int amount)
{
	for (auto it : flyweightsArr)
	{
		if (it->id == product.id)
		{
			//it->amount = amount;
			return it;
		}
	}

	FlyweightProduct* flyw = new FlyweightProduct(product, amount);
	flyweightsArr.push_back(flyw);
	return flyw;
}
