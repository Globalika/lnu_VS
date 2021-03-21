using MyPharmacy.DAL.Modules.Abstract;

namespace MyPharmacy.DAL.Modules.Impl
{
    public class Cosmetic : IEntity
    {
        public Cosmetic() { }
        public Cosmetic(int Id, string expirationDate, string name, int storageTemperature, int capacity, int amount)
        {
            this.Id = Id;
            this.name = name;
            this.expirationDate = expirationDate;
            this.amount = amount;
            this.capacity = capacity;
            this.storageTemperature = storageTemperature;
        }
        public int Id { get; set; }
        public string name;
        public string expirationDate;
        public int amount;
        public int capacity;
        public int storageTemperature;

        public override string ToString()
        {
            return $"{Id} | {expirationDate} | {name} | {storageTemperature} | {capacity} | {amount}";
        }
    }
}
