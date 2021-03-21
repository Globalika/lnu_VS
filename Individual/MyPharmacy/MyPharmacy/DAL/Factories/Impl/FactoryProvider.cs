using Microsoft.Extensions.Configuration;
using MyPharmacy.DAL.Factories.Abstract;
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
                default:
                    return new CosmeticFactory();
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
                default:
                    return new MedicineFactory();
            }
        }
    }
}




namespace MyPharmacy
{
    public class Startup
    {


    }
}
