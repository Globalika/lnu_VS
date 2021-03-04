using System;

namespace MyPharmacy.PL.UserMenu.Impl
{
	public class MainMenu
    {
		public MainMenu()
		{
			m = new MedicineMenu();
			c = new CosmeticMenu();
		}
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

		//public MainMenu()
		//{
		//}
		public void ShowMainMenu() 
		{
			PrintMenuForm();
			MainMenuCommands command;
			do
			{
				command = (MainMenuCommands)((int)(Console.ReadKey(true).KeyChar)-48);
				switch (command)
				{
					case MainMenuCommands.ShowMedicinesTable:
					{
						m.ShowTableMenu();
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
						if (Console.ReadKey(true).KeyChar == '1')
						{
							command = MainMenuCommands.Quit;
							break;
						}
                        else
                        {
							command = MainMenuCommands.MainMenuWaiting;
						}
						PrintMenuForm();
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
			Console.Write("\t\t\tPharmacy +");
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