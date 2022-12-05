#pragma once
#include <iostream>
#include <math.h>

using namespace std;

class ODESolver
{
	public:
		ODESolver(double k, double l);
		virtual void Solve() = 0;

	protected:
		double k;
		double l;

		const double h = 0.5F;
		const unsigned short steps = 5;

		double Function(double x, double y);

		void PrintBorder();
};

