using System.Collections.Generic;

namespace p31task2.DAL.Repositories.Abstract
{
    public interface IRepository<TEntity>
    {
        TEntity Get(int id);

        IEnumerable<TEntity> GetAll();

        TEntity Create(TEntity entity);

        TEntity Update(TEntity entity);

        bool Delete(int id);
    }
}
