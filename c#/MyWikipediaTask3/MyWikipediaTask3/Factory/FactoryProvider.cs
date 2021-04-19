using Microsoft.Extensions.Configuration;
using System;

namespace MyWikipediaTask3.Factory
{
    public class FactoryProvider
    {
        public FactoryProvider()
        {
            var builder = new ConfigurationBuilder()
                .SetBasePath("C:/Users/volod/source/Lnu_VS/c#/MyWikipediaTask3/MyWikipediaTask3")//Directory.GetCurrentDirectory()
                .AddJsonFile(path: "appsettings.json", optional: false, reloadOnChange: true);
            this.Configuration = builder.Build();
        }

        public IConfiguration Configuration { get; }
        public IFactory GetFactory()
        {
            var configuration = this.Configuration.GetSection("DatabaseConfiguration");
            var factoryType = configuration.GetSection("factoryType").Value;

            switch (factoryType)
            {
                case "text":
                    return new TextFactory();
                case "binary":
                    return new BinaryFactory();
                default:
                    throw new Exception("Wrong type!");
            }
        }
    }
}
