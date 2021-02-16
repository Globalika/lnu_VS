using MyPharmacy.DAL.Repositories.Abstract;
using System.Collections.Generic;
using System.Linq;

namespace MyPharmacy.DAL.Repositories.Impl
{
    public class BaseRepository<T> : IBaseRepository<T>
    {
        public List<T> entities = new List<T>();

        //public virtual bool IsProductExist(T product) { }
        public virtual void Create(T product) 
        {
            // Access database
            entities.Add(product);
        }
        public virtual void Update(T product) 
        {
            //
        }
        //public virtual T GetById(int id) { }
        //public virtual std::vector<T> GetAll() { }
        public virtual void Delete(int id)
        {
            //var itemToRemove = entities.Single(r => r.id == id);
            //entities.Remove(itemToRemove);
        }
        public virtual T GetById(int id)
        {
            //return entities.Single(r => r.id == id);

            throw new System.NotImplementedException();
        }

        public virtual List<T> GetAll()
        {
            throw new System.NotImplementedException();
        }
        //public virtual IBaseRepository GetDatabase() { }
        //virtual ~Table() { };
        //protected std::vector<std::vector<std::string>>* GetContentFromProductsVector(std::vector<T*>& products) { }
        //protected std::vector<T> products;
        //protected Database database;
    }
}
