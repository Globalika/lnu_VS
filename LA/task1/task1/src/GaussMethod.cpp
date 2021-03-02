#include<iostream>
#include<math.h>
#include <fstream>
#include <string>
#define epsilon 1e-6
//				Gauss Method. Find Inverse Matrix				//
void PrintMatrix(float**& matrix, int rows, int colums, std::string str = "")
{
	if (str != "")
	{
		std::cout << "\t\t" + str + "\t\t\n";
	}
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < colums; j++)
		{
			if (j == rows)
			{
				std::cout << "|\t\t|";
			}
			std::cout << matrix[i][j] << " ";
		}
		std::cout << '\n';
	}
	std::cout << '\n';
	return;
}
void PrintMatrix(float**& matrix, int dimension, std::string str = "")
{
	if (str != "")
	{
		std::cout << "\t\t" + str + "\t\t\n";
	}
	for (int i = 0; i < dimension; i++)
	{
		for (int j = 0; j < dimension; j++)
		{
			std::cout << matrix[i][j] << " ";
		}
		std::cout << '\n';
	}
	std::cout << '\n';
	return;
}
void ClearMemory(float**& matrix, int dimension) {
	for (int i = 0; i < dimension; i++) {
		delete[] matrix[i];
	}
	delete[] matrix;
	return;
}
bool isNearlyEqualZero(float number)
{
	return std::abs(number) <= epsilon;
}
void SwapMatrixArrays(float**& matrix, int firstArray, int secondArray, int columns)
{
	float temp;
	for (int k = firstArray; k < columns; k++)
	{
		temp = matrix[firstArray][k];
		matrix[firstArray][k] = matrix[secondArray][k];
		matrix[secondArray][k] = temp;
	}
	return;
}
int GetMaxElementArray(float**& matrix, int column, int dimension)
{
	int result = column;
	for (int i = column + 1; i < dimension; i++)
	{
		result = (abs(matrix[i][column]) > abs(matrix[i - 1][column])) ? (i) : result;
	}
	return result;
}
void ZeroMatrixColumn(float**& matrix, int column, int rows, int columns)
{
	float coeff = 0;
	for (int i = column + 1; i < rows; i++)
	{
		coeff = matrix[i][column] / matrix[column][column];
		for (int j = column; j < columns; j++)
		{
			matrix[i][j] = matrix[i][j] - coeff * matrix[column][j];
		}
	}
	return;
}
float* GetResultColumn(float**& matrix, float* column, int rows, int columns)
{
	float* resultColumn = new float[rows];
	for (int i = rows - 1; i >= 0; i--)
	{
		if (i == rows - 1)
		{
			resultColumn[i] = column[i] / matrix[i][i];
			continue;
		}
		else
		{
			resultColumn[i] = column[i];
			for (int j = i + 1; j < columns; j++)
			{
				resultColumn[i] -= matrix[i][j] * resultColumn[j];
			}
			resultColumn[i] /= matrix[i][i];
		}
	}
	return resultColumn;
}
float* GetMatrixColumn(float**& matrix, int dimension, int column)
{
	float* resultColumn = new float[dimension];
	for (int i = 0; i < dimension; i++)
	{
		resultColumn[i] = matrix[i][column];
	}
	return resultColumn;
}
float** MultiplyMatrix(float**& matrix1, float** matrix2, int dimension)
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
				resultMatrix[i][j] += matrix1[i][k] * matrix2[k][j];
			}
			if (isNearlyEqualZero(resultMatrix[i][j]))
			{
				//resultMatrix[i][j] = abs(round(resultMatrix[i][j]));
			}
		}
	}
	return resultMatrix;
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
std::pair<float**, int> GetMatrixFromFile(std::string filePath)
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
		}
		fin.close();
		return std::make_pair(matrix, dimension);
	}
}
float**& CreateMatrixAndIdentity(float**& matrix, int dimension)
{
	float** newMatrix = new float* [dimension];
	for (int i = 0; i < dimension; i++)
	{
		newMatrix[i] = new float[dimension * 2];
	}
	for (int i = 0; i < dimension; i++) {

		for (int j = 0; j < 2 * dimension; j++) {
			if (j == (i + dimension))
			{
				newMatrix[i][j] = 1;
			}
			else if (j >= dimension)
			{
				newMatrix[i][j] = 0;
			}
			else
			{
				newMatrix[i][j] = matrix[i][j];
			}
		}
	}
	return newMatrix;
}
void FindInverseMatrix(std::string filePath)
{
	std::cout << "\t\tGauss Method. Find Inverse Matrix\t\t\n\n";
	//Get Matrix and print
	auto matrixInfo = GetMatrixFromFile(filePath);
	float** matrix = matrixInfo.first;
	int dimension = matrixInfo.second;
	PrintMatrix(matrix, dimension, "Get matrix from file");
	//Find Determinant
	float determinant = FindDeterminantRecursive(matrix, dimension);
	if (isNearlyEqualZero(determinant))
	{
		std::cout << "\t\tDeterminant = 0\n\n" << "\t\tMatrix is degenerate\n\n";
		ClearMemory(matrix, dimension);
		return;
	}
	else
	{
		std::cout << "\t\tDeterminant = " << determinant << "\n\n";
	}
	//Create Matrix + Identity Matrix and print
	float** matrixAndIdentity = CreateMatrixAndIdentity(matrix, dimension);
	PrintMatrix(matrixAndIdentity, dimension, dimension * 2, "Matrix + Identity Matrix");
	//Apply Gausse Algoritm (Triangle matrixe) and print step by step
	for (int i = 0; i < dimension - 1; i++)
	{
		int max = GetMaxElementArray(matrixAndIdentity, i, dimension);
		if (i != max)
		{
			SwapMatrixArrays(matrixAndIdentity, i, max, dimension * 2);
			PrintMatrix(matrixAndIdentity, dimension, dimension * 2, "Matrix swap");
		}

		ZeroMatrixColumn(matrixAndIdentity, i, dimension, dimension * 2);
		PrintMatrix(matrixAndIdentity, dimension, dimension * 2, "Zero column");
	}
	//Get Left Half and print
	float** leftMatrix = new float* [dimension];
	for (int i = 0; i < dimension; i++)
	{
		leftMatrix[i] = new float[dimension];
	}
	for (size_t i = 0; i < dimension; i++)
	{
		for (size_t j = 0; j < dimension; j++)
		{
			leftMatrix[i][j] = matrixAndIdentity[i][j];
		}
	}
	PrintMatrix(leftMatrix, dimension, "Left half");
	//Get Right Half and print
	float** rightMatrix = new float* [dimension];
	for (int i = 0; i < dimension; i++)
	{
		rightMatrix[i] = new float[dimension];
	}
	for (size_t i = 0; i < dimension; i++)
	{
		for (size_t j = 0; j < dimension; j++)
		{
			rightMatrix[i][j] = matrixAndIdentity[i][j + dimension];
		}
	}
	PrintMatrix(rightMatrix, dimension, "Right half");
	//Apply Gausse Algoritm (Inverse Matrix) and print
	float** resultMatrix = new float* [dimension];
	for (int i = 0; i < dimension; i++)
	{
		resultMatrix[i] = new float[dimension];
	}
	for (size_t i = 0; i < dimension; i++)
	{
		float* column = GetMatrixColumn(rightMatrix, dimension, i);
		float* resultColumn = GetResultColumn(leftMatrix, column, dimension, dimension);
		float k1 = resultColumn[0], k2 = resultColumn[1], k3 = resultColumn[2];
		for (size_t j = 0; j < dimension; j++)
		{
			resultMatrix[j][i] = resultColumn[j];
		}
	}
	PrintMatrix(resultMatrix, dimension, "Inverse Matrix");
	//Multiplication Check and print
	float** identityMatrix = MultiplyMatrix(matrix, resultMatrix, dimension);
	PrintMatrix(identityMatrix, dimension, "Identity matrix");
	//Clear Memory
	ClearMemory(matrix, dimension);
	ClearMemory(matrixAndIdentity, dimension);
	ClearMemory(leftMatrix, dimension);
	ClearMemory(rightMatrix, dimension);
	ClearMemory(identityMatrix, dimension);
	ClearMemory(resultMatrix, dimension);
}