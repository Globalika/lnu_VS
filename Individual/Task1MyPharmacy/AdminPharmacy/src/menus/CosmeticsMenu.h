#pragma once
#ifndef _COS_MENU_
#define _COS_MENU_
#include "BaseMenu.h"
class CosmeticsMenu : public  BaseMenu <CosmeticsTable, CosmeticsProduct>
{
public:
	CosmeticsMenu()
	{
		this->repository = new TablesRepository;
	}


	void ShowTableMenu();
	void PrintTable();
	void PrintTableForm();
	void PrintSortTable();

	void ShowProductMenu(int Id);
	void PrintProduct();
	void PrintProductForm();
	void CreateNewProductForm();
	CosmeticsProduct* ChangeCurrentFieldById(int Id);

	~CosmeticsMenu() {}
};
#endif _COS_MENU_