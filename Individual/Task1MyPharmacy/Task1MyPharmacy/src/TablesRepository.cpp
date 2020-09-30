#include "TablesRepository.h"

TablesRepository::TablesRepository()
{
	medicinesTable = nullptr;
	cosmeticsTable = nullptr;
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
