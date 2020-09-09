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


	enum Commands {
		Waiting,
		Quit,
		ChooseTable,
		Back,
		ChangeProductInfo,
		Up,
		Down,
		SelectProduct,
	};
	Commands GetState()
	{
		return state;
	}
	void SetState(Commands state)
	{
		this->state = state;
	}

private:
	Commands state;
	TablesRepository* repository;
};