#pragma once
#ifndef _MEDICINES_TABLE_
#define _MEDICINES_TABLE_
#include <string>
#include <vector>
#include "BaseTable.h"
#include "..\products/MedicinesProduct.h"

class MedicinesTable : public Table <MedicinesProduct>
{
public:
	MedicinesTable();
	void Save() override;
	~MedicinesTable();
	const static std::string medicinesTableName;
private:

};
#endif _MEDICINES_TABLE_