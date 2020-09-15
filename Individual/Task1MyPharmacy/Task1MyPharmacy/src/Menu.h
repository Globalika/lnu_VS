#pragma once
#ifndef _MENU_
#define _MENU_
#include "TablesRepository.h"

class Menu {
public:
	Menu();
	void ShowMainMenu();
	void ShowTableMenu();
	void ShowProductMenu();

	void PrintTable();
	void PrintPharmacyWellcome();
	void PrintPharmacyGetWellSoon();
	void PrintProduct();

	void PrintTableForm();
	void PrintMenuForm();
	void PrintProductForm();

	void MoveProbuctById(int n);

	bool CatchProductName(std::string str);
	bool CatchProductDate(std::string str);
	bool CatchProductAmountOrTempreture(std::string str);

	MedicinesProduct* ChangeCurrentFieldById(int Id);

	enum MainMenuCommands {
		Quit,
		ChooseTable,
		MainMenuWaiting,
	};
	enum TableMenuCommands {
		TableMenuBack,
		TableUp,
		TableDown,
		SelectCurrentProduct,
		SortTableById,
		CreateNewProduct,//
		DeleteCurrentProduct,//
		TableMenuWaiting,
	};
	enum ProductMenuCommands {
		ProductMenuBack,
		ProductFieldUp,
		ProductFieldDown,
		ChangeCurrentField,
		ProductMenuWaiting,
	};
	void SetState(MainMenuCommands state)
	{
		this->mState = state;
	}
	void SetState(TableMenuCommands state)
	{
		this->tState = state;
	}
	void SetState(ProductMenuCommands state)
	{
		this->pState = state;
	}
private:
	int currentProductFieldId = 1;
	int currentId;
	std::vector<MedicinesProduct> products;
	MainMenuCommands mState;
	TableMenuCommands tState;
	ProductMenuCommands pState;
	TablesRepository* repository;
};
#endif _MENU_