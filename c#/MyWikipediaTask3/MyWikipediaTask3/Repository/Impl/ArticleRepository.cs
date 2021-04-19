using MyWikipediaTask3.Entities;
using MyWikipediaTask3.Factory;
using MyWikipediaTask3.Repository.Abstract;
using System;
using System.Collections.Generic;
using System.Linq;

namespace MyWikipediaTask3.Repository.Impl
{
    public class ArticleRepository : BaseRepository<Article>, IArticleRepository
    {
        IFactory factory;
        FactoryProvider prov;
        public ArticleRepository()
        {
            prov = new FactoryProvider();
            factory = prov.GetFactory();
            this.entities = GetTableFromeDataBase();
        }

        public bool AuthorIdCheck(int id)
        {
            return entities.Any(r => r.FK_author_Id == id);
        }

        public override void Save()
        {
            List<string[]> list = new List<string[]>();
            foreach(var it in entities)
            {
                string[] str = new string[4];
                str[0] = it.Id.ToString();
                str[1] = it.FK_author_Id.ToString();
                str[2] = it.title;
                str[3] = it.genre;
                list.Add(str);
            }
            string[] metaData = { "4", "int", "int", "string", "string" };
            factory.GetDataBase().UpdateTableContent(list, prov.GetFactory().GetTableName("ArticleTable"), metaData);

            //BinaryFactory bin = new BinaryFactory();
            //bin.GetDataBase().UpdateTableContent(list, "ArticleTable.binarytable", metaData);
        }

        protected override Article ConvertToObject(string[] strObjItems)
        {
            int fieldsCount = 4;
            if (strObjItems.Length != fieldsCount)
            {
                throw new Exception("Line is in incorrect format!");
            }
            return new Article(Convert.ToInt32(strObjItems[0]), Convert.ToInt32(strObjItems[1]), strObjItems[2], strObjItems[3]);
        }
        protected List<Article> GetTableFromeDataBase()
        {
            List<Article> list = new List<Article>();
            foreach (var it in factory.GetDataBase().GetTableContent(prov.GetFactory().GetTableName("ArticleTable")))
            {
                list.Add(ConvertToObject(it));
            }
            return list;
        }
    }
}
