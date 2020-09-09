#pragma once
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




//#endif _DATABASE_