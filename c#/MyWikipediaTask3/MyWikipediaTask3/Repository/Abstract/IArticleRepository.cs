using MyWikipediaTask3.Entities;

namespace MyWikipediaTask3.Repository.Abstract
{
    public interface IArticleRepository : IBaseRepository<Article>
    {
        public bool AuthorIdCheck(int id);
    }
}
