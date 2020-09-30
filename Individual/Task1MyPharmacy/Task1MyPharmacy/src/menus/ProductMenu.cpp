#include <iostream>
#include <sstream>
#include <fstream>
#include <algorithm>
#include <exception>

#include "BaseMenu.h"
#include "ProductMenu.h"

ProductMenu::ProductMenu()
{
	this->repository = new TablesRepository;
}

void ProductMenu::ShowProductMenu(int tableTypeNumber, int Id)
{
	this->currentId = Id;
	PrintProductForm(tableTypeNumber);
	std::string str;
	int i;
	do
	{
		i = GETCH;
		switch (i)
		{
			case ProductMenuCommands::ProductFieldUp:
			{
				if (currentProductFieldId != 1) { currentProductFieldId--; }
				PrintProductForm(tableTypeNumber);
				break;
			}
			case ProductMenuCommands::ProductFieldDown:
			{
				if (currentProductFieldId != 4 - 1 + tableTypeNumber) { currentProductFieldId++; }
				PrintProductForm(tableTypeNumber);
				break;
			}
			case ProductMenuCommands::ChangeCurrentField:
			{
				//
				std::cout << "Change this field ? | 0 : No | 1 : Yes" << std::endl;
				int i = GETCH;
				if (i == 1)
				{
					if (tableTypeNumber == 1)
					{
						repository->GetMedicinesTable()->Update(*ChangeCurrentFieldById(tableTypeNumber, currentProductFieldId));
						products = repository->GetMedicinesTable()->GetAll();
					}
					else if (tableTypeNumber == 2)
					{
						repository->GetCosmeticsTable()->Update(*ChangeCurrentFieldById(tableTypeNumber, currentProductFieldId));
						products = repository->GetCosmeticsTable()->GetAll();
					}
				}
				//
				currentProductFieldId = 1;
				PrintProductForm(tableTypeNumber);
				break;
			}
			default:
			{
				continue;
			}
		}
	} while (i != ProductMenuCommands::ProductMenuBack);
}
void ProductMenu::PrintProduct(int tableTypeNumber)
{
	if (tableTypeNumber == 1)
	{
		products = repository->GetMedicinesTable()->GetAll();
		MedicinesProduct* product = new MedicinesProduct;
		for (auto it : *products)
		{
			if (it->id == currentId)
			{
				product = dynamic_cast<MedicinesProduct*>(it);
			}
		}
		std::cout << "\n\n";
		std::cout << "Id : " << product->id << std::endl << std::endl;

		if (currentProductFieldId == 1) { std::cout << " ->  "; }
		std::cout << "Expiration Date : " << product->expirationDate << std::endl;

		if (currentProductFieldId == 2) { std::cout << " ->  "; }
		std::cout << "Name : " << product->name << std::endl;

		if (currentProductFieldId == 3) { std::cout << " ->  "; }
		std::cout << "Storage Temperature : " << product->storageTemperature << std::endl;

		if (currentProductFieldId == 4) { std::cout << " ->  "; }
		std::cout << "Amount : " << product->amount << std::endl;
		std::cout << "\n\n";
	}
	else if (tableTypeNumber == 2)
	{
		products = repository->GetCosmeticsTable()->GetAll();
		CosmeticsProduct* product = new CosmeticsProduct;
		for (auto it : *products)
		{
			if (it->id == currentId)
			{
				product = dynamic_cast<CosmeticsProduct*>(it);
			}
		}
		std::cout << "\n\n";
		std::cout << "Id : " << product->id << std::endl << std::endl;

		if (currentProductFieldId == 1) { std::cout << " ->  "; }
		std::cout << "Expiration Date : " << product->expirationDate << std::endl;

		if (currentProductFieldId == 2) { std::cout << " ->  "; }
		std::cout << "Name : " << product->name << std::endl;

		if (currentProductFieldId == 3) { std::cout << " ->  "; }
		std::cout << "Storage Form Type : " << product->storageFormType << std::endl;

		if (currentProductFieldId == 4) { std::cout << " ->  "; }
		std::cout << "Capacity : " << product->capacity << std::endl;

		if (currentProductFieldId == 5) { std::cout << " ->  "; }
		std::cout << "Amount : " << product->amount << std::endl;
		std::cout << "\n\n";
	}
	
}

void ProductMenu::CheckProductDate(std::string str)
{
	if (!(str.at(2) == 46 && str.at(5) == 46 && str.size() == 10))
	{
		throw std::exception();
	}
	for (int i = 0; i < str.size(); i++)
	{
		if (i == 2 || i == 5)
		{
			continue;
		}
		else if (!(str[i] >= 48 && str[i] <= 58))
		{
			throw std::exception();
		}
	}
	if ((str.at(0)-48) * 10 + (str.at(1)-48) < 1 || ((str.at(0)-48) * 10 + (str.at(1)-48)) > 31)
	{
		throw std::exception();
	}
	if ((str.at(3) - 48) * 10 + (str.at(4) - 48) < 1 || ((str.at(3) - 48) * 10 + (str.at(4) - 48)) > 12)
	{
		throw std::exception();
	}
	if (((str.at(6)-48) * 1000 + (str.at(7)-48) * 100 + (str.at(8)-48) * 10 + (str.at(9)-48)) < 2020 || ((str.at(6) - 48) * 1000 + (str.at(7) - 48) * 100 + (str.at(8) - 48) * 10 + (str.at(9) - 48)) > 2300)
	{
		throw std::exception();
	}
}
void ProductMenu::CheckProductString(std::string str)
{
	for (auto i : str)
	{
		if (!((i >= 65 && i <= 90) || (i >= 97 && i <= 122)))
		{
			throw std::exception();
		}
	}
}
void ProductMenu::CheckProductInt(std::string str)
{
	for (auto i : str)
	{
		if (!(i >= 48 && i <= 58))
		{
			throw std::exception();
		}
	}
}

std::string ProductMenu::CreateNewDate(int tableTypeNumber)
{
	std::string str;
	bool isTrue = true;
	while (isTrue)
	{
		try
		{
			isTrue = false;
			std::cout << "New Date : ";
			std::cin >> str;
			CheckProductDate(str);
		}
		catch (const std::exception& err)
		{
			PrintProductForm(tableTypeNumber);
			std::cout << "Wrong form! Please, type date like this example: dd.mm.yyyy" << std::endl;
			isTrue = true;
		}
	}
	return str;
}

std::string ProductMenu::CreateNewString(int tableTypeNumber)
{
	std::string str;
	bool isTrue = true;
	while (isTrue)
	{
		try
		{
			isTrue = false;
			std::cout << "New Line : ";
			std::cin >> str;
			CheckProductString(str);
		}
		catch (const std::exception& err)
		{
			PrintProductForm(tableTypeNumber);
			std::cout << "Wrong! Please, try again." << std::endl;
			isTrue = true;
		}
	}
	return str;
}

std::string ProductMenu::CreateNewInt(int tableTypeNumber)
{
	std::string str;
	bool isTrue = true;
	while (isTrue)
	{
		try
		{
			isTrue = false;
			std::cout << "New Line : ";
			std::cin >> str;
			CheckProductInt(str);
		}
		catch (const std::exception& err)
		{
			PrintProductForm(tableTypeNumber);
			std::cout << "Wrong format! Please, use only numbers." << std::endl;
			isTrue = true;
		}
	}
	return str;
}

ProductMenu::~ProductMenu()
{
}

Product* ProductMenu::ChangeCurrentFieldById(int tableTypeNumber, int Id)
{
	if (tableTypeNumber == 1)
	{
		MedicinesProduct* product = (MedicinesProduct*)(repository->GetMedicinesTable()->GetById(currentId));
		switch (Id)
		{
			case 1:
			{
				product->expirationDate = CreateNewDate(tableTypeNumber);
				break;
			}
			case 2:
			{
				product->name = CreateNewString(tableTypeNumber);
				break;
			}
			case 3:
			{
				std::string str = CreateNewInt(tableTypeNumber);
				std::stringstream ss;
				ss << str;
				ss >> product->storageTemperature;
				ss.clear();
				break;
			}
			case 4:
			{
				std::string str = CreateNewInt(tableTypeNumber);
				std::stringstream ss;
				ss << str;
				ss >> product->amount;
				ss.clear();
				break;
			}
			default:
			{
				break;
			}
		}
		return product;
	}
	else if (tableTypeNumber == 2)
	{
		CosmeticsProduct* product = (CosmeticsProduct*)(repository->GetCosmeticsTable()->GetById(currentId));
		switch (Id)
		{
			case 1:
			{
				product->expirationDate = CreateNewDate(tableTypeNumber);
				break;
			}
			case 2:
			{
				product->name = CreateNewString(tableTypeNumber);
				break;
			}
			case 3:
			{
				product->storageFormType = CreateNewInt(tableTypeNumber);
				break;
			}
			case 4:
			{
				std::string str = CreateNewInt(tableTypeNumber);
				std::stringstream ss;
				ss << str;
				ss >> product->capacity;
				ss.clear();
				break;
			}
			case 5:
			{
				std::string str = CreateNewInt(tableTypeNumber);
				std::stringstream ss;
				ss << str;
				ss >> product->amount;
				ss.clear();
				break;
			}
			default:
			{
				break;
			}
		}
		return product;
	}
}

void ProductMenu::PrintProductForm(int tableTypeNumber)
{
	std::system("cls");
	if (tableTypeNumber == 1)
	{
		std::cout << "\t\t\t Medicines Product \t\t\t \n\n";

	}
	else if (tableTypeNumber == 2)
	{
		std::cout << "\t\t\t Cosmetics Product \t\t\t \n\n";

	}
	std::cout << ProductMenuCommands::ProductMenuBack << " : Back | "
		<< ProductMenuCommands::ProductFieldUp << " : Move Current Field Up | "
		<< ProductMenuCommands::ProductFieldDown << " : Move Current Field Down | "
		<< ProductMenuCommands::ChangeCurrentField << " : ChangeCurrentField";
	SetState(ProductMenuWaiting);
	PrintProduct(tableTypeNumber);
}
