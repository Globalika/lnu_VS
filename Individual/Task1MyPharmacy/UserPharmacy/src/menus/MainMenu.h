#pragma once
#ifndef _MAIN_MENU_
#define _MAIN_MENU_
#include "MyPharmacy.h"
//#include "BaseMenu.h"
#include "MedicinesMenu.h"
#include "CosmeticsMenu.h"
class MainMenu
{
public:
	MainMenu()
	{
		m = new MedicinesMenu;
		c = new CosmeticsMenu;
	}
	void ShowMainMenu();
	void PrintPharmacyWellcome();
	void PrintPharmacyGetWellSoon();
	void PrintMenuForm();
	~MainMenu()
	{
		delete m;
		delete c;
	}

	enum MainMenuCommands {
		Quit,
		ShowMedicinesTable,
		ShowCosmeticsTable,
		MainMenuWaiting,
	};
	void SetState(MainMenuCommands state)
	{
		this->mState = state;
	}
private:
	MainMenuCommands mState;
	MedicinesMenu* m;
	CosmeticsMenu* c;

};
#endif _MAIN_MENU_