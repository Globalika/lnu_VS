using MyPharmacy.DAL.Modules.Abstract;

namespace MyPharmacy.DAL.Modules.Impl
{
    public class Cosmetic : IEntity
    {
        public int id { get; set; }
        public string name;
        public string expirationDate;
        public int amount;
        public int capacity;
        public int storageTemperature;


        public override string ToString()
        {
            return $"{id}'|'{name}'|'{expirationDate}'|'{amount}'|'{capacity}'|'{storageTemperature}";
        }
    }
}
