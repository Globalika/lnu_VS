#pragma once
#ifndef _MAIN_MENU_
#define _MAIN_MENU_
#include "BaseMenu.h"
#include "TableMenu.h"
class MainMenu : public Menu
{
public:
	MainMenu() {}
	void ShowMainMenu();
	void PrintPharmacyWellcome();
	void PrintPharmacyGetWellSoon();
	void PrintMenuForm();
	~MainMenu() {}

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
	TableMenu tableMenu;
	MainMenuCommands mState;
};
#endif _MAIN_MENU_