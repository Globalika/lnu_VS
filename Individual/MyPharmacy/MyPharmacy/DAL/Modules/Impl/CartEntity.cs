using MyPharmacy.DAL.Modules.Abstract;

namespace MyPharmacy.DAL.Modules.Impl
{
    public class CartEntity : IEntity
    {
        public int id { get; set; }
        public string name;
        public override string ToString()
        {
            return $"{id} | {name}";
        }
    }
}
