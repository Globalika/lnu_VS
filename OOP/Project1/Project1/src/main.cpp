#include <string>
#include <vector>

class Product
{
public:
	//virtual Product& operator=(const Product& other);
	int id;
	std::string name;
	/*std::string expirationDate;
	std::string storageTemperature;
	int amount;*/
};
class MedicinesProduct : public virtual Product
{
public:
	MedicinesProduct& operator=(const MedicinesProduct& other);
	static std::vector<std::string> GetvectorStringFromProduct(MedicinesProduct& product);
	static MedicinesProduct GetProductByStringvector(std::vector<std::string>& stringvector);

	std::string expirationDate;
	std::string storageTemperature;
	int amount;
};
class Database
{
public:
	std::vector<std::vector<std::string>>* GetTableContent(std::string tableName);
	std::string CreateTableFilePath(std::string tableName);
	void UpdateTableContent(std::vector<std::vector<std::string>>& content, std::string tableName);
private:

};
class Table
{
public:
	virtual bool IsProductExist(Product& product) = 0;
	virtual void Create(Product& product) = 0;
	virtual void Update(Product& product) = 0;
	virtual Product* GetById(int id) = 0;
	virtual std::vector<Product> GetAll() = 0;
	virtual void Delete(int id) = 0;
	virtual void Save() = 0;
	virtual std::vector<std::vector<std::string>>* GetContentFromProductsvector(std::vector<Product>& products) = 0;
	virtual Database* GetDatabase() = 0;

	//const static std::string tableName;
protected:
	std::vector<Product>* products;
	Database* database;
};

class MedicinesTable : public Table
{
public:
	MedicinesTable();
	bool IsProductExist(Product& product) override;
	void Create(Product& product) override;
	void Update(Product& product) override;
	Product* GetById(int id) override;
	std::vector<Product> GetAll() override;
	void Delete(int id) override;
	void Save() override;
	std::vector<std::vector<std::string>>* GetContentFromProductsvector(std::vector<Product>& products) override;

	const static std::string medicinesTableName;
	Database* GetDatabase() override;
	~MedicinesTable();
	//private:
	//	std::vector<MedicinesProduct>* products;
	//	Database* database;
};

#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>
MedicinesTable::MedicinesTable()
{
	database = new Database();
	std::vector<std::vector<std::string>> stringvector = *database->GetTableContent(medicinesTableName);

	products = new std::vector<Product>;

	for (auto it : stringvector)
	{
		auto var = MedicinesProduct::GetProductByStringvector(it);
		Create(var);
	}
}

bool MedicinesTable::IsProductExist(Product& product)
{
	auto it = std::find_if(products->begin(), products->end(), [product](const Product& p)
		{
			return p.id == product.id;
		});
	return it == products->end();
}

void MedicinesTable::Create(Product& product)
{
	products->push_back(product);
	Save();
}

void MedicinesTable::Update(Product& product)
{
	std::replace_if(products->begin(), products->end(), [product](const Product& p)
		{
			return (p.id == product.id);
		}, product);
	Save();
}

std::vector<Product> MedicinesTable::GetAll()
{
	return *products;
}

Product* MedicinesTable::GetById(int id)
{
	auto result = std::find_if(products->begin(), products->end(), [id](const Product& product)
		{
			return product.id == id;
		});
	return &*result;
}

void MedicinesTable::Delete(int id)
{
	auto result = std::remove_if(products->begin(), products->end(), [id](const Product& product)
		{
			return product.id == id;
		});
	products->erase(result, products->end());
	Save();
}

void MedicinesTable::Save()
{
	database->UpdateTableContent(*GetContentFromProductsvector(*products), medicinesTableName);
}



std::vector<std::vector<std::string>>* MedicinesTable::GetContentFromProductsvector(std::vector<Product>& products)
{
	std::vector<std::vector<std::string>>* vector = new std::vector<std::vector<std::string>>;
	std::vector<std::string> str;
	/*for (auto it : products)
	{

		str = MedicinesProduct::GetvectorStringFromProduct(dynamic_cast<MedicinesProduct>(it));
		vector->push_back(str);
		str.clear();
	}*/

	return vector;
}

Database* MedicinesTable::GetDatabase()
{
	return this->database;
}

MedicinesTable::~MedicinesTable()
{
	delete database;
}

const std::string MedicinesTable::medicinesTableName = "medicinesTable";


#include <sstream>

MedicinesProduct& MedicinesProduct::operator=(const MedicinesProduct& other)
{
	this->id = other.id;
	this->expirationDate = other.expirationDate;
	this->name = other.name;
	this->storageTemperature = other.storageTemperature;
	this->amount = other.amount;
	return *this;
}

std::vector<std::string> MedicinesProduct::GetvectorStringFromProduct(MedicinesProduct& product)
{

	std::vector<std::string> vector;
	vector.push_back(std::to_string(product.id));
	vector.push_back(product.expirationDate);
	vector.push_back(product.name);
	vector.push_back(product.storageTemperature);
	vector.push_back(std::to_string(product.amount));
	return vector;
}

MedicinesProduct MedicinesProduct::GetProductByStringvector(std::vector<std::string>& content)
{
	MedicinesProduct product;
	std::stringstream ss;
	ss << content.at(0);
	ss >> product.id;
	ss.clear();
	product.expirationDate = content.at(1);
	product.name = content.at(2);
	product.storageTemperature = content.at(3);
	ss << content.at(4);
	ss >> product.amount;
	ss.clear();
	return product;
}

#include <iostream>
#include <fstream>
#include <sstream>
//
std::ostream& operator<<(std::ostream& os, std::vector<std::string>& productVec)
{
	os << productVec.at(0) << ',' << productVec.at(1) << ','
		<< productVec.at(2) << ',' << productVec.at(3) << ',' << productVec.at(4);
	return os;
}
//
std::string Database::CreateTableFilePath(std::string tableName)
{
	return "tablefiles/" + tableName + ".txt";
}


void Database::UpdateTableContent(std::vector<std::vector<std::string>>& content, std::string tableName)
{

	std::string filePath = CreateTableFilePath(tableName);
	std::ofstream fout;
	fout.open(filePath);

	if (!fout.is_open())
	{
		std::cout << "open file error" << std::endl;
	}
	else
	{
		int i = 0;
		for (; i < content.size() - 1; i++)
		{
			fout << content.at(i) << '\n';
		}
		fout << content.at(i);
	}
	fout.close();

}

std::vector<std::vector<std::string>>* Database::GetTableContent(std::string tableName)
{
	std::string filePath = Database::CreateTableFilePath(tableName);
	std::vector<std::vector<std::string>>* content = new std::vector<std::vector<std::string>>();
	std::vector<std::string> stringOfContent;//
	std::ifstream fin;
	fin.open(filePath);

	/*try
	{
		fin.open(filePath);
	}
	catch (const std::ifstream::failure& ex)
	{
		std::cout << ex.what() << std::endl;
		std::cout << ex.code() << std::endl;
		std::cout << "cannot open file" << std::endl;
	}*/

	if (!fin.is_open())
	{
		std::cout << "open file error" << std::endl;
	}
	else
	{
		std::string str, token;
		while (!fin.eof())
		{
			str = "";
			while (str == "")
			{
				getline(fin, str);
			}
			std::istringstream ss(str);
			while (std::getline(ss, token, ','))
			{
				stringOfContent.push_back(token);
			}
			content->push_back(stringOfContent);
			stringOfContent.clear();
		}
	}
	fin.close();

	return content;
}

#include <iostream>

struct V {
	virtual void f() {};  // must be polymorphic to use runtime-checked dynamic_cast
};
struct A : virtual V {};
struct B : virtual V {
	B(V* v, A* a) {
		// casts during construction (see the call in the constructor of D below)
		dynamic_cast<B*>(v); // well-defined: v of type V*, V base of B, results in B*
		dynamic_cast<B*>(a); // undefined behavior: a has type A*, A not a base of B
	}
};
struct D : A, B {
	D() : B(static_cast<A*>(this), this) { }
};

struct Base {
	virtual ~Base() {}
};

struct Derived : Base {
	virtual void name() {}
};

#define BIT(x) (1 << x)
int main()
{
	int a = 8 >> 1;
	std::cout << a << std::endl;

	return 0;
}