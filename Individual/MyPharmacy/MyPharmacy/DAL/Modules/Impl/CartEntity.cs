using MyPharmacy.DAL.Modules.Abstract;

namespace MyPharmacy.DAL.Modules.Impl
{
    public class CartEntity : IEntity
    {
        public int Id { get; set; }
        public string name;
        public override string ToString()
        {
            return $"{Id} | {name}";
        }
    }
}
