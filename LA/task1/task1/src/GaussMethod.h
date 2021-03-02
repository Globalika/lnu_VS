//				Gauss Method. Find Inverse Matrix. Header				//
void PrintMatrix(float**& matrix, int arraysAmount, int columnsAmount, std::string str = "");
void PrintMatrix(float**& matrix, int dimension, std::string str = "");
void SwapMatrixArrays(float**& matrix, int firstArray, int secondArray, int columnsAmount);
int GetMaxElementArray(float**& matrix, int column, int arraysAmount);
void ZeroMatrixColumn(float**& matrix, int column, int arraysAmount, int columnAmount);
float* GetResultColumn(float**& matrix, float* column, int arraysAmount, int columnAmount);
float* GetMatrixColumn(float**& matrix, int order, int columnID);
float** MultiplyMatrix(float**& matrix1, float** matrix2, int order);
float FindDeterminantRecursive(float**& matrix, int n);
std::pair<float**, int> GetMatrixFromFile(std::string filename);
float**& CreateMatrixAndIdentity(float**& matrix, int n);
void ClearMemory(float**& a, int n);
bool isNearlyEqualZero(float x);
void FindInverseMatrix(std::string str);