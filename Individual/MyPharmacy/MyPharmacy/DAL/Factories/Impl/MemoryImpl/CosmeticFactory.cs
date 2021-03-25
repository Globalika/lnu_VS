using MyPharmacy.DAL.Factories.Abstract;
using MyPharmacy.DAL.Repositories.Abstract;
using MyPharmacy.DAL.Repositories.Impl.MemoryImpl;

namespace MyPharmacy.DAL.Factories.Impl.MemoryImpl
{
    class CosmeticFactory : ICosmeticFactory
    {
        public ICosmeticRepository GetCosmeticRepository()
        {
            return new CosmeticRepository();
        }
    }
}
