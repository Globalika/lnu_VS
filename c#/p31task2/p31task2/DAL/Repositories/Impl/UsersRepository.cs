using p31task2.DAL.Modules.Impl;
using p31task2.DAL.Repositories.Abstract;
using System;
using System.Collections.Generic;
using System.Data.SqlClient;

namespace p31task2.DAL.Repositories.Impl
{
    public class UsersRepository : IUsersRepository
    {
        private string connStr;
        public UsersRepository(string str)
        {
            this.connStr = str;
        }
        public User Create(User entity)
        {
            using (SqlConnection conn = new SqlConnection(this.connStr))
            using (SqlCommand command = conn.CreateCommand())
            {
                command.CommandText = $"INSERT INTO USERS (USERNAME, ROLE_ID) VALUES ({entity.Name} {entity.RoleId});";
                conn.Open();
                SqlDataReader reader = command.ExecuteReader();
                return entity;
            }
        }

        public bool Delete(int id)
        {
            using (SqlConnection conn = new SqlConnection(this.connStr))
            using (SqlCommand command = conn.CreateCommand())
            {
                command.CommandText = $"DELETE FROM USERS WHERE ID LIKE {id};";
                conn.Open();
                SqlDataReader reader = command.ExecuteReader();
                return true;
            }
        }

        public User Get(int id)
        {
            using (SqlConnection conn = new SqlConnection(this.connStr))
            using (SqlCommand command = conn.CreateCommand())
            {
                command.CommandText = $"SELECT * FROM USER WHERE ID LIKE {id};";
                conn.Open();

                SqlDataReader reader = command.ExecuteReader();
                while (reader.Read())
                {
                    if ((int)reader["ID"] == id)
                    {
                        return new User
                        {
                            Id = (int)reader["ID"],
                            Name = (string)reader["USERNAME"],
                            RoleId = (int)reader["ROLE_ID"]
                        };
                    }
                }
                return null;
            }
        }

        public IEnumerable<User> GetAll()
        {
            using (SqlConnection conn = new SqlConnection(this.connStr))
            using (SqlCommand command = conn.CreateCommand())
            {
                command.CommandText = "SELECT * FROM USERS;";
                conn.Open();

                SqlDataReader reader = command.ExecuteReader();
                var list = new List<User>();
                while (reader.Read())
                {
                    list.Add(new User
                    {
                        Id = (int)reader["ID"],
                        Name = (string)reader["USERNAME"],
                        RoleId = (int)reader["ROLE_ID"]
                    });
                }
                return list;
            }
        }

        public User Update(User entity)
        {
            using (SqlConnection conn = new SqlConnection(this.connStr))
            using (SqlCommand command = conn.CreateCommand())
            {
                command.CommandText = $"UPDATE USERS SET USERNAME = {entity.Name}, ROLE_ID = {entity.RoleId} WHERE ID LIKE {entity.Id};";
                conn.Open();
                SqlDataReader reader = command.ExecuteReader();
                return entity;
            }
        }
    }
}
