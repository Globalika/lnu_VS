using MyPharmacy.DAL.Factories.Abstract;
using MyPharmacy.DAL.Repositories.Abstract;
using MyPharmacy.DAL.Repositories.Impl.FileImpl;

namespace MyPharmacy.DAL.Factories.Impl.FileImpl
{
    class CosmeticFileFactory : ICosmeticFactory
    {
        public ICosmeticRepository GetCosmeticRepository()
        {
            return new CosmeticFileRepository();
        }
    }
}
