#include "TablesRepository.h"

TablesRepository::TablesRepository()
{
	this->medicinesTable = nullptr;
}

MedicinesTable* TablesRepository::GetMedicinesTable() {
	if (this->medicinesTable == nullptr) {
		
		medicinesTable = new MedicinesTable();
	}
	return medicinesTable;
}