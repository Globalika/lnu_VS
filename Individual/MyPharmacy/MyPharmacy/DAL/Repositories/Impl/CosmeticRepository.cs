using MyPharmacy.DAL.Repositories.Abstract;
using MyPharmacy.DAL.Modules.Impl;
using System.Collections.Generic;
using System.Linq;

namespace MyPharmacy.DAL.Repositories.Impl
{
    public class CosmeticRepository : BaseRepository<Cosmetic>, ICosmeticRepository
    {
        public override void Delete(int id)
        {
            var itemToRemove = entities.Single(r => r.id == id);
            entities.Remove(itemToRemove);
        }

        public override Cosmetic GetById(int id)
        {
            return entities.Single(r => r.id == id);
        }

        public override List<Cosmetic> GetAll()
        {
            return entities;
        }
    }
}
