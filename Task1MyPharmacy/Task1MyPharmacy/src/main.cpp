#include <iostream>

#include "database.h"
#include "Product.h"
#include "basetable.h"
#include "MedicinesProduct.h"
#include "MedicinesTable.h"
#include "TablesRepository.h"

using namespace std;

int main()
{
	TablesRepository* context = new TablesRepository;

	context->GetMedicinesTable();
	context->GetMedicinesTable()->Delete(1234);
	context->GetMedicinesTable()->GetDatabase()->UpdateTableContent(*context->GetMedicinesTable()->GetContentFromProductsvector(*context->GetMedicinesTable()->products),"medicinesTable");


	system("pause");
	return 0;
}