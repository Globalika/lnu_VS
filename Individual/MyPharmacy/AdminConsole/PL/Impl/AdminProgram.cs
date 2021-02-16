using System;
using System.Collections.Generic;
using System.Text;
//namespace AdminConsole.PL.Impl

namespace AdminConsole.PL.Impl
{
    class AdminProgram
    {
        static void Main(string[] args)
        {
            MainMenu menu = new MainMenu();
            menu.ShowMainMenu();
        }
    }
}
