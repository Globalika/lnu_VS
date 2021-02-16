using System.Collections.Generic;

namespace MyPharmacy.DAL.Repositories.Abstract
{
    public interface IBaseRepository<T>
    {
        //public virtual bool IsProductExist(T product) { }
        public void Create(T product);
        public void Update(T product);
        public T GetById(int id);
        public List<T> GetAll();
        public void Delete(int id);
        //public virtual void Save() { }
        //public virtual IBaseRepository GetDatabase() { }
        //virtual ~Table() { };
        //protected std::vector<std::vector<std::string>>* GetContentFromProductsVector(std::vector<T*>& products) { }
        //protected std::vector<T> products;
        //protected Database database;
    }
}
