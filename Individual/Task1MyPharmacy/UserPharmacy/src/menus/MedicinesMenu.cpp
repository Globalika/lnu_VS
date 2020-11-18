#include "MedicinesMenu.h"

void MedicinesMenu::ShowTableMenu()
{

	products = repository->GetMedicinesTable()->GetAll();
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
		case TableMenuCommands::OrderCurrentProduct:
		{
			OrderProduct();
			PrintTableForm();
			break;
		}
		case TableMenuCommands::TableOpenCard:
		{
			OpenCard();
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

void MedicinesMenu::PrintTable()
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
	std::cout << "\n\n";
}

void MedicinesMenu::PrintTableForm()
{
	std::system("cls");
	std::cout << "\t\t\t Medicines Table \t\t\t \n\n";
	std::cout << TableMenuCommands::TableMenuBack << " : Back | "
		<< TableMenuCommands::Up << " : Up | "
		<< TableMenuCommands::Down << " : Down | "
		<< TableMenuCommands::SelectCurrentProduct << " : Select Current Product\n"
		<< TableMenuCommands::SortTableById << " : Sort Table By Id | "
		<< TableMenuCommands::OrderCurrentProduct << " : Order Product | "
		<< TableMenuCommands::TableOpenCard << " : Open Card | ";
	SetState(TableMenuWaiting);
	PrintTable();
}

void MedicinesMenu::PrintSortTable()
{
	std::system("cls");

	if (products->at(0)->id > products->at(1)->id)
	{
		std::sort(products->begin(), products->end(), [](const MedicinesProduct* p1, const MedicinesProduct* p2)
			{
				return p1->id < p2->id;
			});
	}
	else
	{
		std::sort(products->begin(), products->end(), [](const MedicinesProduct* p1, const MedicinesProduct* p2)
			{
				return p1->id > p2->id;
			});
	}
	std::cout << "\t\t\t Medicines Table \t\t\t \n\n";
	
	std::cout << TableMenuCommands::TableMenuBack << " : Back | "
		<< TableMenuCommands::Up << " : Up | "
		<< TableMenuCommands::Down << " : Down | "
		<< TableMenuCommands::SelectCurrentProduct << " : Select Current Product\n"
		<< TableMenuCommands::SortTableById << " : Sort Table By Id | ";
	SetState(TableMenuWaiting);
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

void MedicinesMenu::UpdateDataForTableMenu()
{
	delete products;
	delete[] repository;
	repository = new TablesRepository;
	products = repository->GetMedicinesTable()->GetAll();
}

void MedicinesMenu::MoveCursorByProductId(int n)
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

void MedicinesMenu::CreateNewProductForm()
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

MedicinesProduct* MedicinesMenu::ChangeCurrentFieldById(int Id)
{
	MedicinesProduct* product = (MedicinesProduct*)(repository->GetMedicinesTable()->GetById(currentId));
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
		ss >> product->storageTemperature;
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



void MedicinesMenu::ShowProductMenu(int Id)
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
			if (currentProductFieldId != 4) { currentProductFieldId++; }
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
				repository->GetMedicinesTable()->Update(*ChangeCurrentFieldById(currentProductFieldId));
				products = repository->GetMedicinesTable()->GetAll();
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

void MedicinesMenu::PrintProduct()
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

void MedicinesMenu::PrintProductForm()
{
	std::system("cls");
	std::cout << "\t\t\t Medicines Product \t\t\t \n\n";
	std::cout << ProductMenuCommands::ProductMenuBack << " : Back | "
		<< ProductMenuCommands::ProductFieldUp << " : Move Up | "
		<< ProductMenuCommands::ProductFieldDown << " : Move Down | "
		<< ProductMenuCommands::ChangeCurrentField << " : ChangeCurrentField";
	SetState(ProductMenuWaiting);
	PrintProduct();
}


void MedicinesMenu::CheckProductString(std::string str)
{
	for (auto i : str)
	{
		if (!((i >= 65 && i <= 90) || (i >= 97 && i <= 122)))
		{
			throw std::exception();
		}
	}
}

void MedicinesMenu::CheckProductDate(std::string str)
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

void MedicinesMenu::CheckProductInt(std::string str)
{
	for (auto i : str)
	{
		if (!(i >= 48 && i <= 58))
		{
			throw std::exception();
		}
	}
}

std::string MedicinesMenu::CreateNewDate()
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

std::string MedicinesMenu::CreateNewString()
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

std::string MedicinesMenu::CreateNewInt()
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



void MedicinesMenu::OrderProduct()
{
	std::cout << "\n\n" << "choose amount: ";
	int amount;
	std::cin >> amount;
	CartProduct* p = new CartProduct;
	*p = GetCurrentProductAmount(amount);
	bool state = true;
	for (auto it : cart)
	{
		if (it->id == p->id)
		{
			it->amount += amount;
			state = false;
		}
	}
	if (state)
	{
		cart.push_back(p);//
	}

	repository->GetMedicinesTable()->Save();

	if (repository->GetCartTable()->IsProductExist(*p))
	{
		p->amount += amount;
		repository->GetCartTable()->Update(*p);
	}
	else
	{
		repository->GetCartTable()->Create(*p);
	}
	
	std::cout << "\n" << "product successfully added to cart" << std::endl;

	std::cout << "1 : back to table | 2 : open cart" << std::endl;
	bool w = true;
	while (w)
	{
		int k = GETCH;
		if (k == 1)
		{
			w = false;
		}
		else if (k == 2)
		{
			PrintTableForm();
			OpenCard();
			w = false;
		}
	}

}

void MedicinesMenu::OpenCard()
{
	bool w = true;
	while (w)
	{
		PrintTableForm();
		std::cout << "\t\t\t" << "My Cart" << std::endl;
		std::cout << "Product Id || Name || Amount" << "\n\n";
		if (cart.size() == 0)
		{
			std::cout << "||  " << "Cart is Emply" << std::endl;
			std::cout << "\n\n" << "|| 1 : Back " << std::endl;
		}
		else
		{
			for (auto it : cart)
			{
				std::cout << "||  " << it->id << "|| " << it->name << "|| " << it->amount << std::endl;
			}
			std::cout << "\n\n" << "|| 1 : Back | 2 : Clear Cart" << std::endl;
		}
		int g = GETCH;
		if (g == 1)
		{
			w = false;
		}
		else if (g == 2)
		{
			for (auto it : cart)
			{
				ReturnProductAmount(*it);
			}
			repository->GetCartTable()->DeleteAll();
			PrintTableForm();
		}
	}
}

CartProduct& MedicinesMenu::GetCurrentProductAmount(int amount)
{
	CartProduct* p = new CartProduct;
	products = repository->GetMedicinesTable()->GetAll();
	for (auto it : *products)
	{
		if (it->id == currentId)
		{
			p->id = it->id;
			p->name = it->name;
			p->amount = amount;
			it->amount = it->amount - amount;
		}
	}
	return *p;
}

void MedicinesMenu::ReturnProductAmount(CartProduct& p)
{
	products = repository->GetMedicinesTable()->GetAll();
	for (auto it : *products)
	{
		bool state = (it->id == p.id);
		if (true)
		{
			it->amount + p.amount;
		}
	}
}
