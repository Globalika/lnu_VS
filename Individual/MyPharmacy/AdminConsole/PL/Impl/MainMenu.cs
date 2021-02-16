using System;

namespace AdminConsole.PL.Impl
{
    public class MainMenu
    {
		public enum MainMenuCommands
		{
			Quit,
			ShowMedicinesTable,
			ShowCosmeticsTable,
			MainMenuWaiting,
		};
		private MainMenuCommands mState;
		private MedicineMenu m;
		private CosmeticMenu c;

		public MainMenu()
		{
			m = new MedicineMenu();
			c = new CosmeticMenu();
		}
		public void ShowMainMenu() 
		{
			PrintMenuForm();
			//char i = Console.ReadKey().KeyChar;
			MainMenuCommands command;
			do
			{
				//char ch = Console.ReadKey(true).KeyChar;
				//command = (MainMenuCommands)Convert.ToInt32(ch-48);
				//command = (MainMenuCommands)(int.Parse(Console.ReadKey(true).KeyChar));
				//int i;
				command = (MainMenuCommands)((int)(Console.ReadKey(true).KeyChar)-48);
				switch (command)
				{
					case MainMenuCommands.ShowMedicinesTable :
					{
						//m.ShowTableMenu();
						PrintMenuForm();
						break;
					}
					case MainMenuCommands.ShowCosmeticsTable:
					{
						c.ShowTableMenu();
						PrintMenuForm();
						break;
					}
					case MainMenuCommands.Quit:
					{
						Console.WriteLine("Quit Pharmacy? | 0 : No | 1 : Yes");
						//int j = GETCH;
						if (Console.ReadKey(true).KeyChar == '1')
						{
							command = MainMenuCommands.Quit;
							//Console.Clear();
							PrintMenuForm();
						}
						break;
					}
					default:
					{
						continue;
					}
				}
			} while (command != MainMenuCommands.Quit);
			Console.Clear();
			PrintPharmacyGetWellSoon();
		}
		public void PrintPharmacyWellcome() 
		{
			Console.WriteLine("\n\n\n");
			Console.WriteLine("________________________________________________________");
			Console.WriteLine("\n\n\n");
			Console.WriteLine("\t\t\tPharmacy +");
			Console.WriteLine("\n\n\n");
			Console.WriteLine("________________________________________________________");
			Console.WriteLine("\n\n\n");
		}
		public void PrintPharmacyGetWellSoon() 
		{
			Console.WriteLine("\n\n\n");
			Console.WriteLine("________________________________________________________");
			Console.WriteLine("\n\n\n");
			Console.WriteLine("\t\t\tGetWellSoon +");
			Console.WriteLine("\n\n\n");
			Console.WriteLine("________________________________________________________");
			Console.WriteLine("\n\n\n");
		}
		public void PrintMenuForm() 
		{
			Console.Clear();
			Console.Write($"{(int)MainMenuCommands.Quit } : Quit | ");
			Console.Write($"{(int)MainMenuCommands.ShowMedicinesTable} : Choose Medicines Table | ");
			Console.WriteLine($"{(int)MainMenuCommands.ShowCosmeticsTable} : Choose Cosmetics Table");
			PrintPharmacyWellcome();
			SetState(MainMenuCommands.MainMenuWaiting);
		}
		public void SetState(MainMenuCommands state)
		{
			this.mState = state;
		}
	}
}