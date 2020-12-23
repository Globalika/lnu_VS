#include "list.h"
#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
#include "stack.h"

bool predicateReplaceIf(Figure* f)
{
	if (f->GetTheAreaOfTheFigure() == PI*2*2)
	{
		return true;
	}
	return false;
}


bool predicateSort(Figure* a, Figure* b)
{
	if (a->GetTheAreaOfTheFigure() > b->GetTheAreaOfTheFigure())
	{
		return true;
	}
	return false;
}


int main()
{
	vector<Figure*> V;
	V.push_back(new Square(2));
	V.push_back(new Square(4));
	V.push_back(new Triangle(2, 6, 5));
	V.push_back(new Triangle(3, 5, 4));
	V.push_back(new Circle(1));
	V.push_back(new Circle(2));

	for (auto it : V)
	{
		it->PrintFigureInfo();
	}
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;

	std::replace_if(V.begin(), V.end(), predicateReplaceIf, new Circle(1));


	for (auto it : V)
	{
		it->PrintFigureInfo();
	}

	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	std::sort(V.begin(), V.end(), predicateSort);

	for (auto it : V)
	{
		it->PrintFigureInfo();
	}
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;

	////////////////////////////////

	Stack<int> stack;
	int k;
	int amount;
	for (int i = 0; i < 5; i++)
	{
		cout << "input element  " << endl;
		cin >> k;
		stack.push(k);
	}

	amount = stack.GetCount();
	for (int i = 0; i < amount; i++)
	{
		k = stack.pop();
		cout << "element  " << i << " = " << k << endl;
	}

	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	Stack<char> stack2;
	string s = "ryjhtyjr";
	for (int i = 0; i < s.length(); i++)
	{
		stack2.push(s[i]);
	}
	amount = stack2.GetCount();
	for (int i = 0; i < amount; i++)
	{
		k = stack2.pop();
		cout << "element  " << i << " = " << s[i] << endl;
	}

	return 0;


}