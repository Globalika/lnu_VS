#include "TablesRepository.h"
//#include <algorithm>
//#include <sstream>

TablesRepository::TablesRepository()
{
	medicinesTable = nullptr;
	cosmeticsTable = nullptr;
	cartTable = nullptr;
}

MedicinesTable* TablesRepository::GetMedicinesTable() {
	if (medicinesTable == nullptr) {
		
		medicinesTable = new MedicinesTable();
	}
	return medicinesTable;
}

CosmeticsTable* TablesRepository::GetCosmeticsTable()
{
	if (cosmeticsTable == nullptr) {

		cosmeticsTable = new CosmeticsTable();
	}
	return cosmeticsTable;
}

CartTable* TablesRepository::GetCartTable()
{
	if (cartTable == nullptr) {

		cartTable = new CartTable();
	}
	return cartTable;
}
