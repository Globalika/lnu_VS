#pragma once
#include<iostream>
using namespace std;
void TridiagonalAlgorithm(string path);
bool isNearlyEqualZero(float number);
std::tuple<float*, float*, float*, float*, int> GetInfoFromFile(std::string filePath);
float* GetVectorAlpha(float* vecA, float* vecB, float* vecC, int dimension);
float* GetVectorBetta(float* vecA, float* vecB, float* vecC, float* vecF, float* vecAlpha, int dimension);
float* GetVectorY(float* vecA, float* vecC, float* vecF, float* vecAlpha, float* vecBetta, int dimension);
void PrintVector(float* vector, int dimension, std::string str = "");
std::tuple<float*, float*, float*, float*, int> InitializeVectorsByAlgorithm(int n);
float** MakeMatrixFromThreeVectors(float* vecA, float* vecB, float* vecC, int n);
float* MultiplyMatrixOnVector(float** matrix, float* vector, int dimension);
void PrintMatrix(float**& matrix, int dimension, std::string str = "");
bool CorrectnessCheck(float* vecA, float* vecB, float* vecC, int dimension);
float FindNormY(float* vecY, int n);
void TridiagonalAlgorithm(string path);