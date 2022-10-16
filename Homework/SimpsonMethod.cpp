#include "SimpsonMethod.h"

void SimpsonMethod::Research()
{
	printf("SimpsonMethod\n\n");
	fileWithResult.ClearRecords();
	Calculate(4);
	Calculate(6);
	Calculate(8);
}

void SimpsonMethod::Calculate(int N)
{
	while (N % 4 != 0)
		N *= 2;

	double h = (b - a) / N;

	double result = Function(a) + Function(b);

	for (int i = 1; i < N; i++)
	{
		double currX = a + i * h;
		double FuncX = Function(currX);
		int mltp = ((i % 2 == 0) ? 2 : 4);
		double intermediateResult = mltp * FuncX;
		result += intermediateResult;

		char buf[256];
		int check = snprintf(buf, sizeof(buf), "X%i = %.7f\nF(X%i) = %.7f\n%i * %.7f = %.7f\n", i, currX, i, FuncX, mltp, FuncX, intermediateResult);
		fileWithResult.Write(buf);

	}

	result *= h / 3.F;

	printf("Result N%i: % .7f\n", 2*N, result);
	printf("Integral: %.7f\n\n", integralResult);

	char buf[256];
	int check = snprintf(buf, sizeof(buf), "Result N%i: %.7f\nIntegral: %.7f\n", N, result, integralResult);
	fileWithResult.Write(buf);
	fileWithResult.Write("----------------------------------------------------------------------------------\n");
}
