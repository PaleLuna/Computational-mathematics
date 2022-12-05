#include "EulerMethod.h"

void EulerMethod::Solve()
{
	PrintBorder();

	double currentY = l;

	for (int i = 0; i < steps; i++)
	{
		double currentX = i * h;
		double nextY = currentY + h * Function(currentX, currentY);

		Print(currentX, currentY, nextY);

		currentY = nextY;
	}

	PrintBorder();
}

void EulerMethod::Print(const double& x, const double& y, const double& result)
{
	printf("X: %.1f\nY: %.3f\n", x, y);
	printf("result = %.3f + %.1f * (%.1f^2 + ((%.1f-1)/2)) * %.3f) = %.3f\n\n", y, h, x, k, y, result);
}