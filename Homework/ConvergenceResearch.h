#pragma once

#include <math.h>
#include <iostream>
#include "File.h"

class ConvergenceResearch
{
	public:
		ConvergenceResearch(double K, double L);
		ConvergenceResearch();
		virtual void Research() = 0;


	protected:
		double Function(double x);
		File fileWithResult;

		double K;
		double L;

		double a;
		double b;

		double integralResult;
		bool isCalculated;

	private:
		void GetIntegraal();

		void SetA(double K, double L);
		void SetB(double K, double L);

};

inline ConvergenceResearch::ConvergenceResearch(double K, double L)
{
	SetA(K, L);
	SetB(K, L);

	this->K = K;
	this->L = L;

	isCalculated = false;

	GetIntegraal();
}

inline ConvergenceResearch::ConvergenceResearch(){}

inline double ConvergenceResearch::Function(double x)
{
	return (x + L) / (pow(x, 2) + x + K);
}

inline void ConvergenceResearch::GetIntegraal()
{
	if (!isCalculated)
	{
		double res1 = ((1.F / 2.F) * log(pow(b, 2) + b + K)) + (((L - (1.F / 2.F)) / (sqrt(K - (1.F / 4.F)))) * atan((b + (1.F / 2.F)) / (sqrt(K - (1.F / 4.F)))));
		double res2 = (1.F / 2.F) * log(pow(a, 2) + a + K) + (L - (1.F / 2.F)) / (sqrt(K - (1.F / 4.F))) * atan((a + (1.F / 2.F)) / (sqrt(K - (1.F / 4.F))));

		integralResult = res1-res2;
			isCalculated = true;
	}
}

inline void ConvergenceResearch::SetA(double K, double L) { this->a = (K - L) / 2; }
inline void ConvergenceResearch::SetB(double K, double L) { this->b = K + L; }

