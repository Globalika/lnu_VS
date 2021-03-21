//				Square Root Method. Header				//
#include<iostream>
std::tuple<float**, int, float*> GetInfoFromFile(std::string filePath);
bool isNearlyEqualZero(float number);
float FindDeterminantUTU(float** matrix, int dimension);
void ClearMemory(float**& matrix, int dimension);
bool CheckIfMatrixSymmetric(float** matrix, int dimension);
float FindDeterminantRecursive(float**& matrix, int dimension);
bool CheckIfMatrixdDegenerateRecursive(float** matrix, int dimension);
bool CheckIfMatrixdDegenerateUTU(float** matrix, int dimension);
float SumSquare(float** matrixU, int i);
float SumMultiply(float** matrix, int i, int j);
float SumY(float** matrix, int i, float* vectorY);
float SumX(float** matrix, int i, int dimension, float* vectorX);
std::pair<float**, float**> GetUTU(float** matrixA, int dimension);
float* GetVectorY(float** matrixU, int dimension, float* vectorB);
float* GetVectorX(float** matrixU_T, int dimension, float* vectorY);
void PrintMatrix(float**& matrix, int dimension, std::string str = "");
void PrintVector(float* vector, int dimension, std::string str = "");
float** MultiplyMatrix(float** matrix1, float** matrix2, int dimension);
float* MultiplyMatrixOnVector(float** matrix, float* vector, int dimension);
void SquareRootMethod(std::string path);