#include <iostream>
#include <sstream>
#include <fstream>
#include <conio.h>

#include "Menu.h"
Menu::Menu()
{
	this->repository = new TablesRepository;
	SetState(Waiting);
}

void Menu::ShowMainMenu()
{
	std::system("cls");
	std::cout << "0 : Quit";
	std::cout << "1 : Choose Table";
	PrintPharmacyWellcome();
	int i;
	do
	{
		i = _getch();

		switch (i)
		{
		case Commands::ChooseTable:
		{
			//whitch table
			//pull up this table
			ShowTableMenu();
		}
		default:
		{
			//??
		}
		}
	} while (i != Commands::Quit);
	
	PrintPharmacyGetWellSoon();
}

void Menu::ShowTableMenu()
{
	std::system("cls");
	std::cout << "0 : Back";
	std::cout << "1 : Up";
	std::cout << "2 : Down";
	std::cout << "3 : Select Product";
	int i;
	do
	{
		//cout table
		i = _getch();
		switch (i)
		{
		case Commands::SelectProduct:
		{
			//??
			ShowProductMenu();
		}
		case Commands::Up:
		{
			//id??
		}
		case Commands::Down:
		{
			//id??
		}
			default:
			{
				//??
			}
		}
	} while (i != Commands::Back);
	
	return;
}

void Menu::ShowProductMenu()
{
	std::system("cls");
	std::cout << "0 : Back";
	std::cout << "1 : ChangeProduct";
	int i;
	do
	{
		//cout table
		i = _getch();
		switch (i)
		{
		case Commands::SelectProduct:
		{
			//??
			ShowProductMenu();
		}

		default:
		{
			//??
		}
		}
	} while (i != Commands::Back);
	///return
	///
}

void Menu::PrintTable()
{
	//repository->GetMedicinesTable();
	std::cout << "ID | expirationDate | Name | Tempreture | Amount" << std::endl;
	for (auto it : repository->GetMedicinesTable()->GetAll())
	{
		
	}


}

void Menu::PrintPharmacyWellcome()
{
	std::cout << '\n\n\n';
	std::cout << "________________________________________________________" << std::endl;
	std::cout << '\n\n\n';
	std::cout << "Pharmacy +" << std::endl;
	std::cout << '\n\n\n';
	std::cout << "________________________________________________________" << std::endl;
	std::cout << '\n\n\n';
}

void Menu::PrintPharmacyGetWellSoon()
{
	std::system("cls");
	std::cout << '\n\n\n';
	std::cout << "________________________________________________________" << std::endl;
	std::cout << '\n\n\n';
	std::cout << "GetWellSoon !" << std::endl;
	std::cout << '\n\n\n';
	std::cout << "________________________________________________________" << std::endl;
	std::cout << '\n\n\n';
}
