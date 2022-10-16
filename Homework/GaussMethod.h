#pragma once

#include "ConvergenceResearch.h"
#include "GaussTable.h"

class GaussMethod: public ConvergenceResearch
{
	public:
		GaussMethod(double K, double L) : ConvergenceResearch(K, L) { fileWithResult.SetDirectory(pathFile); };
		GaussMethod();
		~GaussMethod();

		virtual void Research() override;

	private:
		string pathFile = "GaussMethod.txt";

		GaussTable* n4;
		GaussTable* n6;
		GaussTable* n8;

		void CreateTable();

		void Calculate(GaussTable* table);

		double CalculateArgument(double t);
};

