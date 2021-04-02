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
        public string name { get; set; }
        public string expirationDate { get; set; }
        public int amount { get; set; }
        public int capacity { get; set; }
        public int storageTemperature { get; set; }

        public override string ToString()
        {
            return $"{Id} | {expirationDate} | {name} | {storageTemperature} | {capacity} | {amount}";
        }
    }
}
