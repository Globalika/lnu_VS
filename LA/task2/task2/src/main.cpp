#include <iostream>
#include <string>
#include "SquareRootMethod.h"
using namespace std;

int main()
{

	std::string
		m2Path = "src/matrixFolder/2x2matrix.txt",
		m3Path = "src/matrixFolder/3x3matrix.txt";

	SquareRootMethod(m3Path);


	return 0;
}