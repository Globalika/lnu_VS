namespace MyPharmacy.DAL.Modules.Impl
{
    public class Flyweight
    {
		public int id { get; set; }
		public string name;
		public int amount;
		public Flyweight(CartEntity flyw, int amount) 
		{
			this.amount = amount;
			this.id = flyw.id;
			this.name = flyw.name;
		}
		Flyweight() { }
		public Flyweight(Flyweight other)
        {
			this.id = other.id;
			this.amount = other.amount;
			this.name = other.name;
        }
		public override string ToString()
		{
			return $"{id} | {name} | {amount}";
		}
	}
}
