using MyPharmacy.PL.Impl;

namespace AdminConsole.Admin
{
    class AdminProgram
    {
        static void Main(string[] args)
        {
            MainMenu menu = new MainMenu();
            menu.ShowMainMenu(true);
        }
    }
}
