#pragma once
#ifndef _TABLES_REPOSITORY_
#define _TABLES_REPOSITORY_
#include "tables/CosmeticsTable.h"
#include "tables/MedicinesTable.h"
#include "tables/CartTable.h"
#include <string>

class TablesRepository
{
public:
	TablesRepository();
	MedicinesTable* GetMedicinesTable();
	CosmeticsTable* GetCosmeticsTable();
	CartTable* GetCartTable();
	~TablesRepository() {}
private:
	MedicinesTable* medicinesTable;
	CosmeticsTable* cosmeticsTable;
	CartTable* cartTable;
};

#endif _TABLES_REPOSITORY_