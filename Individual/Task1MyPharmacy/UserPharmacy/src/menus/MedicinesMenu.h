#pragma once
#ifndef _MED_MENU_
#define _MED_MENU_
#include "BaseMenu.h"
class MedicinesMenu : public BaseMenu<MedicinesTable, MedicinesProduct>
{
public:
	MedicinesMenu()
	{
		this->repository = new TablesRepository;
	}

	void ShowTableMenu();
	void PrintTable();
	void PrintTableForm();
	void PrintSortTable();

	//////////////////////
	void OrderProduct();

	void OpenCard();

	CartProduct& TakeAmountFromCurrentProduct(int amount);

	void ReturnProductAmount(int id, std::string name, int amount);
	/////////////////////

	void ShowProductMenu(int Id);
	void PrintProduct();
	void PrintProductForm();
	void CreateNewProductForm();
	MedicinesProduct* ChangeCurrentFieldById(int Id);

	~MedicinesMenu() {}
};
#endif _MED_MENU_