#include "ODESolver.h"

class TrapezoidMethod : public ODESolver
{
    public:
		TrapezoidMethod(double k, double l) : ODESolver(k, l) { printf("Метод Трапеций\n\n"); }

		void Solve() override;

	private:

		double currentX;
		double nextX;

		double currentY = l;
		double nextY;

		double firstFuncRes;
		double secondFuncRes;
		void Print();
};
