using System;
using System.Collections.Generic;
using System.Text;
using MyWikipediaTask3.Entities;

namespace MyWikipediaTask3.Entities
{
    public class Article : IEntity
    {
        public int Id { get; set; }
        public int FkAuthorId { get; set; }
        public string title { get; set; }
        public string genre { get; set; }

        public Article(int Id, int author_Id, string title, string genre)
        {
            this.Id = Id;
            this.FkAuthorId = author_Id;
            this.title = title;
            this.genre = genre;
        }
        public override string ToString()
        {
            return $"{Id},{FkAuthorId},{title},{genre}";
        }
    }
}