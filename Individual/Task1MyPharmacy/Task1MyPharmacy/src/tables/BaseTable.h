#pragma once
#ifndef _TABLE_
#define _TABLE_
#include <string>
#include <vector>
#include <algorithm>
#include "..\Database.h"
template <class T>
class Table
{
public:
	virtual bool IsProductExist(T& product);
	virtual void Create(T& product);
	virtual void Update(T& product);
	virtual T* GetById(int id);
	virtual std::vector<T*>* GetAll();
	virtual void Delete(int id);
	virtual void Save() {}
	virtual Database* GetDatabase();
	virtual ~Table(){};
protected:
	std::vector<std::vector<std::string>>* GetContentFromProductsVector(std::vector<T*>& products);
	std::vector<T*>* products;
	Database* database;
};
#endif _TABLE_




template<class T>
bool Table<T>::IsProductExist(T& product)
{
	auto it = std::find_if(products->begin(), products->end(), [product](const T* p)
		{
			return p->id == product.id;
		});
	if (it == products->end())
	{
		return false;
	}
	else
	{
		return true;
	}
}

template<class T>
void Table<T>::Create(T& product)
{
	T& mp = dynamic_cast<T&>(product);
	products->push_back(&mp);
	Save();
}

template<class T>
void Table<T>::Update(T& product)
{
	T* pr = dynamic_cast<T*>(&product);
	std::replace_if(products->begin(), products->end(), [pr](const T* p)
		{
			return (p->id == pr->id);
		}, pr);
	Save();
}

template<class T>
T* Table<T>::GetById(int id)
{
	auto result = std::find_if(products->begin(), products->end(), [id](const T* product)
		{
			return product->id == id;
		});
	return *result;
}

template<class T>
std::vector<T*>* Table<T>::GetAll()
{
	std::vector<T*>* v = new std::vector<T*>();
	for (auto it : *products)
	{
		T* p = it;
		v->push_back(p);
	}
	return v;
}

template<class T>
void Table<T>::Delete(int id)
{
	auto result = std::remove_if(products->begin(), products->end(), [id](const T* product)
		{
			return product->id == id;
		});
	products->erase(result, products->end());
	Save();
}

template<class T>
Database* Table<T>::GetDatabase()
{
	return this->database;
}

template<class T>
std::vector<std::vector<std::string>>* Table<T>::GetContentFromProductsVector(std::vector<T*>& products)
{
	std::vector<std::vector<std::string>>* vector = new std::vector<std::vector<std::string>>;
	std::vector<std::string> str;
	for (auto it : products)
	{
		T& cp = dynamic_cast<T&>(*it);
		str = T::GetvectorStringFromProduct(cp);
		vector->push_back(str);
		str.clear();
	}

	return vector;
}
