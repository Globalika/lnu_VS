#pragma once
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

	void PrintTableTemplate();
	void PrintMenuTemplate();


	void MoveProbuctByIdUp();
	void MoveProbuctByIdDown();


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
		DeletCurrentProduct,//
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
	int currentId;
	std::vector<MedicinesProduct> products;
	MainMenuCommands mState;
	TableMenuCommands tState;
	ProductMenuCommands pState;
	TablesRepository* repository;
};