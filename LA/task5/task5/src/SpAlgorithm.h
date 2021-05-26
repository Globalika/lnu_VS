#pragma once
#include<iostream>
using namespace std;

std::tuple<double**, double*, double*, int, double> GetInfoFromFile(std::string filePath);
void PrintVector(double* vector, int dimension, std::string str = "");
void PrintMatrix(double**& matrix, int dimension, std::string str = "");
double* MultiplyMatrixOnVector(double** matrix, double* vector, int dimension);

void SpAlgorithm(string path);