using MyPharmacy.DAL.Repositories.Abstract;
using MyPharmacy.DAL.Modules.Impl;
using System.Collections.Generic;
using System.Linq;

namespace MyPharmacy.DAL.Repositories.Impl
{
    public class MedicineRepository : BaseRepository<Medicine>, IMedicineRepository
    {

        public override void Delete(int id)
        {
            var itemToRemove = entities.Single(r => r.id == id);
            entities.Remove(itemToRemove);
        }

        public override Medicine GetById(int id)
        {
            return entities.Single(r => r.id == id);

            //throw new System.NotImplementedException();
        }

        public override List<Medicine> GetAll()
        {
            return entities;


            //throw new System.NotImplementedException();
        }
    }
}
