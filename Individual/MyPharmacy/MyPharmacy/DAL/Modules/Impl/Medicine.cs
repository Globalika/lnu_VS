using MyPharmacy.DAL.Modules.Abstract;

namespace MyPharmacy.DAL.Modules.Impl
{
    public class Medicine : IEntity
    {
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
