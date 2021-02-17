using MyPharmacy.DAL.Repositories.Abstract;
using System.Collections.Generic;
using System.Linq;

namespace MyPharmacy.DAL.Repositories.Impl
{
    public class BaseRepository<T> : IBaseRepository<T>
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
        }
        public virtual T GetById(int id)
        {
            throw new System.NotImplementedException();
        }

        public virtual List<T> GetAll()
        {
            throw new System.NotImplementedException();
        }
    }
}
