#pragma once
#include "ODESolver.h"
class EulerMethod : public ODESolver
{
	public:
		EulerMethod(double k, double l) : ODESolver(k, l){};

		void Solve() override;

	private:
		void Print(const double& x, const double& y, const double& result);
};