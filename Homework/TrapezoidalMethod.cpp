#include "TrapezoidalMethod.h"

void TrapezoidalMethod::Research()
{
	printf("TrapezoidalMethod\n\n");
	fileWithResult.ClearRecords();
	Calculate(4);
	Calculate(6);
	Calculate(8);
}

void TrapezoidalMethod::Calculate(int N)
{
	double h = (b - a) / N;

	double result = Function(a) + Function(b);

	for (int i = 1; i < N; i++)
	{
		double currX = a + i * h;
		double FuncX = Function(currX);
		double intermediateResult = 2 * FuncX;
		result += intermediateResult;

		char buf[256];
		int check = snprintf(buf, sizeof(buf), "X%i = %.7f\nF(X%i) = %.7f\n2 * %.7f = %.7f\n", i, currX, i, FuncX, FuncX, intermediateResult);
		fileWithResult.Write(buf);
	}

	result *= h / 2;

	printf("Result N%i: % .7f\n", N, result);
	printf("Integral: %.7f\n\n", integralResult);

	char buf[256];
	int check = snprintf(buf, sizeof(buf), "Result N%i: %.7f\nIntegral: %.7f\n", N, result, integralResult);
	fileWithResult.Write(buf);
	fileWithResult.Write("----------------------------------------------------------------------------------\n");
}
