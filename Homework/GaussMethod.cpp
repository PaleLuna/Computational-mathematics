#include "GaussMethod.h"

GaussMethod::GaussMethod(){}

GaussMethod::~GaussMethod()
{
	delete n4;
	delete n6;
	delete n8;
}

void GaussMethod::Research()
{
	n4 = new GaussTable(2);
	n6 = new GaussTable(3);
	n8 = new GaussTable(4);

	printf("GaussMethod\n\n");
	CreateTable();
	fileWithResult.ClearRecords();

	Calculate(n4);
	Calculate(n6);
	Calculate(n8);
}

void GaussMethod::CreateTable()
{
	n4->table[0][0] = 0.861136F;
	n4->table[0][1] = 0.339981F;

	n4->table[1][0] = 0.347854F;
	n4->table[1][1] = 0.652145F;


	n6->table[0][0] = 0.932464F;
	n6->table[0][1] = 0.611209F;
	n6->table[0][2] = 0.238619F;

	n6->table[1][0] = 0.171324F;
	n6->table[1][1] = 0.360761F;
	n6->table[1][2] = 0.467913F;


	n8->table[0][0] = 0.960289F;
	n8->table[0][1] = 0.796666F;
	n8->table[0][2] = 0.525532F;
	n8->table[0][3] = 0.183434F;

	n8->table[1][0] = 0.101228F;
	n8->table[1][1] = 0.222381F;
	n8->table[1][2] = 0.313706F;
	n8->table[1][3] = 0.362683F;
}


double GaussMethod::CalculateArgument(double t)
{
	return (a + b)/2 + ((b - a)/2) * t;
}

void GaussMethod::Calculate(GaussTable* table)
{
	double result = 0;
	for (int i = 0; i < table->N; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			double curT = pow(-1, j) * table->table[0][i];
			double FuncT = Function(CalculateArgument(curT));
			double intermediateResult = table->table[1][i] * FuncT;

			result += table->table[1][i] * FuncT;

			char buf[256];
			int check = snprintf(buf, sizeof(buf), "F(t%i): %.7f\nA%i * F(t%i) = %.7f\n", j+1 + i*2, FuncT, i + 1, j + 1 + i * 2, intermediateResult);
			fileWithResult.Write(buf);
		}
	}
		


	result *= ((b - a) / 2);

	printf("Result N%i: % .7f\n", 2*table->N, result);
	printf("Integral: %.7f\n\n", integralResult);

	char buf[256];
	int check = snprintf(buf, sizeof(buf), "Result N%i: %.7f\nIntegral: %.7f\n", 2 * table->N, result, integralResult);
	fileWithResult.Write(buf);
	fileWithResult.Write("----------------------------------------------------------------------------------\n");
}