#include "TrapezoidMethod.h"

#include "EulerMethod.h"

void TrapezoidMethod::Solve()
{
	PrintBorder();

	for (int i = 1; i < steps; i++)
	{
		nextX = i * h;
		currentX = nextX - h;

		firstFuncRes = Function(currentX, currentY);
		secondFuncRes = Function(nextX, currentY + h * firstFuncRes);

		nextY = currentY + (h/2) * (firstFuncRes + secondFuncRes);

		Print();

		currentY = nextY;
	}

	PrintBorder();
}

void TrapezoidMethod::Print()
{
	printf("CurrentX: %.3f\nnextX: %.3f\nCurrentY: %.3f\n\n", currentX, nextX, currentY);
	printf("FirstFunc = %.3f^2 + ((%.3f - 1)/2) * %.3f = %.3f\n\n", currentX, k, currentY, firstFuncRes);
	printf("SecondFunc = %.3f^2 + ((%.3f - 1)/2) * %.3f = %.3f\n\n", nextX, k, currentY + h * firstFuncRes, secondFuncRes);
	printf("NextY: %.3f + %.3f/2* (%.3f + %.3f) = %.3f\n\n\n\n", currentY, h, firstFuncRes, secondFuncRes, nextY);
}
