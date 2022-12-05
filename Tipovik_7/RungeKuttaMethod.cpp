#include "RungeKuttaMethod.h"

void RungeKuttaMethod::Solve()
{
	PrintBorder();

	for (int i = 0; currentX < 2; i++)
	{
		currentX = i * h;

		CalculateCoeff();

		nextY = currentY + (h / 6) * (k[0] + k[1] + k[2] + k[3]);

		Print();

		currentY = nextY;
	}

	PrintBorder();
}

void RungeKuttaMethod::CalculateCoeff()
{
	k[0] = Function(currentX, currentY);
	k[1] = Function(currentX + h / 2, currentY + (h * k[0] / 2));
	k[2] = Function(currentX + h / 2, currentY + (h * k[1] / 2));
	k[3] = Function(currentX + h, currentY + (h * k[2]));
}

void RungeKuttaMethod::Print()
{
	printf("CurrentX: %.3f\nCurrentY: %.3f\n\n", currentX, currentY);
	for (int i = 0; i < 4; i++)
		printf("K%i = %.3f\n", i, k[i]);
	printf("\n");

	printf("NextY = %.3f + %.3f/6 * (%.3f + %.3f + %.3f + %.3f) = %.3f\n\n", currentY, h, k[0], k[1], k[2], k[3], nextY);
}
