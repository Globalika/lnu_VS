#pragma once
#ifndef _TABLES_REPOSITORY_
#define _TABLES_REPOSITORY_
//#include "BaseTable.h"
#include "MedicinesTable.h"
//#ifdef _DATABASE_
//#define _DATABASE_

class TablesRepository
{
public:
	TablesRepository();
	MedicinesTable* GetMedicinesTable();
private:
	MedicinesTable* medicinesTable;
};




#endif _TABLES_REPOSITORY_