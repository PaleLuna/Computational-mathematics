#pragma once

#include "ConvergenceResearch.h"
class TrapezoidalMethod : public ConvergenceResearch
{
	public:
		TrapezoidalMethod(double K, double L) : ConvergenceResearch(K, L) { fileWithResult.SetDirectory(pathFile);};
		virtual void Research() override;

	private:
		string pathFile = "TrapezoidalMethod.txt";
		void Calculate(int N);

};

