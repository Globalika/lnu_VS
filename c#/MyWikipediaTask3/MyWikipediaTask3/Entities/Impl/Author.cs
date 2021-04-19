using System;
using System.Collections.Generic;
using System.Text;

namespace MyWikipediaTask3.Entities
{
    public class Author : IEntity
    {
        public int Id { get; set; }
        public string name { get; set; }
        //public int articleAmount {}
        public Author (int Id, string name)
        {
            this.Id = Id;
            this.name = name;
        }
        public override string ToString()
        {
            return $"{Id},{name}";
        }
    }
}
