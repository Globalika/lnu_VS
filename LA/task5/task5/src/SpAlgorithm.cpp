#include "SpAlgorithm.h"
#include <math.h>
#include <fstream>
#include <string>
#include <tuple>
#include <vector>

//inverse
void ZeroMatrixColumn(double**& matrix, int column, int rows, int columns)
{
	double coeff = 0;
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
double**& CreateMatrixAndIdentity(double**& matrix, int dimension)
{
	double** newMatrix = new double* [dimension];
	for (int i = 0; i < dimension; i++)
	{
		newMatrix[i] = new double[dimension * 2];
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
double* GetResultColumn(double**& matrix, double* column, int rows, int columns)
{
	double* resultColumn = new double[rows];
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
double* GetMatrixColumn(double**& matrix, int dimension, int column)
{
	double* resultColumn = new double[dimension];
	for (int i = 0; i < dimension; i++)
	{
		resultColumn[i] = matrix[i][column];
	}
	return resultColumn;
}
void SwapMatrixArrays(double**& matrix, int firstArray, int secondArray, int columns)
{
	double temp;
	for (int k = firstArray; k < columns; k++)
	{
		temp = matrix[firstArray][k];
		matrix[firstArray][k] = matrix[secondArray][k];
		matrix[secondArray][k] = temp;
	}
	return;
}
int GetMaxElementArray(double**& matrix, int column, int dimension)
{
	int result = column;
	for (int i = column + 1; i < dimension; i++)
	{
		result = (abs(matrix[i][column]) > abs(matrix[i - 1][column])) ? (i) : result;
	}
	return result;
}
double** GetInverseMatrix(double**& matrix, int dimension)
{
	double** matrixAndIdentity = CreateMatrixAndIdentity(matrix, dimension);
	//
	for (int i = 0; i < dimension - 1; i++)
	{
		int max = GetMaxElementArray(matrixAndIdentity, i, dimension);
		if (i != max)
		{
			SwapMatrixArrays(matrixAndIdentity, i, max, dimension * 2);
		}
		ZeroMatrixColumn(matrixAndIdentity, i, dimension, dimension * 2);
	}
	//
	double** leftMatrix = new double* [dimension];
	for (int i = 0; i < dimension; i++)
	{
		leftMatrix[i] = new double[dimension];
	}
	for (size_t i = 0; i < dimension; i++)
	{
		for (size_t j = 0; j < dimension; j++)
		{
			leftMatrix[i][j] = matrixAndIdentity[i][j];
		}
	}
	//
	double** rightMatrix = new double* [dimension];
	for (int i = 0; i < dimension; i++)
	{
		rightMatrix[i] = new double[dimension];
	}
	for (size_t i = 0; i < dimension; i++)
	{
		for (size_t j = 0; j < dimension; j++)
		{
			rightMatrix[i][j] = matrixAndIdentity[i][j + dimension];
		}
	}
	//
	double** resultMatrix = new double* [dimension];
	for (int i = 0; i < dimension; i++)
	{
		resultMatrix[i] = new double[dimension];
	}
	for (size_t i = 0; i < dimension; i++)
	{
		double* column = GetMatrixColumn(rightMatrix, dimension, i);
		double* resultColumn = GetResultColumn(leftMatrix, column, dimension, dimension);
		for (size_t j = 0; j < dimension; j++)
		{
			resultMatrix[j][i] = resultColumn[j];
		}
	}
	return resultMatrix;
}
//
std::tuple<double**, double*, double*, int, double> GetInfoFromFile(std::string filePath)
{
	std::ifstream fin(filePath);
	if (!fin.is_open())
	{
		throw;
	}
	else
	{
		int dimension;
		double eps;
		fin >> dimension;
		double** matrix = new double* [dimension];
		for (int i = 0; i < dimension; i++)
		{
			matrix[i] = new double[dimension];
		}
		for (int i = 0; i < dimension; i++)
		{
			for (int j = 0; j < dimension; j++)
			{
				fin >> matrix[i][j];
			}
		}
		double* vectorX = new double[dimension];
		for (int k = 0; k < dimension; k++)
		{
			fin >> vectorX[k];
		}
		double* vectorY = new double[dimension];
		for (int k = 0; k < dimension; k++)
		{
			fin >> vectorY[k];
		}
		fin >> eps;
		fin.close();
		return std::make_tuple(matrix, vectorX, vectorY, dimension, eps);
	}
}
void PrintVector(double* vector, int dimension, std::string str)
{
	if (str != "")
	{
		//cout << str << endl;
		std::cout << "\t\t" + str + "\t\t\n";
	}
	for (int i = 0; i < dimension; i++)
	{
		std::cout << vector[i] << " ";
	}
	std::cout << '\n';
	return;
}
void PrintMatrix(double**& matrix, int dimension, std::string str)
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
			/*if (isNearlyEqualZero(matrix[i][j]))
			{
				std::cout << 0 << " ";
			}
			else
			{
				std::cout << matrix[i][j] << " ";
			}*/
		}
		std::cout << '\n';
	}
	return;
}
double* MultiplyMatrixOnVector(double** matrix, double* vector, int dimension)
{
	double* resultVector = new double[dimension];
	for (int i = 0; i < dimension; i++)
	{
		resultVector[i] = 0;
	}
	//
	for (size_t i = 0; i < dimension; i++)
	{
		for (size_t j = 0; j < dimension; j++)
		{
			resultVector[i] += matrix[i][j] * vector[j];
		}
	}
	//
	return resultVector;
}
double** MultiplyMatrix(double**& matrix1, double** matrix2, int dimension)
{
	double** resultMatrix = new double* [dimension];
	for (int i = 0; i < dimension; i++)
	{
		resultMatrix[i] = new double[dimension];
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
		}
	}
	return resultMatrix;
}
double* MultiplyVectors(double* vector1, double* vector2, int dimension)
{
	double* resultVec = new double[dimension];
	for (size_t i = 0; i < dimension; i++)
	{
		resultVec[i] = vector1[i] * vector2[i];
	}
	return resultVec;
}
double GetScalarProduct(double* vector1, double* vector2, int dimension)
{
	double sum = 0;
	for (size_t i = 0; i < dimension; i++)
	{
		sum += vector1[i] * vector2[i];
	}
	return sum;
}
double* GetVectorX(double* vectorY, double s, int dimension)
{
	double* vecX = new double[dimension];
	for (size_t i = 0; i < dimension; i++)
	{
		vecX[i] = vectorY[i] / std::sqrt(s);
	}
	return vecX;
}
bool CheckLambdas(std::vector<double> list, int k, double eps)
{
	return abs(list.at(k) - list.at(k - 1)) <= eps;
}
bool CheckNorma(double* vecX, double* veXp, int dimension, double eps)
{
	double sum = 0, norma = 0;
	for (size_t i = 0; i < dimension; i++)
	{
		sum += pow((vecX[i] - veXp[i]), 2);
	}
	norma = sqrt(sum);
	return norma <= eps;
}
void SpAlgorithm(string path)
{

	auto info = GetInfoFromFile(path);
	double** matrix = std::get<0>(info);
	double* vecX = std::get<1>(info);
	double* vecY = std::get<2>(info);
	int n = std::get<3>(info);
	double eps = std::get<4>(info);
	cout << endl;
	PrintMatrix(matrix, n, "Matrix A");
	cout << endl;
	PrintVector(vecX, n, "Vector X");
	cout << endl;
	PrintVector(vecY, n, "Vector Y");
	cout << endl;
	//
	double** inverseMatrix = GetInverseMatrix(matrix, n);
	double** identityMatrix = MultiplyMatrix(matrix, inverseMatrix, n);
	PrintMatrix(identityMatrix, n, "A*A-1");
	//
	cout << endl;
	PrintMatrix(inverseMatrix, n, "A-1");
	cout << endl;
	std::vector<double> vecLambda;
	vecLambda.push_back(0);

	double t, s = GetScalarProduct(vecY, vecY, n);
	double* vecXp;
	vecX = GetVectorX(vecY, s, n);
	int k = 0;
	do
	{
		vecXp = vecX;
		//PrintVector(vecXp, n, "vectorXp");
		k++;
		cout << "k = " << k << endl;
		//y = a-1*x
		vecY = MultiplyMatrixOnVector(inverseMatrix, vecXp, n);
		//PrintVector(vecY, n, "vectorY");
		//s
		s = GetScalarProduct(vecY, vecY, n);
		//t
		t = GetScalarProduct(vecY, vecXp, n);
		//lambda
		vecLambda.push_back(s / t);
		//x
		vecX = GetVectorX(vecY, s, n);
		PrintVector(vecX, n, "vectorX");
		//check
	} while (!CheckLambdas(vecLambda,k, eps) || !CheckNorma(vecX, vecXp, n, eps));
	//print result//
	cout << endl;
	cout << endl;
	cout << "Result" << endl;
	cout << "k = " << k << endl;
	cout << "Lambda = " << (double)(1 / vecLambda.at(k)) << endl;
	PrintVector(vecX, n, "result vector X");
	//
	double* Ax = MultiplyMatrixOnVector(inverseMatrix, vecX, n);

	PrintVector(Ax, n, "A * x");


	double* lambX = new double[n];
	for (size_t i = 0; i < n; i++)
	{
		lambX[i] = vecX[i] * vecLambda.at(k);
	}
	PrintVector(vecX, n, "lambda * X");

	cout << endl;
	//
}
