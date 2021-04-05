#include <iostream>
#include <string>
using namespace std;
#include <thread>
void print(double* arr, string name, int n);
double max(double* x_i, double* y, int n);
void norma_kapa(double first, double& kapa1, double& kapa2, double& M1, double& M2)
{
	if (first != 1) {
		kapa1 /= first;
		kapa2 /= first;
		M1 /= first;
		M2 /= first;
	}
}


int main()
{
	//y''(x) + 2y'(x) - 3y(x) = 2 + 4x - 6x^2; x : (0, 1)

	int n = 4;
	//double h = (double)1 / n;

	double first = 2;
	double M1 = 3;
	double M2 = 2.8;
	double kapa1 = -1;
	double kapa2 = -0.8;
	double* a_i = new double[n];
	double* b_i = new double[n];
	double* c_i = new double[n];

	double* alpha = new double[n];
	double* betta = new double[n];
	double* y = new double[n];

	double* f_x_i = new double[n];
	double* x_i = new double[n];

	norma_kapa(first, kapa1, kapa2, M1, M2);

	alpha[0] = kapa1;
	betta[0] = M1;

	/////////////Version1//////////
	for (int i = 0; i < n; i++) {
		a_i[i] = 1;
		b_i[i] = 1;
		c_i[i] = 3;
		f_x_i[i] = 1;
	}
	//////////////////////////////

	for (int i = 0; i < n - 1; i++) {
		alpha[i + 1] = (b_i[i]) / (c_i[i] - a_i[i] * alpha[i]);
		betta[i + 1] = (f_x_i[i] + a_i[i] * betta[i]) / (c_i[i] - a_i[i] * alpha[i]);
	}

	y[n] = (M2 + (kapa2)*betta[n - 1]) / (1 - (kapa2)*alpha[n - 1]);
	for (int i = n - 1; i > -1; i--) {
		y[i] = alpha[i] * y[i + 1] + betta[i];
	}

	print(alpha, "a", n);
	print(betta, "b", n);
	print(y, "y", n + 1);


	//cout << max(x_i, y, n);

	system("pause");
	return 0;
}

void print(double* arr, string name, int n) {
	for (int i = 0; i < n; i++) {
		cout << name << "[" << i << "] = " << arr[i] << endl;
	}
	cout << endl;
}
double max(double* x_i, double* y, int n) {
	double max = 0;
	for (int i = 0; i < n; i++) {
		if (abs(y[i] - x_i[i] * x_i[i]) > max)
		{
			max = abs(y[i] - x_i[i] * x_i[i]);
		}
	}
	cout << "Max: " << max << endl;
	return max;
}