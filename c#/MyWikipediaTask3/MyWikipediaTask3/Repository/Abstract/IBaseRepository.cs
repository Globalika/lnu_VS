using System.Collections.Generic;

namespace MyWikipediaTask3.Repository.Abstract
{
    public interface IBaseRepository<T>
    {
        public void Create(T product);
        public void Update(T product);
        public T GetById(int id);
        public List<T> GetAll();
        public void Delete(int id);
    }
}
