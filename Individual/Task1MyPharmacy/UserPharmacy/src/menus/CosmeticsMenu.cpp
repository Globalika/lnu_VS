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
		<< TableMenuCommands::OrderCurrentProduct << " : Order Product | "
		<< TableMenuCommands::TableOpenCard << " : Open Card | ";
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
		<< TableMenuCommands::SortTableById << " : Sort Table By Id | ";
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
		<< ProductMenuCommands::ProductFieldUp << " : Move Up | "
		<< ProductMenuCommands::ProductFieldDown << " : Move Down | "
		<< ProductMenuCommands::ChangeCurrentField << " : ChangeCurrentField";
	SetState(ProductMenuWaiting);
	PrintProduct();
}

void CosmeticsMenu::OrderProduct()
{
	std::cout << "\n\n" << "choose amount: ";
	int amount;
	std::cin >> amount;
	CartProduct cartProduct = TakeAmountFromCurrentProduct(amount);

	repository->GetCosmeticsTable()->Save();
	if (repository->GetCartTable()->IsProductExist(*factory.GetCartFlyweight(cartProduct, amount)))///////////////////////////////////
	{
		factory.GetCartFlyweight(cartProduct, amount)->amount += amount;/////
		repository->GetCartTable()->Update(*factory.GetCartFlyweight(cartProduct, amount));
	}
	else if ((factory.GetCartFlyweight(cartProduct, amount))->amount == 0)
	{
		factory.GetCartFlyweight(cartProduct, amount)->amount += amount;
		repository->GetCartTable()->Create(*factory.GetCartFlyweight(cartProduct, amount));
	}
	else
	{
		repository->GetCartTable()->Create(*factory.GetCartFlyweight(cartProduct, amount));
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

void CosmeticsMenu::OpenCard()
{
	bool w = true;
	while (w)
	{
		PrintTableForm();
		std::cout << "\t\t\t" << "My Cart" << std::endl;
		std::cout << "Product Id || Name || Amount" << "\n\n";
		if ((*repository->GetCartTable()->GetAll()).size() == 0)
		{
			std::cout << "||  " << "Cart is Emply" << std::endl;
			std::cout << "\n\n" << "|| 1 : Back " << std::endl;
		}
		else
		{
			for (auto it : *repository->GetCartTable()->GetAll())
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
			for (auto it : *repository->GetCartTable()->GetAll())
			{
				ReturnProductAmount(it->id, it->name, it->amount);

				//
				CartProduct c;
				c.id = it->id;
				c.name = it->name;
				factory.GetCartFlyweight(c, 0)->amount = 0;
				//
			}
			repository->GetCartTable()->DeleteAll();
			PrintTableForm();
			w = false;
			(*repository->GetCartTable()->GetAll()).clear();
		}
	}
}

CartProduct& CosmeticsMenu::TakeAmountFromCurrentProduct(int amount)
{
	CartProduct* p = new CartProduct;
	products = repository->GetCosmeticsTable()->GetAll();
	for (auto it : *products)
	{
		if (it->id == currentId)
		{
			p->id = it->id;
			p->name = it->name;
			it->amount = it->amount - amount;
		}
	}
	return *p;
}

void CosmeticsMenu::ReturnProductAmount(int id, std::string name, int amount)
{
	products = repository->GetCosmeticsTable()->GetAll();
	for (auto it : *products)
	{
		if (it->id == id)
		{
			it->amount += amount;
		}
	}
	repository->GetCosmeticsTable()->Save();
}

