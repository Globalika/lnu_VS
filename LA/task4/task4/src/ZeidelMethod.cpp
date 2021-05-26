#include "ZeidelMethod.h"
#include <math.h>
#include <fstream>
#include <string>
#include <tuple>

bool ConvergeCheck(double* vexX_i, double* vexX_iplus1, int dimension, double eps)
{
	double norma = 0;
	for (int i = 0; i < dimension; i++) {
		norma += pow((vexX_iplus1[i] - vexX_i[i]), 2);
	}
	if (sqrt(norma) < eps) {
		cout << "	" << sqrt(norma) << " < " << eps << endl;
	}
	else {
		cout << "	" << sqrt(norma) << " >= " << eps << endl;
	}
	return (sqrt(norma) < eps);
}
std::tuple<double**, double*, int, double> GetInfoFromFile(std::string filePath)
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
		double** matrix = new double*[dimension];
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
		double* vectorB = new double[dimension];
		for (int k = 0; k < dimension; k++)
		{
			fin >> vectorB[k];
		}
		fin >> eps;
		fin.close();
		return std::make_tuple(matrix, vectorB, dimension, eps);
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
double GetSum(double** matrix, double* vec, int i, int a, int b)
{
	
	double sum = 0;
	for (int j = a; j < b; j++)
	{
		sum += matrix[i][j] * vec[j];
	}
	//if (n == 0)
	//for (size_t j = n; j < m; j++)
	//{
	//	sum += matrix[n][j + 1] * vec[j];
	//}
	//else
	//for (size_t j = n; j < m; j++)
	//{
	//	sum += matrix[n - 1][j] * vec[j];
	//}
	return sum;
}
std::pair<double*, int> AlgorithmImplementation(double** matrix, double* vecB, int dimension, double eps)
{
	int k = 0;
	double* vecX_i = new double[dimension]();
	double* vecX_iplus1 = new double[dimension]();
	do
	{
		//
		for (int i = 0; i < dimension; i++) {
			vecX_i[i] = vecX_iplus1[i];
		}
		//
		k++;
		for (int i = 0; i < dimension; i++) {
			vecX_iplus1[i] = (-1 / matrix[i][i]) *
				(
					GetSum(matrix, vecX_iplus1, i, 0, i)
					+ GetSum(matrix, vecX_i, i, i + 1, dimension)
					- vecB[i]
					);
		}
		if (k > 50)break;
		//
		string str = std::to_string(k);
		PrintVector(vecX_iplus1,dimension, str);
	} while (!ConvergeCheck(vecX_i, vecX_iplus1, dimension, eps));
	return std::make_pair(vecX_iplus1,k);
}
double GetNormaAxminusb(double** matrix, double* vecB, double* vecX, double dimension)
{
	double* vecAX = MultiplyMatrixOnVector(matrix, vecX, dimension);
	double norma = abs(vecAX[0] - vecB[0]);

	for (size_t i = 1; i < dimension; i++) {
		if (norma < abs(vecAX[i] - vecB[i]))
			norma = abs(vecAX[i] - vecB[i]);
	}
	return norma;
}
bool MatrixDiagonalZeroElementsCheck(double** matrix, double dimension)
{
	for (size_t i = 0; i < dimension; i++)
	{
		if (matrix[i][i] == 0)return false;
	}
	return true;
}
bool MatrixDiagonalDominanceCheck(double** matrix, double dimension)
{
	double* sumArr = new double[dimension]();
	for (int i = 0; i < dimension; i++) {
		for (int j = 0; j < dimension; j++) {
			sumArr[i] += matrix[i][j];
		}
		sumArr[i] -= matrix[i][i];
		if (matrix[i][i] < sumArr[i]) return false;
	}
	return true;
}
void ZeidelAlgorithm(string path)
{
	auto info = GetInfoFromFile(path);
	int n = std::get<2>(info);
	double eps = std::get<3>(info);
	double* vecB = std::get<1>(info);
	double** matrix = std::get<0>(info);
	cout << endl;
	PrintMatrix(matrix,n,"Matrix");
	cout << endl;
	PrintVector(vecB, n, "Vector B");
	cout << endl;
	//
	/*if (!MatrixDiagonalZeroElementsCheck(matrix, n)) {
		cout << "Matrix has Diagonal Zero Element!" << endl;
		return; }
	if (!MatrixDiagonalDominanceCheck(matrix, n)) {
		cout << "Matrix has not Diagonal Dominance!" << endl;
		return;
	}*/
	//
	auto result = AlgorithmImplementation(matrix, vecB, n, eps);
	cout << endl << endl;
	PrintVector(std::get<0>(result), n, "Vector X");
	cout << std::get<1>(result) << " iterations" << endl;
	cout << "||A*x - b|| = " << GetNormaAxminusb(matrix, vecB, std::get<0>(result),n) << endl;
	return;
}
