#include <iostream>
#include "MainMenu.h"

void MainMenu::ShowMainMenu()
{
	PrintMenuForm();
	int i;
	do
	{
		i = GETCH;
		switch (i)
		{
			case MainMenuCommands::ShowMedicinesTable:
			{
				tableMenu.ShowTableMenu(1);
				PrintMenuForm();
				break;
			}
			case MainMenuCommands::ShowCosmeticsTable:
			{
				tableMenu.ShowTableMenu(2);
				PrintMenuForm();
				break;
			}
			case MainMenuCommands::Quit:
			{
				i = 0;
				std::cout << "Quit Pharmacy? | 0 : No | 1 : Yes" << std::endl;
				int j = GETCH;
				if (j == 0)
				{
					i = -1;
					PrintMenuForm();
				}
				break;
			}
			default:
			{
				continue;
			}
		}
	} while (i != MainMenuCommands::Quit);
	
	PrintPharmacyGetWellSoon();
}

void MainMenu::PrintMenuForm()
{
	std::system("cls");
	std::cout << MainMenuCommands::Quit << " : Quit | "
		<< MainMenuCommands::ShowMedicinesTable << " : Choose Medicines Table | " 
		<< MainMenuCommands::ShowCosmeticsTable << " : Choose Cosmetics Table" << std::endl;

	PrintPharmacyWellcome();
	SetState(MainMenuWaiting);
}

void MainMenu::PrintPharmacyWellcome()
{
	std::cout << "\n\n\n";
	std::cout << "________________________________________________________" << std::endl;
	std::cout << "\n\n\n";
	std::cout << "\t\t\tPharmacy +" << std::endl;
	std::cout << "\n\n\n";
	std::cout << "________________________________________________________" << std::endl;
	std::cout << "\n\n\n";
}

void MainMenu::PrintPharmacyGetWellSoon()
{
	std::system("cls");
	std::cout << "\n\n\n";
	std::cout << "________________________________________________________" << std::endl;
	std::cout << "\n\n\n";
	std::cout << "\t\t\tGetWellSoon !" << std::endl;
	std::cout << "\n\n\n";
	std::cout << "________________________________________________________" << std::endl;
	std::cout << "\n\n\n";
}