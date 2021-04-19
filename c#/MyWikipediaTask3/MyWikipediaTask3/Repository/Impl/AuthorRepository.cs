using MyWikipediaTask3.Entities;
using MyWikipediaTask3.Factory;
using MyWikipediaTask3.Repository.Abstract;
using System;
using System.Collections.Generic;

namespace MyWikipediaTask3.Repository.Impl
{
    public class AuthorRepository : BaseRepository<Author>, IAuthorRepository
    {
        IFactory factory;
        FactoryProvider prov;
        public AuthorRepository()
        {
            prov = new FactoryProvider();
            factory = prov.GetFactory();
            this.entities = GetTableFromeDataBase();
        }
        public override void Save()
        {
            List<string[]> list = new List<string[]>();
            foreach (var it in entities)
            {
                string[] str = new string[2];
                str[0] = it.Id.ToString();
                str[1] = it.name;
                list.Add(str);
            }
            string[] metaData = { "2", "int", "string" };
            factory.GetDataBase().UpdateTableContent(list, prov.GetFactory().GetTableName("AuthorTable"), metaData);

            //BinaryFactory bin = new BinaryFactory();
            //bin.GetDataBase().UpdateTableContent(list, "AuthorTable.binarytable", metaData);
        }

        protected override Author ConvertToObject(string[] strObjItems)
        {
            int fieldsCount = 2;
            if (strObjItems.Length != fieldsCount)
            {
                throw new Exception("Line is in incorrect format!");
            }
            return new Author(Convert.ToInt32(strObjItems[0]), strObjItems[1]);
        }

        protected List<Author> GetTableFromeDataBase()
        {
            List<Author> list = new List<Author>();
            foreach (var it in factory.GetDataBase().GetTableContent(prov.GetFactory().GetTableName("AuthorTable")))
            {
                list.Add(ConvertToObject(it));
            }
            return list;
        }

    }
}
