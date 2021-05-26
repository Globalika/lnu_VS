using MyWikipediaTask3.DataBase.Abstract;
using MyWikipediaTask3.DataBase.Impl;

namespace MyWikipediaTask3.Factory
{
    public class BinaryFactory : IFactory
    {
        public IDataBase GetDataBase()
        {
            return new BinaryDataBase();
        }
        public string GetTableName(string str)
        {
            return str + ".binarytable";
        }
    }
}
