using MyPharmacy.DAL.Modules.Impl;

namespace MyPharmacy.DAL.Repositories.Abstract
{
    public interface ICartRepositoty : IBaseRepository<Flyweight>
    {
        public bool IsProductExist(Flyweight product);
    }
}
