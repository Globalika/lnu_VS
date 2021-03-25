using MyPharmacy.DAL.Factories.Abstract;
using MyPharmacy.DAL.Repositories.Abstract;
using MyPharmacy.DAL.Repositories.Impl.MemoryImpl;

namespace MyPharmacy.DAL.Factories.Impl.MemoryImpl
{
    class MedicineFactory : IMedicineFactory
    {
        public IMedicineRepository GetMedicineRepository()
        {
            return new MedicineRepository();
        }
    }
}
