using MyPharmacy.DAL.Repositories.Abstract;
using MyPharmacy.DAL.Modules.Impl;
using System.Collections.Generic;
using System.Linq;

namespace MyPharmacy.DAL.Repositories.Impl
{
    public class CosmeticRepository : BaseRepository<Cosmetic>, ICosmeticRepository
    {
        public CosmeticRepository()//-----
        {
            entities.Add( new Cosmetic()
            {
                Id = 3444,
                name = "wgykue",
                amount = 43,
                capacity = 243,
                expirationDate = "21.10.1999",
                storageTemperature = 42
            });
            entities.Add( new Cosmetic()
            {
                Id = 3885,
                name = "ftytuur",
                amount = 22,
                capacity = 23,
                expirationDate = "18.07.2200",
                storageTemperature = 453
            });
            entities.Add( new Cosmetic()
            {
                Id = 3454,
                name = "twferjsr",
                amount = 3,
                capacity = 98,
                expirationDate = "01.03.2030",
                storageTemperature = 12
            });
        }//
        public override void Delete(int id)
        {
            var itemToRemove = entities.Single(r => r.Id == id);
            entities.Remove(itemToRemove);
        }
        public override Cosmetic GetById(int id)
        {
            return entities.Single(r => r.Id == id);
        }
        public override List<Cosmetic> GetAll()
        {
            return entities;
        }
    }
}
