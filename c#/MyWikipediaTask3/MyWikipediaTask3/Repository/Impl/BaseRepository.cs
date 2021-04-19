using MyWikipediaTask3.Entities;
using MyWikipediaTask3.Repository.Abstract;
using System.Collections.Generic;
using System.Linq;

namespace MyWikipediaTask3.Repository.Impl
{
    public abstract class BaseRepository<T> : IBaseRepository<T> where T : IEntity
    {
        public List<T> entities;
        public void Create(T product)
        {
            entities.Add(product);
            Save();
        }
        protected void Init()
        {
            entities = new List<T>();
        }
        public void Delete(int id)
        {
            var itemToRemove = entities.Single(r => r.Id == id);
            entities.Remove(itemToRemove);
            Save();
        }

        public List<T> GetAll()
        {
            return entities;
        }

        public T GetById(int id)
        {
            return entities.Single(r => r.Id == id);
        }

        public void Update(T product)
        {
            var index = entities.FindIndex(0, r => r.Id == product.Id);
            entities.RemoveAt(index);
            entities.Insert(index, product);
            Save();
        }
        protected abstract T ConvertToObject(string[] strObjItems);
        public abstract void Save();

        //void IBaseRepository<T>.Save()
        //{
        //}
    }
}
