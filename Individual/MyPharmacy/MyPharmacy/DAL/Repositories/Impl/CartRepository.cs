﻿using MyPharmacy.DAL.Repositories.Abstract;
using MyPharmacy.DAL.Modules.Impl;
namespace MyPharmacy.DAL.Repositories.Impl
{
    public class CartRepository : BaseRepository<Flyweight>,ICartRepositoty
    {
        public CartRepository()
        {

        }
		public bool IsProductExist(Flyweight product)
		{
			var it = entities.Find(x => x.id == product.id);
			if (it == null)
			{
				return false;
			}
			else
			{
				return true;
			}
		}
	}
}