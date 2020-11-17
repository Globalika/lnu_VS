#pragma once
#ifndef _COS_MENU_
#define _COS_MENU_
#include "BaseMenu.h"
//template <typename CosmeticsTable, typename CosmeticsProduct>
class CosmeticsMenu : public  BaseMenu <CosmeticsTable, CosmeticsProduct>
{
public:
	CosmeticsMenu() /*: BaseMenu() {}*/
	{
		this->repository = new TablesRepository;
	}


	void ShowTableMenu();
	void PrintTable();
	void PrintTableForm();
	void PrintSortTable();
	void UpdateDataForTableMenu();
	void MoveCursorByProductId(int n);

	enum TableMenuCommands {
		TableMenuBack,
		Up,
		Down,
		SelectCurrentProduct,
		SortTableById,
		OrderCurrentProduct,
		TableOpenCard,
		TableMenuWaiting,
	};
	void SetState(TableMenuCommands state)
	{
		this->tState = state;
	}


	void OrderProduct();
	void OpenCard();

	CartProduct& GetCurrentProductAmount(int amount);
	void ReturnProductAmount(CartProduct& p);


	void ShowProductMenu(int Id);
	void PrintProduct();
	void PrintProductForm();
	void CreateNewProductForm();
	CosmeticsProduct* ChangeCurrentFieldById(int Id);

	void CheckProductString(std::string str);
	void CheckProductDate(std::string str);
	void CheckProductInt(std::string str);
	std::string CreateNewDate();
	std::string CreateNewString();
	std::string CreateNewInt();

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

	~CosmeticsMenu() {}
private:
	TablesRepository* repository;
	int currentId;
	std::vector<CosmeticsProduct*>* products;
	int currentProductFieldId = 1;
	TableMenuCommands tState;
	ProductMenuCommands pState;
	std::vector<CartProduct*>* cart;

};
#endif _COS_MENU_