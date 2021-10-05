using p31task2.DAL.Modules.Abstract;

namespace p31task2.DAL.Modules.Impl
{
    public class User : IBaseEntity
    {
        public int Id { get; set; }

        public string Name { get; set; }

        public int RoleId { get; set; }

        public override string ToString()
        {
            return string.Format("Id = {0}\tName = {1}\tRoleId={2}\n",
                Id, Name, RoleId);
        }
    }
}
