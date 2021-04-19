using MyWikipediaTask3.DataBase.Abstract;
using System.Collections.Generic;

namespace MyWikipediaTask3.DataBase.Impl
{
    public abstract class BaseDataBase : IDataBase
    {
        public string CreateTablePath(string tableName)
        {
            return "C:/Users/volod/source/Lnu_VS/c#/MyWikipediaTask3/MyWikipediaTask3/Files/" + tableName;
        }

        public abstract List<string[]> GetTableContent(string tableName);

        public abstract void UpdateTableContent(List<string[]> list, string tableName, string[] metaData);
    }
}
