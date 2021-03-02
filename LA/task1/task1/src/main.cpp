#include <string>
#include "GaussMethod.h"

int main()
{
	std::string 
		m2Path = "src/matrixFolder/matrix2x2Det0.txt",
		m3Path = "src/matrixFolder/matrix3x3FromNotebook.txt",
		m4Path = "src/matrixFolder/matrix4x4.txt",
		m5Path = "src/matrixFolder/matrix5x5Det0.txt";

	FindInverseMatrix(m2Path);

	return 0;
}