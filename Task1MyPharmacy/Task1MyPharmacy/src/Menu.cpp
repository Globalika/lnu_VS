#include <iostream>
#include <sstream>
#include <fstream>
#include <conio.h>
#include <algorithm>
#include <exception>

#include "Menu.h"
Menu::Menu()
{
	this->repository = new TablesRepository;
}

void Menu::ShowMainMenu()
{
	PrintMenuForm();
	int i;
	do
	{
		i = _getch()-48;

		switch (i)
		{
		case MainMenuCommands::ChooseTable:
		{
			ShowTableMenu();
			PrintMenuForm();
			break;
		}
		case MainMenuCommands::Quit:
		{
			std::cout << "Quit Pharmacy? | 0 : No | 1 : Yes" << std::endl;
			int j = _getch();
			if (j - 48 == 0)
			{
				i = -1;
			}
			PrintMenuForm();
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

void Menu::ShowTableMenu()
{
	products = repository->GetMedicinesTable()->GetAll();
	this->currentId = products.at(0).id;
	PrintTableForm();
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
				PrintTableForm();
				break;
			}
			case TableMenuCommands::TableUp:
			{
				MoveProbuctById(-1);
				PrintTableForm();
				break;
			}
			case TableMenuCommands::TableDown:
			{
				MoveProbuctById(1);
				PrintTableForm();
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
				PrintTableForm();
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

					std::cout << "Id (Example : 9999) : "; std::cin >> k;
					product.id = k; std::cout << '\n';

					std::cout << "Expiration Date (Example : 12.12.2012) : "; std::cin >> str;
					product.expirationDate = str; std::cout << '\n';

					std::cout << "Name (Example : Kfehjvre) : "; std::cin >> str;
					product.name = str; std::cout << '\n';

					std::cout << "Storage Temprature (Example : 23) : "; std::cin >> str;
					product.storageTemperature = str; std::cout << '\n';

					std::cout << "Amount (Example : 44) : "; std::cin >> k;
					product.amount = k; std::cout << '\n';

					repository->GetMedicinesTable()->Create(product);
					products = repository->GetMedicinesTable()->GetAll();
					currentId = products.at(0).id;
				}
				PrintTableForm();
				break;
			}
			case TableMenuCommands::DeleteCurrentProduct:
			{
				std::cout << "Delete current product? | 0 : No | 1 : Yes" << std::endl;
				int i = _getch();
				if (i-48 == 1)
				{
					repository->GetMedicinesTable()->Delete(currentId);
					products = repository->GetMedicinesTable()->GetAll();
					currentId = products.at(0).id;
				}
				PrintTableForm();
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
	PrintProductForm();
	std::string str;
	int i;
	do
	{
		i = _getch()-48;
		switch (i)
		{
			case ProductMenuCommands::ProductFieldUp:
			{
				if (currentProductFieldId != 1) { currentProductFieldId--; }
				PrintProductForm();
				break;
			}
			case ProductMenuCommands::ProductFieldDown:
			{
				if (currentProductFieldId != 4) { currentProductFieldId++; }
				PrintProductForm();
				break;
			}
			case ProductMenuCommands::ChangeCurrentField:
			{
				repository->GetMedicinesTable()->Update(*ChangeCurrentFieldById(currentProductFieldId));
				products = repository->GetMedicinesTable()->GetAll();
				currentProductFieldId = 1;
				PrintProductForm();
				break;
			}
			default:
			{
				continue;
			}
		}
	} while (i != ProductMenuCommands::ProductMenuBack);
}
void Menu::PrintProduct() 
{
	MedicinesProduct product;
	for (auto i : products)
	{
		if (i.id == currentId) { product = i; }
	}
	
	std::cout << "\n\n";
	std::cout << "Id : " << product.id << std::endl << std::endl;

	if (currentProductFieldId == 1) { std::cout << " ->  "; }
	std::cout << "Expiration Date : " << product.expirationDate << std::endl;

	if (currentProductFieldId == 2) { std::cout << " ->  "; }
	std::cout << "Name : " << product.name << std::endl; 

	if (currentProductFieldId == 3) { std::cout << " ->  "; }
	std::cout << "Storage Temperature : " << product.storageTemperature << std::endl; 

	if (currentProductFieldId == 4) { std::cout << " ->  "; }
	std::cout << "Amount : " << product.amount << std::endl;
	std::cout << "\n\n";
}

void Menu::PrintTableForm()
{
	std::system("cls");
	std::cout << TableMenuCommands::TableMenuBack << " : Back | "
		<< TableMenuCommands::TableUp << " : Up | "
		<< TableMenuCommands::TableDown << " : Down | "
		<< TableMenuCommands::SelectCurrentProduct << " : Select Current Product\n"
		<< TableMenuCommands::SortTableById << " : Sort Table By Id | "
		<< TableMenuCommands::CreateNewProduct << " : Create NewProduct | "
		<< TableMenuCommands::DeleteCurrentProduct << " : Delete Current Product";
	SetState(TableMenuWaiting);
	PrintTable();
}

void Menu::PrintMenuForm()
{
	std::system("cls");
	std::cout << MainMenuCommands::Quit << " : Quit | "
		<< MainMenuCommands::ChooseTable << " : Choose Medicines Table" << std::endl;
	PrintPharmacyWellcome();
	SetState(MainMenuWaiting);
}

void Menu::PrintProductForm()
{
	std::system("cls");
	std::cout << ProductMenuCommands::ProductMenuBack << " : Back | "
		<< ProductMenuCommands::ProductFieldUp << " : Move Current Field Up | "
		<< ProductMenuCommands::ProductFieldDown << " : Move Current Field Down | "
		<< ProductMenuCommands::ChangeCurrentField << " : ChangeCurrentField";
	SetState(ProductMenuWaiting);
	PrintProduct();
}

void Menu::PrintTable()
{
	std::cout << "\n\n";
	std::cout << "ID | expirationDate | Name | StorageTemprature | Amount";
	std::cout << "\n\n";
	for (auto it : this->products)
	{
		if (it.id == this->currentId)
		{
			std::cout << " ->  ";
		}
		std::cout << std::to_string(it.id) << " | "
			<< it.expirationDate << " | " 
			<< it.name << " | "
			<< it.storageTemperature << " | " 
			<< std::to_string(it.amount) 
			<< std::endl;
	}
	std::cout << "\n\n";
}

void Menu::PrintPharmacyWellcome()
{
	std::cout << "\n\n\n";
	std::cout << "________________________________________________________" << std::endl;
	std::cout << "\n\n\n";
	std::cout << "\t\t\tPharmacy +" << std::endl;
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
	std::cout << "\t\t\tGetWellSoon !" << std::endl;
	std::cout << "\n\n\n";
	std::cout << "________________________________________________________" << std::endl;
	std::cout << "\n\n\n";
	
}


void Menu::MoveProbuctById(int n)
{
	if (n == 1)
	{
		if (currentId == products.at(products.size() - 1).id)
		{
			return;
		}
	}
	else
	{
		if (currentId == products.at(0).id)
		{
			return;
		}
	}
	int i = 0;
	while (products.at(i).id != currentId) 
	{ 
		i++;
	}
	currentId = products.at(i + n).id;
}

bool Menu::CatchProductName(std::string str)
{
	for (auto i : str)
	{
		if (!((i >= 65 && i <= 90) || (i >= 97 && i <= 122)))
		{
			return true;
		}
	}
	return false;
}

bool Menu::CatchProductDate(std::string str)
{
	if (!(str.at(2) == 46 && str.at(5) == 46 && str.size() == 10))
	{
		return true;//
	}
	for (int i = 0; i < str.size(); i++)
	{
		if (i == 2 || i == 5)
		{
			continue;
		}
		else if(!(str[i] >= 48 && str[i] <= 58))
		{
			return true;
		}
	}
	return false;
}

bool Menu::CatchProductAmountOrTempreture(std::string str)
{
	for (auto i : str)
	{
		if (!(i >= 48 && i <= 58))
		{
			return true;
		}
	}
	return false;
}

MedicinesProduct* Menu::ChangeCurrentFieldById(int Id)
{
	std::string str;
	MedicinesProduct* product = (repository->GetMedicinesTable()->GetById(currentId));
	bool isTrue = true;
	switch (Id)
	{
		case 1:
		{
			std::cout << "Input new Expiration Date? | 0 : No | 1 : Yes" << std::endl;
			int i = _getch();
			if (i - 48 == 1)
			{
				while (isTrue)
				{
					try
					{
						std::cout << "New Date : ";
						std::cin >> str;
						if (CatchProductDate(str))
						{
							throw std::exception();
						}
						isTrue = false;
					}
					catch (const std::exception& err)
					{
						PrintProductForm();
						std::cout << "Wrong form! Please, type date like this example: dd.mm.yyyy" << std::endl;
					}
				}
				product->expirationDate = str;
			}
			break;
		}
		case 2:
		{
			std::cout << "Input new Name? | 0 : No | 1 : Yes" << std::endl;
			int i = _getch();
			if (i - 48 == 1)
			{
				while (isTrue)
				{
					try
					{
						std::cout << "New Name : ";
						std::cin >> str;
						if (CatchProductName(str))
						{
							throw std::exception();
						}
						isTrue = false;
					}
					catch (const std::exception& err)
					{
						PrintProductForm();
						std::cout << "Wrong name! Please, try again." << std::endl;
					}
				}
				product->name = str;
			}
			break;
		}
		case 3:
		{
			std::cout << "Input new Storage Tepmreture? | 0 : No | 1 : Yes" << std::endl;
			int i = _getch();
			if (i - 48 == 1)
			{
				while (isTrue)
				{
					try
					{
						std::cout << "New Tepmreture : ";
						std::cin >> str;
						if (CatchProductAmountOrTempreture(str))
						{
							throw std::exception();
						}
						isTrue = false;
					}
					catch (const std::exception& err)
					{
						PrintProductForm();
						std::cout << "Wrong format! Please, use only numbers." << std::endl;
					}
				}
				product->storageTemperature = str;
			}
			break;
		}
		case 4:
		{
			std::cout << "Input new Amount? | 0 : No | 1 : Yes" << std::endl;
			int i = _getch();
			if (i - 48 == 1)
			{
				while (isTrue)
				{
					try
					{
						std::cout << "New Amount : ";
						std::cin >> str;
						if (CatchProductAmountOrTempreture(str))
						{
							throw std::exception();
						}
						isTrue = false;
					}
					catch (const std::exception& err)
					{
						PrintProductForm();
						std::cout << "Wrong format! Please, use only numbers." << std::endl;
					}
				}
				std::stringstream ss;
				ss << str;
				ss >> product->amount;
				ss.clear();
			}
			break;
		}
		default:
		{
			break;
		}
	}
	return product;
}
