using MyPharmacy.DAL.Factories.Abstract;
using MyPharmacy.DAL.Repositories.Abstract;
using MyPharmacy.DAL.Repositories.Impl.FileImpl;

namespace MyPharmacy.DAL.Factories.Impl.FileImpl
{
    class MedicineFileFactory : IMedicineFactory
    {
        public IMedicineRepository GetMedicineRepository()
        {
            return new MedicineFileRepository();
        }
    }
}
