#pragma once
#ifndef _BASE_MENU_
#define _BASE_MENU_

#define GETCH _getch()-48
#include <iostream>
#include <sstream>
#include <conio.h>
#include <fstream>
#include <ostream>
#include <string>
#include <algorithm>
#include <MyPharmacy.h>

template <typename TableType, typename ProductType>
class BaseMenu
{
public:
	virtual void ShowTableMenu() {}
	virtual void PrintTable() {}
	virtual void PrintTableForm() {}
	virtual void PrintSortTable() {}
	virtual void UpdateDataForTableMenu() {}
	void MoveCursorByProductId(int n);
	virtual void CreateNewProductForm() {}
	virtual ~BaseMenu() {}

	enum TableMenuCommands {
		TableMenuBack,
		Up,
		Down,
		SelectCurrentProduct,
		SortTableById,
		OrderCurrentProduct,
		TableOpenCard,
		TableMenuWaiting,
	};
	void SetState(TableMenuCommands state)
	{
		this->tState = state;
	}

	void ShowProductMenu(int Id);

	virtual void PrintProduct() {}
	virtual void PrintProductForm() {}
	void CheckProductString(std::string str);
	void CheckProductDate(std::string str);
	void CheckProductInt(std::string str);
	std::string CreateNewDate();
	std::string CreateNewString();
	std::string CreateNewInt();
	ProductType* ChangeCurrentFieldById(int Id);

	enum ProductMenuCommands {
		ProductMenuBack,
		ProductFieldUp,
		ProductFieldDown,
		ChangeCurrentField,
		ProductMenuWaiting,
	};
	void SetState(ProductMenuCommands state)
	{
		this->pState = state;
	}

protected:
	TablesRepository* repository;
	int currentId;
	std::vector<ProductType*>* products;
	TableMenuCommands tState;
	ProductMenuCommands pState;
	int currentProductFieldId = 1;
	FlyweightFactory factory;
};

template<typename TableType, typename ProductType>
void BaseMenu<TableType, ProductType>::MoveCursorByProductId(int n)
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

template<typename TableType, typename ProductType>
void BaseMenu<TableType, ProductType>::CheckProductString(std::string str)
{
	for (auto i : str)
	{
		if (!((i >= 65 && i <= 90) || (i >= 97 && i <= 122)))
		{
			throw std::exception();
		}
	}
}

template<typename TableType, typename ProductType>
void BaseMenu<TableType, ProductType>::CheckProductDate(std::string str)
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

template<typename TableType, typename ProductType>
void BaseMenu<TableType, ProductType>::CheckProductInt(std::string str)
{
	for (auto i : str)
	{
		if (!(i >= 48 && i <= 58))
		{
			throw std::exception();
		}
	}
}

template<typename TableType, typename ProductType>
std::string BaseMenu<TableType, ProductType>::CreateNewDate()
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

template<typename TableType, typename ProductType>
std::string BaseMenu<TableType, ProductType>::CreateNewString()
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

template<typename TableType, typename ProductType>
std::string BaseMenu<TableType, ProductType>::CreateNewInt()
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
#endif _BASE_MENU_
