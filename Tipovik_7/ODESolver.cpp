#include "ODESolver.h"

ODESolver::ODESolver(double k, double l)
{
	this->k = k;
	this->l = l;
}

double ODESolver::Function(double x, double y)
{
	return pow(x, 2) + ((k -1)/2) * y;
}

void ODESolver::PrintBorder()
{
	for (int i = 0; i < 100; i++)
		printf("*");
	printf("\n\n");
}
