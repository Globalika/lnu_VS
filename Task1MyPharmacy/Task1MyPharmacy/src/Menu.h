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
	//void PrintProductInfo();


	enum MainMenuCommands {
		Quit,
		ChooseTable,
		MainMenuWaiting,
	};
	enum TableMenuCommands {
		TableMenuBack,
		Up,
		Down,
		SelectProduct,
		TableMenuWaiting,
	};
	enum ProductMenuCommands {
		ProductMenuBack,
		ChangeProductInfo,
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
	MainMenuCommands mState;
	TableMenuCommands tState;
	ProductMenuCommands pState;
	TablesRepository* repository;
};