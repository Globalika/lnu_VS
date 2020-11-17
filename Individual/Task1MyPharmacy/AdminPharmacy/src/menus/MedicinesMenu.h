#pragma once
#ifndef _MED_MENU_
#define _MED_MENU_
#include "BaseMenu.h"
//template <typename MedicinesTable, typename MedicinesProduct>
class MedicinesMenu : /*virtual*/ public BaseMenu<MedicinesTable, MedicinesProduct>
{
public:
	MedicinesMenu()/* : BaseMenu() {}*/
	{
		this->repository = new TablesRepository;
	}


	void ShowTableMenu();
	void PrintTable();
	void PrintTableForm();
	void PrintSortTable();
	void UpdateDataForTableMenu();
	void MoveCursorByProductId(int n);

	enum TableMenuCommands {
		TableMenuBack,
		Up,
		Down,
		SelectCurrentProduct,
		SortTableById,
		CreateNewProduct,//
		DeleteCurrentProduct,//
		TableMenuWaiting,
	};
	void SetState(TableMenuCommands state)
	{
		this->tState = state;
	}

	void ShowProductMenu(int Id);
	void PrintProduct();
	void PrintProductForm();
	void CreateNewProductForm();
	MedicinesProduct* ChangeCurrentFieldById(int Id);

	void CheckProductString(std::string str);
	void CheckProductDate(std::string str);
	void CheckProductInt(std::string str);
	std::string CreateNewDate();
	std::string CreateNewString();
	std::string CreateNewInt();

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

	~MedicinesMenu() {}
private:
	TablesRepository* repository;
	int currentId;
	std::vector<MedicinesProduct*>* products;
	int currentProductFieldId = 1;
	TableMenuCommands tState;
	ProductMenuCommands pState;
};
#endif _MED_MENU_