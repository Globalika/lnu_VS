using p31task2.DAL.Repositories.Impl;
using System;

namespace p31task2.PL
{
    class Program
    {

        static void Main(string[] args)
        {

            string coString = "Data Source=localhost;Initial Catalog=DATABASE_TASK_2;Integrated Security=True";

            Console.WriteLine("----Roles----\n");
            RolesRepository rolesRepo = new RolesRepository(coString);

            var allRoles = rolesRepo.GetAll();
            foreach (var it in allRoles)
            {
                Console.WriteLine(it.ToString());
            }
            Console.WriteLine("-------------------------------------------------------------\n");
            Console.WriteLine("----Users----\n");
            UsersRepository usersRepo = new UsersRepository(coString);

            var allUsers = usersRepo.GetAll();
            foreach (var it in allUsers)
            {
                Console.WriteLine(it.ToString());
            }

            Console.WriteLine((rolesRepo.Get(0) != null) ? rolesRepo.Get(1).ToString() : "no role with such id");

            Console.ReadLine();
        }
    }
}
