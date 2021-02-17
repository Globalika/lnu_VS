﻿using MyPharmacy.DAL.Modules.Impl;
using System.Collections.Generic;

namespace MyPharmacy.DAL.Repositories
{
    public class FlyweightFactory
    {
	    public Flyweight GetCartFlyweight(CartEntity product, int amount)
        {
			foreach (var it in flyweightsArr)
			{
				if (it.id == product.id)
				{
					return it;
				}
			}

			Flyweight flyw = new Flyweight(product, amount);
			flyweightsArr.Add(flyw);
			return flyw;
		}
	    public List<Flyweight> flyweightsArr;
    }
}