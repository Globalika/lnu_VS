using System.Collections.Generic;

namespace MyWikipediaTask3.DataBase.Abstract
{
    public interface IDataBase
    {
        public string CreateTablePath(string tableName);
        public void UpdateTableContent(List<string[]> list, string tableName, string[] metaData);
        public List<string[]> GetTableContent(string tableName);
    }
}
