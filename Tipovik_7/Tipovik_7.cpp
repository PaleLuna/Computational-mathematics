#include <iostream>

#include "ODESolver.h"
#include "EulerMethod.h"
#include "TrapezoidMethod.h"
#include "RungeKuttaMethod.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "ru");

	double k, l;

	printf("K >> ");
	cin >> k;
	printf("L >> ");
	cin >> l;

	(new EulerMethod(k, l))->Solve();
	(new TrapezoidMethod(k, l))->Solve();
	(new RungeKuttaMethod(k, l))->Solve();
	return 0;
}