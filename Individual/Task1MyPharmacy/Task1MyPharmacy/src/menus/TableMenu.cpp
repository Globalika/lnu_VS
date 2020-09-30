#include <iostream>
#include <sstream>
#include <fstream>
#include <algorithm>
#include <exception>

#include "TableMenu.h"

TableMenu::TableMenu()
{
	this->repository = new TablesRepository;
}

void TableMenu::ShowTableMenu(int tableTypeNumber)
{
	if (tableTypeNumber == 1)
	{
		products = repository->GetMedicinesTable()->GetAll();
	}
	else if (tableTypeNumber == 2)
	{
		products = repository->GetCosmeticsTable()->GetAll();
	}
	this->currentId = products->at(0)->id;
	PrintTableForm(tableTypeNumber);
	int catcher;
	do
	{
		catcher = GETCH;
		switch (catcher)
		{
		case TableMenuCommands::Up:
		{
			MoveCursorByProductId(-1);
			PrintTableForm(tableTypeNumber);
			break;
		}
		case TableMenuCommands::Down:
		{
			MoveCursorByProductId(1);
			PrintTableForm(tableTypeNumber);
			break;
		}
		case TableMenuCommands::SelectCurrentProduct:
		{
			ProductMenu productMenu;
			productMenu.ShowProductMenu(tableTypeNumber, this->currentId);
			UpdateDataForTableMenu(tableTypeNumber);
			//currentId = products->at(0)->id;
			PrintTableForm(tableTypeNumber);
			break;
		}
		case TableMenuCommands::SortTableById:
		{
			PrintSortTable(tableTypeNumber);
			break;
		}
		case TableMenuCommands::CreateNewProduct:
		{
			std::cout << "Create new product? | 0 : No | 1 : Yes" << std::endl;
			int i = GETCH;
			if (i == 1)
			{
				if (tableTypeNumber == 1)
				{
					MedicinesProduct* product = new MedicinesProduct;
					std::string str; int k;

					std::cout << "Id (Example : 9999) : "; std::cin >> k;
					product->id = k; std::cout << '\n';

					std::cout << "Expiration Date (Example : 12.12.2012) : "; std::cin >> str;
					product->expirationDate = str; std::cout << '\n';

					std::cout << "Name (Example : Kfehjvre) : "; std::cin >> str;
					product->name = str; std::cout << '\n';

					std::cout << "Storage Temprature (Example : 23) : "; std::cin >> str;
					product->storageTemperature = k; std::cout << '\n';

					std::cout << "Amount (Example : 44) : "; std::cin >> k;
					product->amount = k; std::cout << '\n';

					repository->GetMedicinesTable()->Create(*product);
					products = repository->GetMedicinesTable()->GetAll();
				}
				else if (tableTypeNumber == 2)
				{
					CosmeticsProduct* product = new CosmeticsProduct;
					std::string str; int k;

					std::cout << "Id (Example : 9999) : "; std::cin >> k;
					product->id = k; std::cout << '\n';

					std::cout << "Expiration Date (Example : 12.12.2012) : "; std::cin >> str;
					product->expirationDate = str; std::cout << '\n';

					std::cout << "Name (Example : Kfehjvre) : "; std::cin >> str;
					product->name = str; std::cout << '\n';

					std::cout << "Storage Form Type (Example : 23) : "; std::cin >> str;
					product->storageFormType = str; std::cout << '\n';

					std::cout << "Capacity (Example : 44) : "; std::cin >> k;
					product->capacity = k; std::cout << '\n';

					std::cout << "Amount (Example : 44) : "; std::cin >> k;
					product->amount = k; std::cout << '\n';

					repository->GetCosmeticsTable()->Create(*product);
					products = repository->GetCosmeticsTable()->GetAll();
				}
				currentId = products->at(0)->id;
			}
			PrintTableForm(tableTypeNumber);
			break;
		}
		case TableMenuCommands::DeleteCurrentProduct:
		{
			std::cout << "Delete current product? | 0 : No | 1 : Yes" << std::endl;
			int catcher = GETCH;
			if (catcher == 1)
			{
				if (tableTypeNumber == 1)
				{
					repository->GetMedicinesTable()->Delete(currentId);
					products = repository->GetMedicinesTable()->GetAll();
				}
				else if (tableTypeNumber == 2)
				{
					repository->GetCosmeticsTable()->Delete(currentId);
					products = repository->GetCosmeticsTable()->GetAll();
				}
				currentId = products->at(0)->id;
			}
			PrintTableForm(tableTypeNumber);
			break;
		}
		default:
		{
			continue;
		}
		}
	} while (catcher != TableMenuCommands::TableMenuBack);
}

void TableMenu::PrintTableForm(int tableTypeNumber)
{
	std::system("cls");
	if (tableTypeNumber == 1)
	{
		std::cout << "\t\t\t Medicines Table \t\t\t \n\n";
	}
	else if (tableTypeNumber == 2)
	{
		std::cout << "\t\t\t Cosmetics Table \t\t\t \n\n";
	}
	std::cout << TableMenuCommands::TableMenuBack << " : Back | "
		<< TableMenuCommands::Up << " : Up | "
		<< TableMenuCommands::Down << " : Down | "
		<< TableMenuCommands::SelectCurrentProduct << " : Select Current Product\n"
		<< TableMenuCommands::SortTableById << " : Sort Table By Id | "
		<< TableMenuCommands::CreateNewProduct << " : Create NewProduct | "
		<< TableMenuCommands::DeleteCurrentProduct << " : Delete Current Product";
	SetState(TableMenuWaiting);
	PrintTable(tableTypeNumber);
}

void TableMenu::PrintTable(int tableTypeNumber)
{
	if (tableTypeNumber == 1)
	{
		std::cout << "\n\n";
		std::cout << "ID | expirationDate | Name | StorageTemprature | Amount";
		std::cout << "\n\n";
		for (auto it : *products)
		{
			MedicinesProduct& p = dynamic_cast<MedicinesProduct&>(*it);
			if (p.id == this->currentId)
			{
				std::cout << " ->  ";
			}

			std::cout << std::to_string(p.id) << " | "
				<< p.expirationDate << " | "
				<< p.name << " | "
				<< p.storageTemperature << " | "
				<< std::to_string(p.amount)
				<< std::endl;
		}
	}
	else if (tableTypeNumber == 2)
	{
		std::cout << "\n\n";
		std::cout << "ID | expirationDate | Name | storageFormType | Capacity | Amount";
		std::cout << "\n\n";
		for (auto it : *products)
		{
			CosmeticsProduct& p = dynamic_cast<CosmeticsProduct&>(*it);
			if (p.id == this->currentId)
			{
				std::cout << " ->  ";
			}
			std::cout << std::to_string(p.id) << " | "
				<< p.expirationDate << " | "
				<< p.name << " | "
				<< p.storageFormType << " | "
				<< std::to_string(p.capacity) << " | "
				<< std::to_string(p.amount)
				<< std::endl;
		}
	}
	std::cout << "\n\n";
}

void TableMenu::PrintSortTable(int tableTypeNumber)
{
	if (products->at(0)->id > products->at(1)->id)
	{
		std::sort(products->begin(), products->end(), [](const Product* p1, const Product* p2)
			{
				return p1->id < p2->id;
			});
	}
	else
	{
		std::sort(products->begin(), products->end(), [](const Product* p1, const Product* p2)
			{
				return p1->id > p2->id;
			});
	}
	std::system("cls");
	if (tableTypeNumber == 1)
	{
		std::cout << "\t\t\t Medicines Table \t\t\t \n\n";
	}
	else if (tableTypeNumber == 2)
	{
		std::cout << "\t\t\t Cosmetics Table \t\t\t \n\n";
	}
	std::cout << TableMenuCommands::TableMenuBack << " : Back | "
		<< TableMenuCommands::Up << " : Up | "
		<< TableMenuCommands::Down << " : Down | "
		<< TableMenuCommands::SelectCurrentProduct << " : Select Current Product\n"
		<< TableMenuCommands::SortTableById << " : Sort Table By Id | "
		<< TableMenuCommands::CreateNewProduct << " : Create NewProduct | "
		<< TableMenuCommands::DeleteCurrentProduct << " : Delete Current Product";
	SetState(TableMenuWaiting);
	if (tableTypeNumber == 1)
	{
		std::cout << "\n\n";
		std::cout << "ID | expirationDate | Name | StorageTemprature | Amount";
		std::cout << "\n\n";
		for (auto it : *products)
		{
			MedicinesProduct& p = dynamic_cast<MedicinesProduct&>(*it);
			if (p.id == this->currentId)
			{
				std::cout << " ->  ";
			}

			std::cout << std::to_string(p.id) << " | "
				<< p.expirationDate << " | "
				<< p.name << " | "
				<< p.storageTemperature << " | "
				<< std::to_string(p.amount)
				<< std::endl;
		}
	}
	else if (tableTypeNumber == 2)
	{
		std::cout << "\n\n";
		std::cout << "ID | expirationDate | Name | storageFormType | Capacity | Amount";
		std::cout << "\n\n";
		for (auto it : *products)
		{
			CosmeticsProduct& p = dynamic_cast<CosmeticsProduct&>(*it);
			if (p.id == this->currentId)
			{
				std::cout << " ->  ";
			}
			std::cout << std::to_string(p.id) << " | "
				<< p.expirationDate << " | "
				<< p.name << " | "
				<< p.storageFormType << " | "
				<< std::to_string(p.capacity) << " | "
				<< std::to_string(p.amount)
				<< std::endl;
		}
	}
}

void TableMenu::UpdateDataForTableMenu(int tableTypeNumber)
{
	delete products;
	delete[] repository;
	repository = new TablesRepository;
	//currentId = products->at(0)->id;
	if (tableTypeNumber == 1)
	{
		products = repository->GetMedicinesTable()->GetAll();
	}
	else if (tableTypeNumber == 2)
	{
		products = repository->GetCosmeticsTable()->GetAll();
	}
}

void TableMenu::MoveCursorByProductId(int n)
{
	if (n == 1)
	{
		if (currentId == products->at(products->size() - 1)->id)
		{
			return;
		}
	}
	else
	{
		if (currentId == products->at(0)->id)
		{
			return;
		}
	}
	int i = 0;
	while (products->at(i)->id != currentId)
	{
		i++;
	}
	currentId = products->at(i + n)->id;
}

TableMenu::~TableMenu()
{
	delete repository;
}

