using MyPharmacy.DAL.Modules.Abstract;
using MyPharmacy.DAL.Repositories.Abstract;
using System.Collections.Generic;
using System.Linq;

namespace MyPharmacy.DAL.Repositories.Impl
{
    //public class MyEnumerator<T> : IEnumerable<T>
    //{
    //    public IEnumerator<T> GetEnumerator()
    //    {
    //        return new MyInfEnumerator();
    //    }
    //    //public Get
    //}
    //T[] entitties;
    //var entTT = entities.GetEnumerator();

    public abstract class BaseRepository<T> : IBaseRepository<T> where T : IEntity
    {
        public List<T> entities = new List<T>();
        public virtual void Create(T product) 
        {
            // Access database
            entities.Add(product);
        }
        public virtual void Update(T product) 
        {
        }
        public virtual void Delete(int id)
        {
            var itemToRemove = entities.Single(r => r.Id == id);
            entities.Remove(itemToRemove);
        }
        public virtual T GetById(int id)
        {
            throw new System.NotImplementedException();
        }
        public virtual List<T> GetAll()
        {
            return entities;
        }
    }
}
