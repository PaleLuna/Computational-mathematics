#pragma once
#include "ConvergenceResearch.h"
class SimpsonMethod: public ConvergenceResearch
{
	public:
		SimpsonMethod(double K, double L) : ConvergenceResearch(K, L) { fileWithResult.SetDirectory(pathFile); };

		virtual void Research() override;
	private:
		string pathFile = "SimpsonMethod.txt";
		void Calculate(int N);

};

