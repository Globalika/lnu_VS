#pragma once
#ifndef _TABLES_REPOSITORY_
#define _TABLES_REPOSITORY_
//#include "tables/BaseTable.h"
#include "tables/MedicinesTable.h"
#include "tables/CosmeticsTable.h"

class TablesRepository
{
public:
	TablesRepository();
	MedicinesTable* GetMedicinesTable();
	CosmeticsTable* GetCosmeticsTable();
private:
	MedicinesTable* medicinesTable;
	CosmeticsTable* cosmeticsTable;
};

#endif _TABLES_REPOSITORY_