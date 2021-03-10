using MyPharmacy.DAL.Modules.Abstract;

namespace MyPharmacy.DAL.Modules.Impl
{
    public class Flyweight : IEntity
    {
		public int Id { get; set; }
		public string name;
		public int amount;
		public Flyweight(CartEntity flyw, int amount) 
		{
			this.amount = amount;
			this.Id = flyw.Id;
			this.name = flyw.name;
		}
		Flyweight() { }
		public Flyweight(Flyweight other)
        {
			this.Id = other.Id;
			this.amount = other.amount;
			this.name = other.name;
        }
		public override string ToString()
		{
			return $"{Id} | {name} | {amount}";
		}
	}
}
