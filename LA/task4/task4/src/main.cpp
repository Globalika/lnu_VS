#include <iostream>
#include <string>
#include "ZeidelMethod.h"


int main()
{
	std::string
		path1 = "src/files/4x4matrix1.txt",
		path2 = "src/files/4x4matrix2.txt",
		path3 = "src/files/matrix.txt";
	//
	ZeidelAlgorithm(path1);
	return 0;
}