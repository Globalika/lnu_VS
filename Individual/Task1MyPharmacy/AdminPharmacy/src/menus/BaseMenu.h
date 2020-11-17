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
//	void ShowTableMenu();
//	virtual void PrintTable() {}
//	virtual void PrintTableForm() {}
//	virtual void PrintSortTable() {}
//	virtual void UpdateDataForTableMenu() {}
//	virtual void MoveCursorByProductId() {}
//
//
//
//	~BaseMenu() {}
////
//	//enum TableMenuCommands {
//	//	TableMenuBack,
//	//	Up,
//	//	Down,
//	//	SelectCurrentProduct,
//	//	SortTableById,
//	//	CreateNewProduct,//
//	//	DeleteCurrentProduct,//
//	//	TableMenuWaiting,
//	//};
//	//void SetState(TableMenuCommands state)
//	//{
//	//	this->tState = state;
//	//}
////
//	void ShowProductMenu(int Id);
//	virtual void PrintProduct() {}
//	virtual void PrintProductForm() {}
//	void CheckProductString(std::string str);
//	void CheckProductDate(std::string str);
//	void CheckProductInt(std::string str);
//	std::string CreateNewDate();
//	std::string CreateNewString();
//	std::string CreateNewInt();
	//ProductType* ChangeCurrentFieldById(int Id);
//
	/*enum ProductMenuCommands {
		ProductMenuBack,
		ProductFieldUp,
		ProductFieldDown,
		ChangeCurrentField,
		ProductMenuWaiting,
	};
	void SetState(ProductMenuCommands state)
	{
		this->pState = state;
	}*/
//
protected:
	//TablesRepository* repository;
	//int currentId;
	//std::vector<ProductType*>* products;
	////TableMenuCommands tState;


	////ProductMenuCommands pState;
	//int currentProductFieldId = 1;

};
//
//////
//
//
//template<typename TableType, typename ProductType>
//void BaseMenu<TableType, ProductType>::ShowTableMenu()
//{
//	products = repository->GetCosmeticsTable()->GetAll();
//	this->currentId = products->at(0)->id;
//	PrintTableForm();
//	int catcher;
//	do
//	{
//		catcher = GETCH;
//		switch (catcher)
//		{
//		case TableMenuCommands::Up:
//		{
//			MoveCursorByProductId(-1);
//			PrintTableForm();
//			break;
//		}
//		case TableMenuCommands::Down:
//		{
//			MoveCursorByProductId(1);
//			PrintTableForm();
//			break;
//		}
//		case TableMenuCommands::SelectCurrentProduct:
//		{
//			ShowProductMenu(this->currentId);
//			UpdateDataForTableMenu();
//			PrintTableForm();
//			break;
//		}
//		case TableMenuCommands::SortTableById:
//		{
//			PrintSortTable();
//			break;
//		}
//		case TableMenuCommands::CreateNewProduct:
//		{
//			std::cout << "Create new product? | 0 : No | 1 : Yes" << std::endl;
//			int i = GETCH;
//			if (i == 1)
//			{
//
//				CreateNewProductForm();
//				currentId = products->at(0)->id;
//			}
//			PrintTableForm();
//			break;
//		}
//		case TableMenuCommands::DeleteCurrentProduct:
//		{
//			std::cout << "Delete current product? | 0 : No | 1 : Yes" << std::endl;
//			int catcher = GETCH;
//			if (catcher == 1)
//			{
//				repository->GetCosmeticsTable()->Delete(currentId);
//				products = repository->GetCosmeticsTable()->GetAll();
//				currentId = products->at(0)->id;
//			}
//			PrintTableForm();
//			break;
//		}
//		default:
//		{
//			continue;
//		}
//		}
//	} while (catcher != TableMenuCommands::TableMenuBack);
//}
//
//template<typename TableType, typename ProductType>
//void BaseMenu<TableType, ProductType>::ShowProductMenu(int Id)
//{
//	this->currentId = Id;
//	PrintProductForm();
//	std::string str;
//	int i;
//	do
//	{
//		i = GETCH;
//		switch (i)
//		{
//		case ProductMenuCommands::ProductFieldUp:
//		{
//			if (currentProductFieldId != 1) { currentProductFieldId--; }
//			PrintProductForm();
//			break;
//		}
//		case ProductMenuCommands::ProductFieldDown:
//		{
//			if (currentProductFieldId != 4) { currentProductFieldId++; }
//			PrintProductForm();
//			break;
//		}
//		case ProductMenuCommands::ChangeCurrentField:
//		{
//			//
//			std::cout << "Change this field ? | 0 : No | 1 : Yes" << std::endl;
//			int i = GETCH;
//			if (i == 1)
//			{
//				repository->GetMedicinesTable()->Update(*ChangeCurrentFieldById(currentProductFieldId));
//				products = repository->GetMedicinesTable()->GetAll();
//			}
//			//
//			currentProductFieldId = 1;
//			PrintProductForm();
//			break;
//		}
//		default:
//		{
//			continue;
//		}
//		}
//	} while (i != ProductMenuCommands::ProductMenuBack);
//}
//
//
//template<typename TableType, typename ProductType>
//void BaseMenu<TableType, ProductType>::CheckProductString(std::string str)
//{
//	for (auto i : str)
//	{
//		if (!((i >= 65 && i <= 90) || (i >= 97 && i <= 122)))
//		{
//			throw std::exception();
//		}
//	}
//}
//
//template<typename TableType, typename ProductType>
//void BaseMenu<TableType, ProductType>::CheckProductDate(std::string str)
//{
//	if (!(str.at(2) == 46 && str.at(5) == 46 && str.size() == 10))
//	{
//		throw std::exception();
//	}
//	for (int i = 0; i < str.size(); i++)
//	{
//		if (i == 2 || i == 5)
//		{
//			continue;
//		}
//		else if (!(str[i] >= 48 && str[i] <= 58))
//		{
//			throw std::exception();
//		}
//	}
//	if ((str.at(0) - 48) * 10 + (str.at(1) - 48) < 1 || ((str.at(0) - 48) * 10 + (str.at(1) - 48)) > 31)
//	{
//		throw std::exception();
//	}
//	if ((str.at(3) - 48) * 10 + (str.at(4) - 48) < 1 || ((str.at(3) - 48) * 10 + (str.at(4) - 48)) > 12)
//	{
//		throw std::exception();
//	}
//	if (((str.at(6) - 48) * 1000 + (str.at(7) - 48) * 100 + (str.at(8) - 48) * 10 + (str.at(9) - 48)) < 2020 || ((str.at(6) - 48) * 1000 + (str.at(7) - 48) * 100 + (str.at(8) - 48) * 10 + (str.at(9) - 48)) > 2300)
//	{
//		throw std::exception();
//	}
//}
//
//template<typename TableType, typename ProductType>
//void BaseMenu<TableType, ProductType>::CheckProductInt(std::string str)
//{
//	for (auto i : str)
//	{
//		if (!(i >= 48 && i <= 58))
//		{
//			throw std::exception();
//		}
//	}
//}
//
//template<typename TableType, typename ProductType>
//std::string BaseMenu<TableType, ProductType>::CreateNewDate()
//{
//	std::string str;
//	bool isTrue = true;
//	while (isTrue)
//	{
//		try
//		{
//			isTrue = false;
//			std::cout << "New Date : ";
//			std::cin >> str;
//			CheckProductDate(str);
//		}
//		catch (const std::exception& err)
//		{
//			PrintProductForm();
//			std::cout << "Wrong form! Please, type date like this example: dd.mm.yyyy" << std::endl;
//			isTrue = true;
//		}
//	}
//	return str;
//}
//
//template<typename TableType, typename ProductType>
//std::string BaseMenu<TableType, ProductType>::CreateNewString()
//{
//	std::string str;
//	bool isTrue = true;
//	while (isTrue)
//	{
//		try
//		{
//			isTrue = false;
//			std::cout << "New Line : ";
//			std::cin >> str;
//			CheckProductString(str);
//		}
//		catch (const std::exception& err)
//		{
//			PrintProductForm();
//			std::cout << "Wrong! Please, try again." << std::endl;
//			isTrue = true;
//		}
//	}
//	return str;
//}
//
//template<typename TableType, typename ProductType>
//std::string BaseMenu<TableType, ProductType>::CreateNewInt()
//{
//	std::string str;
//	bool isTrue = true;
//	while (isTrue)
//	{
//		try
//		{
//			isTrue = false;
//			std::cout << "New Line : ";
//			std::cin >> str;
//			CheckProductInt(str);
//		}
//		catch (const std::exception& err)
//		{
//			PrintProductForm();
//			std::cout << "Wrong format! Please, use only numbers." << std::endl;
//			isTrue = true;
//		}
//	}
//	return str;
//}
//
//
//
//
//
//
//
//
////template<typename TableType, typename ProductType>
////ProductType* BaseMenu<TableType, ProductType>::ChangeCurrentFieldById(int Id)
////{
////	ProductType* product = (ProductType*)(repository->GetMedicinesTable()->GetById(currentId));
////	switch (Id)
////	{
////	case 1:
////	{
////		product->expirationDate = CreateNewDate();
////		break;
////	}
////	case 2:
////	{
////		product->name = CreateNewString();
////		break;
////	}
////	case 3:
////	{
////		std::string str = CreateNewInt();
////		std::stringstream ss;
////		ss << str;
////		ss >> product->storageTemperature;
////		ss.clear();
////		break;
////	}
////	case 4:
////	{
////		std::string str = CreateNewInt();
////		std::stringstream ss;
////		ss << str;
////		ss >> product->amount;
////		ss.clear();
////		break;
////	}
////	default:
////	{
////		break;
////	}
////	}
////	return product;
////}
//
//
//
//
//
//
#endif _BASE_MENU_
