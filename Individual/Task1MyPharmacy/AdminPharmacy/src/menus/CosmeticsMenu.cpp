#include "CosmeticsMenu.h"

void CosmeticsMenu::ShowTableMenu()
{

	products = repository->GetCosmeticsTable()->GetAll();
	this->currentId = products->at(0)->id;
	PrintTableForm();
	int catcher;
	do
	{
		catcher = GETCH;
		switch (catcher)
		{
		case TableMenuCommands::Up:
		{
			MoveCursorByProductId(-1);
			PrintTableForm();
			break;
		}
		case TableMenuCommands::Down:
		{
			MoveCursorByProductId(1);
			PrintTableForm();
			break;
		}
		case TableMenuCommands::SelectCurrentProduct:
		{
			ShowProductMenu(this->currentId);
			//UpdateDataForTableMenu();
			PrintTableForm();
			break;
		}
		case TableMenuCommands::SortTableById:
		{
			PrintSortTable();
			break;
		}
		case TableMenuCommands::CreateNewProduct:
		{
			std::cout << "Create new product? | 0 : No | 1 : Yes" << std::endl;
			int i = GETCH;
			if (i == 1)
			{
				
				CreateNewProductForm();				
				currentId = products->at(0)->id;
			}
			PrintTableForm();
			break;
		}
		case TableMenuCommands::DeleteCurrentProduct:
		{
			std::cout << "Delete current product? | 0 : No | 1 : Yes" << std::endl;
			int catcher = GETCH;
			if (catcher == 1)
			{
				repository->GetCosmeticsTable()->Delete(currentId);
				products = repository->GetCosmeticsTable()->GetAll();
				currentId = products->at(0)->id;
			}
			PrintTableForm();
			break;
		}
		default:
		{
			continue;
		}
		}
	} while (catcher != TableMenuCommands::TableMenuBack);
}

void CosmeticsMenu::PrintTable()
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
	std::cout << "\n\n";
}

void CosmeticsMenu::PrintTableForm()
{
	std::system("cls");
	std::cout << "\t\t\t Cosmetics Table \t\t\t \n\n";
	std::cout << TableMenuCommands::TableMenuBack << " : Back | "
		<< TableMenuCommands::Up << " : Up | "
		<< TableMenuCommands::Down << " : Down | "
		<< TableMenuCommands::SelectCurrentProduct << " : Select Current Product\n"
		<< TableMenuCommands::SortTableById << " : Sort Table By Id | "
		<< TableMenuCommands::CreateNewProduct << " : Create NewProduct | "
		<< TableMenuCommands::DeleteCurrentProduct << " : Delete Current Product";
	SetState(TableMenuWaiting);
	PrintTable();
}

void CosmeticsMenu::PrintSortTable()
{
	std::system("cls");

	if (products->at(0)->id > products->at(1)->id)
	{
		std::sort(products->begin(), products->end(), [](const CosmeticsProduct* p1, const CosmeticsProduct* p2)
			{
				return p1->id < p2->id;
			});
	}
	else
	{
		std::sort(products->begin(), products->end(), [](const CosmeticsProduct* p1, const CosmeticsProduct* p2)
			{
				return p1->id > p2->id;
			});
	}
	std::cout << "\t\t\t Cosmetics Table \t\t\t \n\n";
	
	std::cout << TableMenuCommands::TableMenuBack << " : Back | "
		<< TableMenuCommands::Up << " : Up | "
		<< TableMenuCommands::Down << " : Down | "
		<< TableMenuCommands::SelectCurrentProduct << " : Select Current Product\n"
		<< TableMenuCommands::SortTableById << " : Sort Table By Id | "
		<< TableMenuCommands::CreateNewProduct << " : Create NewProduct | "
		<< TableMenuCommands::DeleteCurrentProduct << " : Delete Current Product";
	SetState(TableMenuWaiting);

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

void CosmeticsMenu::UpdateDataForTableMenu()
{
	delete products;
	delete[] repository;
	repository = new TablesRepository;
	products = repository->GetCosmeticsTable()->GetAll();
}

void CosmeticsMenu::MoveCursorByProductId(int n)
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

void CosmeticsMenu::CreateNewProductForm()
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

CosmeticsProduct* CosmeticsMenu::ChangeCurrentFieldById(int Id)
{
	CosmeticsProduct* product = (CosmeticsProduct*)(repository->GetMedicinesTable()->GetById(currentId));
	switch (Id)
	{
	case 1:
	{
		product->expirationDate = CreateNewDate();
		break;
	}
	case 2:
	{
		product->name = CreateNewString();
		break;
	}
	case 3:
	{
		std::string str = CreateNewInt();
		std::stringstream ss;
		ss << str;
		ss >> product->storageFormType;
		ss.clear();
		break;
	}
	case 4:
	{
		std::string str = CreateNewInt();
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

void CosmeticsMenu::ShowProductMenu(int Id)
{
	this->currentId = Id;
	PrintProductForm();
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
			PrintProductForm();
			break;
		}
		case ProductMenuCommands::ProductFieldDown:
		{
			if (currentProductFieldId != 5) { currentProductFieldId++; }
			PrintProductForm();
			break;
		}
		case ProductMenuCommands::ChangeCurrentField:
		{
			//
			std::cout << "Change this field ? | 0 : No | 1 : Yes" << std::endl;
			int i = GETCH;
			if (i == 1)
			{
				repository->GetCosmeticsTable()->Update(*ChangeCurrentFieldById(currentProductFieldId));
				products = repository->GetCosmeticsTable()->GetAll();
			}
			//
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

void CosmeticsMenu::PrintProduct()
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

void CosmeticsMenu::PrintProductForm()
{
	std::system("cls");
	std::cout << "\t\t\t Cosmetics Product \t\t\t \n\n";
	std::cout << ProductMenuCommands::ProductMenuBack << " : Back | "
		<< ProductMenuCommands::ProductFieldUp << " : Move Current Field Up | "
		<< ProductMenuCommands::ProductFieldDown << " : Move Current Field Down | "
		<< ProductMenuCommands::ChangeCurrentField << " : ChangeCurrentField";
	SetState(ProductMenuWaiting);
	PrintProduct();
}



void CosmeticsMenu::CheckProductString(std::string str)
{
	for (auto i : str)
	{
		if (!((i >= 65 && i <= 90) || (i >= 97 && i <= 122)))
		{
			throw std::exception();
		}
	}
}

void CosmeticsMenu::CheckProductDate(std::string str)
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
	if ((str.at(0) - 48) * 10 + (str.at(1) - 48) < 1 || ((str.at(0) - 48) * 10 + (str.at(1) - 48)) > 31)
	{
		throw std::exception();
	}
	if ((str.at(3) - 48) * 10 + (str.at(4) - 48) < 1 || ((str.at(3) - 48) * 10 + (str.at(4) - 48)) > 12)
	{
		throw std::exception();
	}
	if (((str.at(6) - 48) * 1000 + (str.at(7) - 48) * 100 + (str.at(8) - 48) * 10 + (str.at(9) - 48)) < 2020 || ((str.at(6) - 48) * 1000 + (str.at(7) - 48) * 100 + (str.at(8) - 48) * 10 + (str.at(9) - 48)) > 2300)
	{
		throw std::exception();
	}
}

void CosmeticsMenu::CheckProductInt(std::string str)
{
	for (auto i : str)
	{
		if (!(i >= 48 && i <= 58))
		{
			throw std::exception();
		}
	}
}

std::string CosmeticsMenu::CreateNewDate()
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
			PrintProductForm();
			std::cout << "Wrong form! Please, type date like this example: dd.mm.yyyy" << std::endl;
			isTrue = true;
		}
	}
	return str;
}

std::string CosmeticsMenu::CreateNewString()
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
			PrintProductForm();
			std::cout << "Wrong! Please, try again." << std::endl;
			isTrue = true;
		}
	}
	return str;
}

std::string CosmeticsMenu::CreateNewInt()
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
			PrintProductForm();
			std::cout << "Wrong format! Please, use only numbers." << std::endl;
			isTrue = true;
		}
	}
	return str;
}
