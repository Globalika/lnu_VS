#pragma once
#ifndef _TABLES_REPOSITORY_
#define _TABLES_REPOSITORY_
#include "MedicinesTable.h"

class TablesRepository
{
public:
	TablesRepository();
	MedicinesTable* GetMedicinesTable();
private:
	MedicinesTable* medicinesTable;
};

#endif _TABLES_REPOSITORY_