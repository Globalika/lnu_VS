#include "SquareRootMethod.h"
#include<iostream>
#include<math.h>
#include <fstream>
#include <string>
#include <tuple>

#define epsilonP 1e+6
#define epsilonN 1e-6

std::tuple<float**, int, float*> GetInfoFromFile(std::string filePath)
{
	std::ifstream fin(filePath);
	if (!fin.is_open())
	{
		throw;
	}
	else
	{
		int dimension;
		fin >> dimension;
		float** matrix = new float* [dimension];
		float* vectorB = new float[dimension];

		for (int i = 0; i < dimension; i++)
		{
			matrix[i] = new float[dimension];
		}
		float temp = 0;
		while (!fin.eof())
		{

			for (int i = 0; i < dimension; i++)
			{
				for (int j = 0; j < dimension; j++)
				{
					fin >> temp;
					matrix[i][j] = temp;
				}
			}

			for (int k = 0; k < dimension; k++)
			{
				fin >> temp;
				vectorB[k] = temp;
			}

		}
		fin.close();
		return std::make_tuple(matrix, dimension, vectorB);
	}
}
bool isNearlyEqualZero(float number)
{
	bool temp = std::abs(number) <= epsilonN;
	temp = std::abs(number) >= epsilonP;
	return temp;
}
float FindDeterminantUTU(float** matrix, int dimension)
{
	float determinant = 1;
	for (size_t i = 0; i < dimension; i++)
	{
		determinant *= pow(matrix[i][i], 2);
	}
	return determinant;
}
void ClearMemory(float**& matrix, int dimension) {
	for (int i = 0; i < dimension; i++) {
		delete[] matrix[i];
	}
	delete[] matrix;
	return;
}
bool CheckIfMatrixSymmetric(float** matrix, int dimension)
{
	for (int i = 0; i < dimension; i++)
	{
		for (int j = 0; j < dimension; j++)
		{
			if (matrix[i][j] != matrix[j][i])
				return false;
		}
	}
	return true;
}
float FindDeterminantRecursive(float**& matrix, int dimension) {
	if (dimension == 1)
	{
		return matrix[0][0];
	}
	else if (dimension == 2)
	{
		return matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];
	}
	else
	{
		float determinant = 0;
		for (int k = 0; k < dimension; k++)
		{
			float** minor = new float* [dimension - 1];
			for (int i = 0; i < dimension - 1; i++)
			{
				minor[i] = new float[dimension - 1];
			}

			for (int i = 1; i < dimension; i++)
			{
				int temp = 0;
				for (int j = 0; j < dimension; j++)
				{
					if (j == k)
					{
						continue;
					}
					minor[i - 1][temp] = matrix[i][j];
					temp++;
				}
			}
			determinant += pow(-1, k + 2) * matrix[0][k] * FindDeterminantRecursive(minor, dimension - 1);
			ClearMemory(minor, dimension - 1);
		}
		return determinant;
	}
}
bool CheckIfMatrixdDegenerateRecursive(float** matrix, int dimension)
{
	return FindDeterminantRecursive(matrix,dimension) == 0;
}
bool CheckIfMatrixdDegenerateUTU(float** matrix, int dimension)
{
	return FindDeterminantUTU(matrix, dimension) == 0;
}
float SumSquare(float** matrixU, int i)
{
	float sum = 0;
	for (int k = 0; k <= i - 1; k++)
	{
		sum += pow(matrixU[k][i], 2);
	}
	return sum;
	/*return []() 
	{

	};*/
}
float SumMultiply(float** matrix, int i, int j)
{
	float sum = 0;
	for (int k = 0; k <= i - 1; k++)
	{
		sum += matrix[k][i] * matrix[k][j];
	}
	return sum;
}
float SumY(float** matrix, int i, float* vectorY)
{
	float sum = 0;
	for (int k = 0; k <= i - 1; k++)
	{
		if (isNearlyEqualZero(matrix[k][i] * vectorY[k]))
		{
			sum += 0;
		}
		else
		{
			sum += matrix[k][i] * vectorY[k];
		}
	}
	return sum;
}
float SumX(float** matrix, int i, int dimension, float* vectorX)
{
	float sum = 0;
	for (int k = i + 1; k < dimension; k++)
	{
		if (isNearlyEqualZero(matrix[i][k] * vectorX[k]))
		{
			sum += 0;
		}
		else
		{
			sum += matrix[i][k] * vectorX[k];
		}
	}
	return sum;
}
std::tuple<float**, float**, bool> GetUTU(float** matrixA, int dimension)
{
	bool state = false;
	//U
	float** matrixU = new float* [dimension];
	for (int i = 0; i < dimension; i++)
	{
		matrixU[i] = new float[dimension];
	}
	for (int i = 0; i < dimension; i++)
	{
		for (int j = 0; j < dimension; j++)
		{
			matrixU[i][j] == 0;
		}
	}
	//
	for (int i = 0; i < dimension; i++)
	{
		if ((matrixA[i][i] - SumSquare(matrixU, i) < 0) || isNearlyEqualZero(matrixU[i][i]))
			state = true;
		matrixU[i][i] = sqrt(matrixA[i][i] - SumSquare(matrixU, i));
		for (int j = i; j < dimension; j++)
		{
			matrixU[i][j] = (matrixA[i][j] - SumMultiply(matrixU, i, j)) / matrixU[i][i];
		}
	}
	//U_T
	float** matrixU_T = new float* [dimension];
	for (int i = 0; i < dimension; i++)
	{
		matrixU_T[i] = new float[dimension];
	}
	for (int i = 0; i < dimension; i++)
	{
		for (int j = 0; j < dimension; j++)
		{
			matrixU_T[j][i] = matrixU[i][j];
		}
	}
	
	return std::make_tuple(matrixU, matrixU_T, state);
}
float* GetVectorY(float** matrixU_T, int dimension, float* vectorB)
{
	float* vectorY = new float[dimension];

	for (int i = 0; i < dimension; i++)
	{
		vectorY[i] = (1/ matrixU_T[i][i]) * (vectorB[i] - SumY(matrixU_T, i, vectorY));
	}
	return vectorY;
}
float* GetVectorX(float** matrixU, int dimension, float* vectorY)
{
	float* vectorX = new float[dimension];

	for (int i = dimension - 1; i >= 0; i--)
	{
		vectorX[i] = (1 / matrixU[i][i]) * (vectorY[i] - SumX(matrixU, i, dimension, vectorX));
	}
	return vectorX;
}
void PrintMatrix(float**& matrix, int dimension, std::string str)
{
	if (str != "")
	{
		std::cout << "\t\t" + str + "\t\t\n";
	}
	for (int i = 0; i < dimension; i++)
	{
		for (int j = 0; j < dimension; j++)
		{
			if (isNearlyEqualZero(matrix[i][j]))
			{
				std::cout << 0 << " ";
			}
			else
			{
				std::cout << matrix[i][j] << " ";
			}
		}
		std::cout << '\n';
	}
	return;
}
void PrintVector(float* vector, int dimension, std::string str)
{
	if (str != "")
	{
		std::cout << "\t\t" + str + "\t\t\n";
	}
	for (int i = 0; i < dimension; i++)
	{
		std::cout << vector[i] << " ";
	}
	std::cout << '\n';
	return;
}
float** MultiplyMatrix(float** matrix1, float** matrix2, int dimension)
{

	float** resultMatrix = new float* [dimension];
	for (int i = 0; i < dimension; i++)
	{
		resultMatrix[i] = new float[dimension];
	}
	for (int i = 0; i < dimension; i++)
	{
		for (int j = 0; j < dimension; j++)
		{
			resultMatrix[i][j] = 0;
		}
	}
	for (size_t i = 0; i < dimension; i++)
	{
		for (size_t j = 0; j < dimension; j++)
		{
			for (size_t k = 0; k < dimension; k++)
			{
				if (isNearlyEqualZero(matrix1[i][k] * matrix2[k][j]))
				{
					resultMatrix[i][j] += 0;
				}
				else
				{
					resultMatrix[i][j] += matrix1[i][k] * matrix2[k][j];
				}
			}
			
		}
	}
	return resultMatrix;
}
float* MultiplyMatrixOnVector(float** matrix, float* vector, int dimension)
{
	float* resultVector = new float[dimension];
	for (int i = 0; i < dimension; i++)
	{
		resultVector[i] = 0;
	}
	//
	for (size_t i = 0; i < dimension; i++)
	{
		for (size_t j = 0; j < dimension; j++)
		{
			if (isNearlyEqualZero(matrix[i][j] * vector[j]))
			{
				resultVector[i] += 0;
			}
			else
			{
				resultVector[i] += matrix[i][j] * vector[j];
			}
		}
	}
	//
	return resultVector;
}

void SquareRootMethod(std::string path)
{
	//print info
	auto info = GetInfoFromFile(path);
	float** matrixA = std::get<0>(info);
	int dimension = std::get<1>(info);
	float* vectorB = std::get<2>(info);
	PrintMatrix(matrixA, dimension, "matrix A :");
	PrintVector(vectorB, dimension, "vector B :");

	//check determinant
	std::cout << "Degenerate check (A):";
	if (CheckIfMatrixdDegenerateRecursive(matrixA, dimension) == true)
	{
		std::cout << "\nDeterminant = " << FindDeterminantRecursive(matrixA, dimension);
		std::cout << "\nMatrix is degenerate\n";
		return;
	}
	else
	{
		std::cout << "\nDeterminant = " << FindDeterminantRecursive(matrixA, dimension);
		std::cout << "\nMatrix is not degenerate\n";
	}

	//check symmetry
	std::cout << "\nSymmetry check :";
	if (CheckIfMatrixSymmetric(matrixA, dimension) == false)
	{
		std::cout << "\nMatrix is not Symmetric\n";
		return;
	}
	else
	{
		std::cout << "\nMatrix is Symmetric\n";
	}

	//UTU
	auto matrixies = GetUTU(matrixA, dimension);
	float** matrixU = std::get<0>(matrixies);
	float** matrixU_T = std::get<1>(matrixies);
	//check root
	std::cout << "Root from negative check (UTU):";
	if (std::get<2>(matrixies))
	{
		std::cout << "\nRoot from negative number error\n";
		return;
	}
	else
	{
		std::cout << "\nNo erors\n";
	}

	//print U and U_T
	PrintMatrix(matrixU, dimension, "matrix U :");
	PrintMatrix(matrixU_T, dimension, "matrix U_T :");
	
	//check determinant
	std::cout << "Degenerate check (UTU):";
	if (CheckIfMatrixdDegenerateUTU(matrixU, dimension) == true)
	{
		std::cout << "\nDeterminant = " << FindDeterminantUTU(matrixU, dimension);
		std::cout << "\nMatrix is degenerate\n";
		return;
	}
	else
	{
		std::cout << "\nDeterminant = " << FindDeterminantUTU(matrixU, dimension);
		std::cout << "\nMatrix is not degenerate\n";
	}

	//check UTU
	float** UTUMultiply = MultiplyMatrix(matrixU_T, matrixU, dimension);
	PrintMatrix(UTUMultiply, dimension, "U_T * U :");

	//U_T * y = b
	float* vectorY = GetVectorY(matrixU, dimension, vectorB);
	PrintVector(vectorY, dimension, "vector Y :");
	//check 
	float* vecBCheck = MultiplyMatrixOnVector(matrixU_T,vectorY, dimension);
	PrintVector(vecBCheck,dimension, "vector B check (U_T * y = b):");

	//U * x = y
	float* vectorX = GetVectorX(matrixU, dimension, vectorY);
	PrintVector(vectorX, dimension, "vector X :");
	//check
	float* vecYCheck = MultiplyMatrixOnVector(matrixU, vectorX, dimension);
	PrintVector(vecYCheck, dimension, "vector Y check (U * x = y):");

	//check A*x = b
	float* vecABCheck = MultiplyMatrixOnVector(matrixA, vectorX, dimension);
	PrintVector(vecABCheck, dimension, "vector B check (A * x = b):");

	// determinant check
	std::cout << "Recursive Determinant (det A) = " << FindDeterminantRecursive(matrixA, dimension) << std::endl
		<< "Diagonals Elements Multiply (det U * det U_T) = " << FindDeterminantUTU(matrixU, dimension) << std::endl;

}