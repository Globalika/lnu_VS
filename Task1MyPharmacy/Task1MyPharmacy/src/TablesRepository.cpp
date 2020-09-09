#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

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