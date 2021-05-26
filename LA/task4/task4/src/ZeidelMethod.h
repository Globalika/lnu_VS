#pragma once
#include<iostream>
using namespace std;


bool ConvergeCheck(double* vexX_i, double* vexX_iplus1, int dimension, double eps);
std::tuple<double**, double*, int, double> GetInfoFromFile(std::string filePath);
void PrintVector(double* vector, int dimension, std::string str = "");
void PrintMatrix(double**& matrix, int dimension, std::string str = "");
double* MultiplyMatrixOnVector(double** matrix, double* vector, int dimension);
double GetSum(double** matrix, double* vec, int i, int a, int b);
std::pair<double*, int> AlgorithmImplementation(double** matrix, double* vecB, int dimension, double eps);
double GetNormaAxminusb(double** matrix, double* vecB, double* vecX, double dimension);
bool MatrixDiagonalZeroElementsCheck(double** matrix, double dimension);
bool MatrixDiagonalDominanceCheck(double** matrix, double dimension);
void ZeidelAlgorithm(string path);