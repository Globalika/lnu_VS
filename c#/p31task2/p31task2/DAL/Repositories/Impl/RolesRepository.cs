using p31task2.DAL.Modules.Impl;
using p31task2.DAL.Repositories.Abstract;
using System.Collections.Generic;
using System.Data.SqlClient;


namespace p31task2.DAL.Repositories.Impl
{
    public class RolesRepository : IRolesRepository
    {
        private string connStr;
        public RolesRepository(string str)
        {
            this.connStr = str;
        }
        public Role Create(Role entity)
        {
            using (SqlConnection conn = new SqlConnection(this.connStr))
            using (SqlCommand command = conn.CreateCommand())
            {
                command.CommandText = $"INSERT INTO ROLES (ROLENAME) VALUES ({entity.Name});";
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
                command.CommandText = $"DELETE FROM ROLES WHERE ID LIKE {id};";
                conn.Open();
                SqlDataReader reader = command.ExecuteReader();
                return true;
            }
        }

        public Role Get(int id)
        {
            using (SqlConnection conn = new SqlConnection(this.connStr))
            using (SqlCommand command = conn.CreateCommand())
            {
                command.CommandText = $"SELECT * FROM ROLES WHERE ID LIKE {id};";
                conn.Open();

                SqlDataReader reader = command.ExecuteReader();
                while (reader.Read())
                {
                    if ((int)reader["ID"] == id)
                    {
                        return new Role
                        {
                            Id = (int)reader["ID"],
                            Name = (string)reader["ROLENAME"]
                        };
                    }
                }
                return null;
            }
        }

        public IEnumerable<Role> GetAll()
        {
            using (SqlConnection conn = new SqlConnection(this.connStr))
            using (SqlCommand command = conn.CreateCommand())
            {
                command.CommandText = "SELECT * FROM ROLES;";
                conn.Open();

                SqlDataReader reader = command.ExecuteReader();
                var list = new List<Role>();
                while (reader.Read())
                {
                    list.Add(new Role
                    {
                        Id = (int)reader["ID"],
                        Name = (string)reader["ROLENAME"]
                    });
                }
                return list;
            }
        }

        public Role Update(Role entity)
        {
            using (SqlConnection conn = new SqlConnection(this.connStr))
            using (SqlCommand command = conn.CreateCommand())
            {
                command.CommandText = $"UPDATE ROLES SET ROLENAME = {entity.Name} WHERE ID LIKE {entity.Id};";
                conn.Open();
                SqlDataReader reader = command.ExecuteReader();
                return entity;
            }
        }
    }
}
