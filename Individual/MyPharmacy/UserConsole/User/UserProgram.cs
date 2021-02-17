using MyPharmacy.PL.Impl;

namespace UserConsole.Admin
{
    class UserProgram
    {
        static void Main(string[] args)
        {
            MainMenu menu = new MainMenu();
            menu.ShowMainMenu(false);
        }
    }
}
