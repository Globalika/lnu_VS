using Microsoft.Extensions.Configuration;
using MyPharmacy.DAL.Factories.Abstract;
using MyPharmacy.DAL.Factories.Impl.FileImpl;
using MyPharmacy.DAL.Factories.Impl.MemoryImpl;
using System;
using System.IO;

namespace MyPharmacy.DAL.Factories.Impl
{
    public class FactoryProvider
    {
        public FactoryProvider()
        {
            var builder = new ConfigurationBuilder()
                .SetBasePath(Directory.GetCurrentDirectory())
                .AddJsonFile(path: "appsettings.json", optional: false, reloadOnChange: true);
            this.Configuration = builder.Build();
        }

        public IConfiguration Configuration { get; }
        public ICosmeticFactory GetCosmeticFactory()
        {
            var configuration = this.Configuration.GetSection("DatabaseConfiguration");
            var factoryType = configuration.GetSection("factoryType").Value;

            switch (factoryType)
            {
                case "file":
                    return new CosmeticFileFactory();
                case "memory":
                    return new CosmeticFactory();
                default:
                    throw new Exception("Wrong type!");
            }
        }
        public IMedicineFactory GetMedicineFactory()
        {
            var configuration = this.Configuration.GetSection("DatabaseConfiguration");
            var factoryType = configuration.GetSection("factoryType").Value;

            switch (factoryType)
            {
                case "file":
                    return new MedicineFileFactory();
                case "memory":
                    return new MedicineFactory();
                default:
                    throw new Exception("Wrong type!");
            }
        }

        public ICartFactory GetCartFactory()
        {
            var configuration = this.Configuration.GetSection("DatabaseConfiguration");
            var factoryType = configuration.GetSection("factoryType").Value;

            switch (factoryType)
            {
                case "file":
                    return new CartFileFactory();
                case "memory":
                    return new CartFactory();
                default:
                    throw new Exception("Wrong type!");
            }
        }
    }
}