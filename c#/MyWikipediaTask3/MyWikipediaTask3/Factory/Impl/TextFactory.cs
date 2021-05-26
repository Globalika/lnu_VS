using MyWikipediaTask3.DataBase.Abstract;
using MyWikipediaTask3.DataBase.Impl;

namespace MyWikipediaTask3.Factory
{
    public class TextFactory : IFactory
    {
        public IDataBase GetDataBase()
        {
            return new TextDataBase();
        }
        public string GetTableName(string str)
        {
            return str+".table";
        }
    }
}
