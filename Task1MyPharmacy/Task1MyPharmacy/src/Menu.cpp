#include <iostream>
#include <sstream>
#include <fstream>
#include <conio.h>

#include "Menu.h"
Menu::Menu()
{
	this->repository = new TablesRepository;
}

void Menu::ShowMainMenu()
{
	std::system("cls");
	std::cout << "0 : Quit | 1 : Choose Table" << std::endl;
	PrintPharmacyWellcome();
	SetState(MainMenuWaiting);
	int i;
	do
	{
		i = _getch()-48;

		switch (i)
		{
		case MainMenuCommands::ChooseTable:
		{
			//whitch table
			//pull up this table
			ShowTableMenu();
			std::system("cls");
			std::cout << "0 : Quit | 1 : Choose Table" << std::endl;
			PrintPharmacyWellcome();
			SetState(MainMenuWaiting);
		}
		default:
		{
			continue;
		}
		}
	} while (i != MainMenuCommands::Quit);
	
	PrintPharmacyGetWellSoon();
}

void Menu::ShowTableMenu()
{
	std::system("cls");
	std::cout << "0 : Back | 1 : Up | 2 : Down | 3 : Select Product";
	SetState(TableMenuWaiting);
	PrintTable();
	int i;
	do
	{
		//cout table
		i = _getch()-48;
		switch (i)
		{
			case TableMenuCommands::SelectProduct:
			{
				//??
				ShowProductMenu();
				std::system("cls");
				std::cout << "0 : Back | 1 : Up | 2 : Down | 3 : Select Product";
				SetState(TableMenuWaiting);
				PrintTable();
			}
			case TableMenuCommands::Up:
			{
				//id??
				this->repository->GetMedicinesTable()->SetCurrentId(3);//
				std::system("cls");
				std::cout << "0 : Back | 1 : Up | 2 : Down | 3 : Select Product";
				SetState(TableMenuWaiting);
				PrintTable();
			}
			case TableMenuCommands::Down:
			{
				//id??
				this->repository->GetMedicinesTable()->SetCurrentId(3);//
				std::system("cls");
				std::cout << "0 : Back | 1 : Up | 2 : Down | 3 : Select Product";
				SetState(TableMenuWaiting);
				PrintTable();
			}
			default:
			{
				//??
				continue;
			}
		}
	} while (i != TableMenuCommands::TableMenuBack);
	
	return;
}

void Menu::ShowProductMenu()
{
	std::system("cls");
	std::cout << "0 : Back";
	std::cout << "1 : ChangeProduct";
	SetState(ProductMenuWaiting);
	int i;
	do
	{
		//cout table
		i = _getch()-48;
		switch (i)
		{
		case ProductMenuCommands::ChangeProductInfo:
		{
			//??
		}

		default:
		{
			//??
			continue;
		}
		}
	} while (i != ProductMenuCommands::ProductMenuWaiting);
	///return
	///
}

void Menu::PrintTable()
{
	std::cout << "\n\n";
	std::cout << "ID | expirationDate | Name | StorageTemprature | Amount";
	std::cout << "\n\n";
	for (auto it : repository->GetMedicinesTable()->GetAll())
	{
		std::cout << std::to_string(it.id) << " | " << it.expirationDate << " | " << it.name << " | "
			<< it.storageTemperature << " | " << std::to_string(it.amount) << std::endl;
	}
	std::cout << "\n\n";
}

void Menu::PrintPharmacyWellcome()
{
	std::cout << "\n\n\n";
	std::cout << "________________________________________________________" << std::endl;
	std::cout << "\n\n\n";
	std::cout << "Pharmacy +" << std::endl;
	std::cout << "\n\n\n";
	std::cout << "________________________________________________________" << std::endl;
	std::cout << "\n\n\n";
}

void Menu::PrintPharmacyGetWellSoon()
{
	std::system("cls");
	std::cout << "\n\n\n";
	std::cout << "________________________________________________________" << std::endl;
	std::cout << "\n\n\n";
	std::cout << "GetWellSoon !" << std::endl;
	std::cout << "\n\n\n";
	std::cout << "________________________________________________________" << std::endl;
	std::cout << "\n\n\n";
}
