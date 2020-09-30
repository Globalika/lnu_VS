#pragma once
#ifndef _PRODUCT_MENU_
#define _PRODUCT_MENU_
#include "BaseMenu.h"
#include "TableMenu.h"
class ProductMenu : public Menu
{
public:
	ProductMenu();
	void ShowProductMenu(int tableTypeNumber, int Id);

	void PrintProduct(int tableTypeNumber);
	void PrintProductForm(int tableTypeNumber);

	void CheckProductString(std::string str);
	void CheckProductDate(std::string str);
	void CheckProductInt(std::string str);

	std::string CreateNewDate(int tableTypeNumber);
	std::string CreateNewString(int tableTypeNumber);
	std::string CreateNewInt(int tableTypeNumber);
	~ProductMenu();
	Product* ChangeCurrentFieldById(int tableTypeNumber,int Id);
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
private:
	int currentId;
	ProductMenuCommands pState;
	int currentProductFieldId = 1;
	std::vector<Product*>* products;
};
#endif _PRODUCT_MENU_