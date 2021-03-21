using MyPharmacy.DAL.Modules.Impl;
using MyPharmacy.DAL.Repositories.Abstract;

namespace MyPharmacy.DAL.Factories.Abstract
{
    public interface ICosmeticFactory
    {
        ICosmeticRepository GetCosmeticRepository();
    }
}
