using MyPharmacy.DAL.Modules.Abstract;

namespace MyPharmacy.DAL.Modules.Impl
{
    public class Medicine : IEntity
    {
        public Medicine() { }
        public Medicine(int Id, string expirationDate, string name, int storageTemperature, int amount)
        {
            this.Id = Id;
            this.name = name;
            this.expirationDate = expirationDate;
            this.amount = amount;
            this.storageTemperature = storageTemperature;
        }
        public int Id { get; set; }
        public string name;
        public string expirationDate;
        public int amount;
        public int storageTemperature;

        public override string ToString()
        {
            return $"{Id} | {expirationDate} | {name} | {storageTemperature} | {amount}";
        }
    }
}
