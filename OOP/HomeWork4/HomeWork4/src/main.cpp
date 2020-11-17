#include <iostream>
#include "birds.h"
#include "Figures.h"
using namespace std;

int main()
{
	Bird** array = new Bird * [4];
	array[0] = new Eagle();
	array[1] = new Swallow();
	array[2] = new Penguin();
	array[3] = new Chicken();

	for (int i = 0; i < 4; i++)
	{
		cout << array[i]->GetType() << endl;
		if (array[i]->LayEggs())
		{
			cout << "bird lay eggs" << endl;
		}
		else 
		{
			cout << "bird dont lay eggs" << endl;
		}
		cout << "bird feather color: " << array[i]->FeatherColor() << endl;
		cout << "bird can: "; array[i]->fly(); cout << endl << endl;
	}
	//////////////////////////

	//////////////////////////

	Figure** f = new Figure*[5];
	f[0] = new Rectangle(4,6);
	f[1] = new Rectangle(42,66);
	f[2] = new Circle(4);
	f[3] = new Circle(43);
	f[4] = new Circle(1);
	for (int i = 0; i < 5; i++)
	{
		f[i]->PrintFigureInfo();
	}

	
	return 0;
}