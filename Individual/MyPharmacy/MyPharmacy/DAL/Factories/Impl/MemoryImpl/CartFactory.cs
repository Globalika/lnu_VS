using MyPharmacy.DAL.Factories.Abstract;
using MyPharmacy.DAL.Repositories.Abstract;
using MyPharmacy.DAL.Repositories.Impl.MemoryImpl;

namespace MyPharmacy.DAL.Factories.Impl.MemoryImpl
{
    class CartFactory : ICartFactory
    {
        public ICartRepositoty GetCartRepository()
        {
            return new CartRepository();
        }
    }
}
