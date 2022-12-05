#pragma once
#include "ODESolver.h"
class RungeKuttaMethod : public ODESolver
{
public:
	RungeKuttaMethod(double k, double l) : ODESolver(k, l) 
	{ 
		currentY = l;
		printf("Метод Рунге-Кутта\n\n"); 
	}

	void Solve() override;

private:

	double currentX;

	double currentY;
	double nextY;

	double k[4];


	void CalculateCoeff();
	void Print();
};

