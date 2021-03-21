using MyPharmacy.DAL.Modules.Impl;
using System.Collections.Generic;

namespace MyPharmacy.DAL.Repositories
{
    public static class InitialDataLoader
    {
        public static List<Medicine> InitializeMedicineRepository()
        {
            List<Medicine> entities = new List<Medicine>();
            entities.Add(new Medicine()
            {
                Id = 3444,
                name = "wgykue",
                amount = 43,
                expirationDate = "21.10.1999",
                storageTemperature = 42
            });
            entities.Add(new Medicine()
            {
                Id = 3885,
                name = "ftytuur",
                amount = 22,
                expirationDate = "18.07.2200",
                storageTemperature = 453
            });
            entities.Add(new Medicine()
            {
                Id = 3454,
                name = "twferjsr",
                amount = 3,
                expirationDate = "01.03.2030",
                storageTemperature = 12
            });
            return entities;
        }
        public static List<Cosmetic> InitializeCosmeticRepository()
        {
            List<Cosmetic> entities = new List<Cosmetic>();
            entities.Add(new Cosmetic()
            {
                Id = 3444,
                name = "wgykue",
                amount = 43,
                capacity = 243,
                expirationDate = "21.10.1999",
                storageTemperature = 42
            });
            entities.Add(new Cosmetic()
            {
                Id = 3885,
                name = "ftytuur",
                amount = 22,
                capacity = 23,
                expirationDate = "18.07.2200",
                storageTemperature = 453
            });
            entities.Add(new Cosmetic()
            {
                Id = 3454,
                name = "twferjsr",
                amount = 3,
                capacity = 98,
                expirationDate = "01.03.2030",
                storageTemperature = 12
            });
            return entities;
        }
    }
}
