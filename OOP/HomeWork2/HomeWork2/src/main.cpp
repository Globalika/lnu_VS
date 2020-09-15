#include "Person.h"
#include "PersonList.h"
#include <iostream>

using namespace std;

void f(Person p2)
{
	p2.WriteToConsole();
} //p2.~Person() => delete[] middleName, because p2 local variable => copy error


void f(Person& p2)
{

}// no p2.~Person() !! becuase p2 is a reference on a 'p in main' => no copy error

void f(char* p2)
{

}//no delete[] p2 => no error

//before correct copy ctor
//p.middleName <> p2.middleName - 2 diff variables
//*(p.middleName) == *(p2.middleName)

//after copy ctor
//p.middleName <> p2.middleName - 2 diff variables
//*(p.middleName) <> *(p2.middleName) - 2 diff arrays in memory

int main()
{
	Person p("Oleg", "Stud", "Volodym", 23);
	//f(p); // copy problem

	Person p2 = p; //copy problem
	//Person p2 = p ~ Person p2(p);

	/*p2 <-p
	p2.Person(p); other = p; this = p2.*/


	Person p3("Andriy", "Stud2", "olegovych", 20);
	p3 = p; //assignment operator
	p = p;

	Person p4("Andriy", "Stud2", "olegovych", 20);

	PersonList pl(10);
	pl.Add(p);
	pl.Add(p4);
	pl.Write();

	PersonList pl2 = pl;
	//HW:
	//test how it works without created ctor
	//PersonList pl2 = pl; // copy ctor!!
	//pl3 = pl; //assignment operator

	//* [*], pl.Add(p) => [p], pl.Add(p) => 1. allocate memory [p], [* *]; 2. copy data [p], [p *]; 3. delete memory: null, [p, *] => [p p * *]
	//* add 1
	system("pause");
}

//assignment problem
//1. main -> p -> middleName -> char[]
//2. p3 = p: p3.firstName = p.firstName, ... p3.middleName = p.middleName = > error!
//	p3.middleName -> p.middleName
//3. p3.~Person() => delete [] p3.middleName (delete p.middleName)
//4. p.~Person () => delete [] p.middleName => error !!!



//copy problem
//1. 
//main -> p -> middleName -> char[]
//f -> copy p into p2 -> p2 -> middleName ->main.p.middleName
//
//2. delete stack of f => p2.~Person() => p2 -> middleName -> null
//
//3. main.p.middleName -> null
//
//4. main -> p.~Person() => error!!!
