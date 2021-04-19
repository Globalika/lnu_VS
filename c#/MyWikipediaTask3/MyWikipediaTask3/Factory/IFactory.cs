using MyWikipediaTask3.DataBase.Abstract;

namespace MyWikipediaTask3.Factory
{
    public interface IFactory
    {
        public IDataBase GetDataBase();
        public string GetTableName(string str);
    }
}
