#include "TridiagonalMatrixAlgorithm.h"
#include <iostream>
#include <math.h>
#include <fstream>
#include <string>
#include <tuple>

#define epsilonN -1e-6
#define epsilonP 1e-6

bool isNearlyEqualZero(float number)
{
	bool temp;
	if (number > 0)
	{
		temp = number <= epsilonP;
	}
	else
	{
		temp = number >= epsilonN;
	}
	return temp;
}
std::tuple<float*, float*, float*, float*, int> GetInfoFromFile(std::string filePath)
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
		float* vectorA = new float[dimension-1];
		float* vectorB = new float[dimension-1];
		float* vectorC = new float[dimension];
		float* vectorF = new float[dimension];
		float temp;
		while (!fin.eof())
		{
			for (int i = 0; i < dimension-1; i++)
			{
				fin >> temp;
				vectorB[i] = temp;
			}
			for (int k = 0; k < dimension; k++)
			{
				fin >> temp;
				vectorC[k] = temp;
			}
			for (int j = 0; j < dimension-1; j++)
			{
				fin >> temp;
				vectorA[j] = temp;
			}
			for (int k = 0; k < dimension; k++)
			{
				fin >> temp;
				vectorF[k] = temp;
			}
		}
		fin.close();
		return std::make_tuple(vectorA, vectorB, vectorC, vectorF, dimension);
	}
}
float* GetVectorAlpha(float*  vecA, float* vecB, float* vecC, int dimension)
{
	float* vecAlpha = new float[dimension-1];

	vecAlpha[0] = (-1) * vecB[0] / vecC[0];

	for (int i = 0; i < dimension-2; i++)
	{
		vecAlpha[i + 1] = (-1) * vecB[i+1] / (vecC[i+1] + vecA[i] * vecAlpha[i]);
	}
	return vecAlpha;
}
float* GetVectorBetta(float* vecA, float* vecB, float* vecC, float* vecF, float* vecAlpha, int dimension)
{
	float* vecBetta = new float[dimension];
	vecBetta[0] = vecF[0] / vecC[0];

	for (int i = 0; i < dimension-2; i++)
	{
		vecBetta[i + 1] = (vecF[i+1] - vecA[i] * vecBetta[i]) / (vecC[i+1] + vecA[i] * vecAlpha[i]);
	}
	return vecBetta;
}
float* GetVectorY(float* vecA, float* vecC, float* vecF, float* vecAlpha, float*vecBetta, int dimension)
{
	float* vecY = new float[dimension-1];
	vecY[dimension - 1] = (vecF[dimension - 1] - vecA[dimension - 2] * vecBetta[dimension - 2])
		/ (vecC[dimension - 1] + vecA[dimension - 2] * vecAlpha[dimension - 2]);

	for (int i = dimension - 2; i >= 0; i--)
	{
		vecY[i] = vecAlpha[i] * vecY[i + 1] + vecBetta[i];
	}
	return vecY;
}
void PrintVector(float* vector, int dimension, std::string str)
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
std::tuple<float*, float*, float*, float*, int> InitializeVectorsByAlgorithm(int n)
{
	float* vectorA = new float[n -1];
	float* vectorB = new float[n -1];
	float* vectorC = new float[n];
	float* vectorF = new float[n];

	float h = 1 / (float)(n-1);
	vectorA[n - 2] = 0;
	for (int i = 0; i < n - 2 ; i++)
	{
		vectorA[i] = 1;
	}
	vectorB[0] = 0;
	for (int i = 1; i < n - 1; i++)
	{
		vectorB[i] = 1;
	}
	vectorC[0] = vectorC[n - 1] = 1;
	for (int i = 1; i < n - 1; i++)
	{
		vectorC[i] = -2 - (1 + i * h) * pow(h,2);
	}
	vectorF[0] = 1;
	vectorF[n - 1] = 3;
	for (int i = 1; i < n - 1; i++)
	{
		vectorF[i] = pow(h, 2) * (4 - (1 + i * h) * (2*pow(i,2)*pow(h, 2) +1));
	}
	return std::make_tuple(vectorA,vectorB,vectorC,vectorF,n);
}
float** MakeMatrixFromThreeVectors(float* vecA, float* vecB, float* vecC, int n)
{
	float** matrix = new float* [n];
	for (int i = 0; i < n; i++)
	{
		matrix[i] = new float[n];
	}
	for (size_t i = 0; i < n; i++)
	{//
		for (size_t j = 0; j < n; j++)
		{
			if (i == j)
			{
				matrix[i][j] = vecC[i];
			}
			else if (i + 1 == j)
			{
				matrix[i][j] = vecB[i];
			}
			else if (i == j + 1)
			{
				matrix[i][j] = vecA[i-1];
			}
			else
			{
				matrix[i][j] = 0;
			}
		}
	}
	return matrix;
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
			resultVector[i] += matrix[i][j] * vector[j];
		}
	}
	//
	return resultVector;
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
bool CorrectnessCheck(float* vecA, float* vecB, float* vecC, int dimension)
{
	
	bool stateC_i = true, stateA_i = true, stateB_i = true,
		stateC_B_i = true, stateC_A_B_i = true, stateC_A_i = true;
	//C_i > 0
	for (int i = 0; i < dimension; i++)
	{
		if (!(std::abs(vecC[i]) > 0))
			stateC_i = false;
	}
	//A_i > 0
	for (int i = 0; i < dimension - 2; i++)/////////////
	{
		if (!(std::abs(vecA[i]) > 0))
			stateA_i = false;
	}
	//B_i > 0
	for (int i = 1; i < dimension - 1; i++)////////////////
	{
		if (!(std::abs(vecB[i]) > 0))
			stateB_i = false;
	}

	//C_0 >= B_0
	if (!std::abs(vecC[0]) >= std::abs(vecB[0]))
		stateC_B_i = false;

	//C_i >= A_i + B_i
	for (int i = 1; i < dimension-2; i++)
	{
		if (!(std::abs(vecC[i]) >= (std::abs(vecA[i]) + std::abs(vecB[i]))))
			stateC_A_B_i = false;
	}
	//C_i > A_i
	if (!(std::abs(vecC[dimension-1]) >= std::abs(vecA[dimension-2])))
		stateC_A_i = false;

	return((stateC_i && stateA_i && stateB_i) && (stateC_A_B_i || stateC_A_i || stateC_B_i));
}
float FindNormY(float* vecY, int n)
{
	float* vecYY = new float[n];
	float h = 1 / (float)(n-1);
	for (int i = 0; i < n; i++)
	{
		vecYY[i] = (2 * pow(i,2) * pow(h,2)) + 1;
	}

	float norma = 0;
	for (size_t i = 0; i < n; i++)
	{
		norma += pow((vecY[i] - vecYY[i]), 2);
	}
	return  sqrt(norma);
}
void TridiagonalAlgorithm(string path)
{
	//auto info = GetInfoFromFile(path);
	auto info = InitializeVectorsByAlgorithm(6);

	float* vectorA = std::get<0>(info);
	float* vectorB = std::get<1>(info);
	float* vectorC = std::get<2>(info);
	float* vectorF = std::get<3>(info);
	int dimension = std::get<4>(info);
	PrintVector(vectorA, dimension-1, "A");
	PrintVector(vectorB, dimension-1, "B");
	PrintVector(vectorC, dimension, "C");
	PrintVector(vectorF, dimension, "F");
	//
	
	cout << endl << (CorrectnessCheck(vectorA, vectorB, vectorC, dimension) ? "The matrix is correct!" : "Tre matrix is not correct!") << endl << endl;


	//
	float* alpha = GetVectorAlpha(vectorA, vectorB, vectorC, dimension);
	PrintVector(alpha, dimension-1, "alpha");
	float* betta = GetVectorBetta(vectorA,vectorB, vectorC, vectorF, alpha, dimension);
	PrintVector(betta, dimension-1, "betta");
	float* vecY = GetVectorY(vectorA, vectorC, vectorF, alpha, betta, dimension);
	PrintVector(vecY, dimension, "Y");
	auto matrix = MakeMatrixFromThreeVectors(vectorA, vectorB, vectorC, dimension);
	PrintMatrix(matrix,dimension, "matrix");
	auto resultVector = MultiplyMatrixOnVector(matrix, vecY, dimension);
	PrintVector(resultVector, dimension, "check");
	//

	cout << endl << "Rate of difference :" << FindNormY(vecY, dimension)<< endl;

	return;
}
























//y''(x) + 2y'(x) - 3y(x) = 2 + 4x - 6x^2; x : (0, 1)

	//int n = 4;
	////double h = (double)1 / n;

	//double first = 2;
	//double M1 = 3;
	//double M2 = 2.8;
	//double kapa1 = -1;
	//double kapa2 = -0.8;
	//double* a_i = new double[n];
	//double* b_i = new double[n];
	//double* c_i = new double[n];

	//double* alpha = new double[n];
	//double* betta = new double[n];
	//double* y = new double[n];

	//double* f_x_i = new double[n];
	//double* x_i = new double[n];

	//norma_kapa(first, kapa1, kapa2, M1, M2);

	//alpha[0] = kapa1;
	//betta[0] = M1;

	///////////////Version1//////////
	//for (int i = 0; i < n; i++) {
	//	a_i[i] = 1;
	//	b_i[i] = 1;
	//	c_i[i] = 3;
	//	f_x_i[i] = 1;
	//}
	////////////////////////////////

	//for (int i = 0; i < n - 1; i++) {
	//	alpha[i + 1] = (b_i[i]) / (c_i[i] - a_i[i] * alpha[i]);
	//	betta[i + 1] = (f_x_i[i] + a_i[i] * betta[i]) / (c_i[i] - a_i[i] * alpha[i]);
	//}

	//y[n] = (M2 + (kapa2)*betta[n - 1]) / (1 - (kapa2)*alpha[n - 1]);
	//for (int i = n - 1; i > -1; i--) {
	//	y[i] = alpha[i] * y[i + 1] + betta[i];
	//}

	//print(alpha, "a", n);
	//print(betta, "b", n);
	//print(y, "y", n + 1);


	////cout << max(x_i, y, n);

	//system("pause");
//
//
//void print(double* arr, string name, int n) {
//	for (int i = 0; i < n; i++) {
//		cout << name << "[" << i << "] = " << arr[i] << endl;
//	}
//	cout << endl;
//}
//double max(double* x_i, double* y, int n) {
//	double max = 0;
//	for (int i = 0; i < n; i++) {
//		if (abs(y[i] - x_i[i] * x_i[i]) > max)
//		{
//			max = abs(y[i] - x_i[i] * x_i[i]);
//		}
//	}
//	cout << "Max: " << max << endl;
//	return max;
//}
//void norma_kapa(double first, double& kapa1, double& kapa2, double& M1, double& M2)
//{
//	if (first != 1) {
//		kapa1 /= first;
//		kapa2 /= first;
//		M1 /= first;
//		M2 /= first;
//	}
//}
//

