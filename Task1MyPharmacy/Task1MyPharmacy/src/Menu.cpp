#include <iostream>
#include <sstream>
#include <fstream>
#include <conio.h>
#include <algorithm>
#include "Menu.h"
Menu::Menu()
{
	this->repository = new TablesRepository;
}

void Menu::ShowMainMenu()
{
	PrintMenuTemplate();
	int i;
	do
	{
		i = _getch()-48;

		switch (i)
		{
		case MainMenuCommands::ChooseTable:
		{
			ShowTableMenu();
			PrintMenuTemplate();
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
	products = repository->GetMedicinesTable()->GetAll();
	this->currentId = products.at(0).id;
	PrintTableTemplate();
	int i;
	do
	{
		i = _getch()-48;
		switch (i)
		{
			case TableMenuCommands::SelectCurrentProduct:
			{
				ShowProductMenu();
				currentId = products.at(0).id;
				PrintTableTemplate();
				break;
			}
			case TableMenuCommands::TableUp:
			{
				MoveProbuctByIdUp();//
				PrintTableTemplate();
				break;
			}
			case TableMenuCommands::TableDown:
			{
				MoveProbuctByIdDown();//
				PrintTableTemplate();
				break;
			}
			case TableMenuCommands::SortTableById:
			{

				if (products.at(0).id > products.at(1).id)
				{
					std::sort(products.begin(), products.end(), [](const MedicinesProduct& p1, const MedicinesProduct& p2)
						{
							return p1.id < p2.id;
						});
				}
				else
				{
					std::sort(products.begin(), products.end(), [](const MedicinesProduct& p1, const MedicinesProduct& p2)
						{
							return p1.id > p2.id;
						});
				}
				PrintTableTemplate();
				break;
			}
			case TableMenuCommands::CreateNewProduct:
			{
				std::cout << "Create new product? | 0 : No | 1 : Yes" << std::endl;
				int i = _getch();
				if (i - 48 == 1)
				{
					MedicinesProduct product;
					std::string str; int k;

					std::cout << "Id : "; std::cin >> k;
					product.id = k; std::cout << '\n';

					std::cout << "Expiration Date : "; std::cin >> str;
					product.expirationDate = str; std::cout << '\n';

					std::cout << "Name : "; std::cin >> str;
					product.name = str; std::cout << '\n';

					std::cout << "Storage Temprature : "; std::cin >> str;
					product.storageTemperature = str; std::cout << '\n';

					std::cout << "Amount : "; std::cin >> k;
					product.amount = k; std::cout << '\n';

					repository->GetMedicinesTable()->Create(product);
					repository->GetMedicinesTable()->Save();
					products = repository->GetMedicinesTable()->GetAll();
					currentId = products.at(0).id;
				}
				PrintTableTemplate();
				break;
			}
			case TableMenuCommands::DeletCurrentProduct:
			{
				std::cout << "Delete current product? | 0 : No | 1 : Yes" << std::endl;
				int i = _getch();
				if (i-48 == 1)
				{
					repository->GetMedicinesTable()->Delete(currentId);
					repository->GetMedicinesTable()->Save();
					products = repository->GetMedicinesTable()->GetAll();
					currentId = products.at(0).id;
				}
				PrintTableTemplate();
				break;
			}
			default:
			{
				continue;
			}
		}
	} while (i != TableMenuCommands::TableMenuBack);
}

void Menu::ShowProductMenu()
{
	std::system("cls");
	std::cout << "0 : Back | 1 : ChangeCurrentField";
	SetState(ProductMenuWaiting);
	PrintProduct();
	std::string str;
	int n;
	int i;
	do
	{
		//cout table
		i = _getch()-48;
		switch (i)
		{
		/*case ProductMenuCommands::ChangeCurrentField:
		{
			std::cout << "Input new field : ";
			std::cin >> str;
			repository->GetMedicinesTable()->GetById(repository->GetMedicinesTable()->GetCurrentId())->SetProductExpirationDate(str);
			std::system("cls");
			std::cout << "0 : Back | 1 : ChangeProductName | 2 : ChangeProductExpiredDate | 3 : ChangeProductStorageTempreture | 4 : ChangeProductAmount";
			SetState(ProductMenuWaiting);
			PrintProduct();
			break;
		}*/
		/*case ProductMenuCommands::ChangeProductName:
		{
			std::cout << "Input new name : ";
			std::cin >> str;
			repository->GetMedicinesTable()->GetById(repository->GetMedicinesTable()->GetCurrentId())->SetProductName(str);
			std::system("cls");
			std::cout << "0 : Back | 1 : ChangeProductName | 2 : ChangeProductExpiredDate | 3 : ChangeProductStorageTempreture | 4 : ChangeProductAmount";
			SetState(ProductMenuWaiting);
			PrintProduct();
			break;
		}
		case ProductMenuCommands::ChangeProductStorageTemperature: 
		{
			std::cout << "Input new tempreture : ";
			std::cin >> str;
			repository->GetMedicinesTable()->GetById(repository->GetMedicinesTable()->GetCurrentId())->SetProductStorageTemperature(str);
			std::system("cls");
			std::cout << "0 : Back | 1 : ChangeProductName | 2 : ChangeProductExpiredDate | 3 : ChangeProductStorageTempreture | 4 : ChangeProductAmount";
			SetState(ProductMenuWaiting);
			PrintProduct();
			break;
		}*/
		/*case ProductMenuCommands::ChangeProductAmount:
		{
			std::cout << "Input new amount : ";
			std::cin >> n;
			repository->GetMedicinesTable()->GetById(repository->GetMedicinesTable()->GetCurrentId())->SetProductAmount(n);
			std::system("cls");
			std::cout << "0 : Back | 1 : ChangeProductName | 2 : ChangeProductExpiredDate | 3 : ChangeProductStorageTempreture | 4 : ChangeProductAmount";
			SetState(ProductMenuWaiting);
			PrintProduct();
			break;
		}*/
		default:
		{
			//??
			continue;
		}
		}
	} while (i != ProductMenuCommands::ProductMenuBack);
	///return
	///
}
void Menu::PrintProduct() 
{
	MedicinesProduct product;
	for (auto i : products)
	{
		if (i.id == currentId) { product = i; }
	}
	
	std::cout << "\n\n";
	std::cout << "Id : " << product.id << std::endl;
	std::cout << "Expiration Date : " << product.expirationDate << std::endl;
	std::cout << "Name : " << product.name << std::endl;
	std::cout << "Storage Temperature : " << product.storageTemperature << std::endl;
	std::cout << "Amount : " << product.amount << std::endl;
	std::cout << "\n\n";
}

void Menu::PrintTableTemplate()
{
	std::system("cls");
	std::cout << "0 : Back | 1 : Up | 2 : Down | 3 : Select Current Product" <<'\n';
	std::cout << "4 : Sort Table By Id | 5 : Create NewProduct | 6 : Delete Current Product";
	SetState(TableMenuWaiting);
	PrintTable();
}

void Menu::PrintMenuTemplate()
{
	std::system("cls");
	std::cout << "0 : Quit | 1 : Choose Medicines Table" << std::endl;
	PrintPharmacyWellcome();
	SetState(MainMenuWaiting);
}

void Menu::PrintTable()
{
	std::cout << "\n\n";
	std::cout << "ID | expirationDate | Name | StorageTemprature | Amount";
	std::cout << "\n\n";
	for (auto it : this->products)
	{
		if (it.id == this->currentId)
			std::cout << " ->  ";
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


void Menu::MoveProbuctByIdDown()
{
	if (currentId == products.at(products.size() - 1).id)
		return;
	int i = 0;
	while (products.at(i).id != currentId) { i++; }
	currentId = products.at(i + 1).id;
}

void Menu::MoveProbuctByIdUp()
{
	if (currentId == products.at(0).id)
		return;
	int i = 0;
	while (products.at(i).id != currentId) { i++; }
	currentId = products.at(i - 1).id;
}