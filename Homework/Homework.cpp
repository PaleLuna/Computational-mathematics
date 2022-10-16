#include <iostream>

#include "ConvergenceResearch.h"
#include "GaussMethod.h"
#include "TrapezoidalMethod.h"
#include "SimpsonMethod.h"

using namespace std;

int main()
{
	double K;
	double L;
	printf("K >> ");
	cin >> K;
	printf("L >> ");
	cin >> L;

	setlocale(LC_ALL, "ru");
	ConvergenceResearch* taks = new GaussMethod(K, L);
	taks->Research();

	delete taks;
	taks = new TrapezoidalMethod(K, L);
	taks->Research();

	delete taks;
	taks = new SimpsonMethod(K, L);
	taks->Research();

	return 0;
}