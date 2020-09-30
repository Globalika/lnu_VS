#pragma once
#ifndef _TABLE_MENU_
#define _TABLE_MENU_
#include "BaseMenu.h"
#include "ProductMenu.h"
class TableMenu : public Menu
{
public:
	TableMenu();
	void ShowTableMenu(int tableTypeNumber);

	void PrintTable(int tableTypeNumber);
	void PrintTableForm(int tableTypeNumber);
	void PrintSortTable(int tableTypeNumber);//
	void UpdateDataForTableMenu(int tableTypeNumber);
	void MoveCursorByProductId(int n);
	~TableMenu();

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
private:
	int currentId;
	std::vector<Product*>* products;
	TableMenuCommands tState;
};
#endif _TABLE_MENU_