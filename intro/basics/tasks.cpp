#include "tasks.h"
#include <vector>
#include <cmath>

int NOuter::NInner::DoSomething(int lhs, int rhs) {
	return (lhs + rhs);
}

int NOuter::DoSomething(int lhs, int rhs) {
	return (lhs - rhs);
}

int NOverload::ProcessTwoArgs(int lhs, int rhs) {
	return (lhs + rhs);
}

char NOverload::ProcessTwoArgs(char lhs, char rhs) {
	return (std::max(lhs, rhs));
}  

int NOverload::ProcessTwoArgs(int lhs, char rhs) {
	return (std::abs(lhs-rhs)) ;
}

unsigned int NOverflow::WithOverflow(int lhs, int rhs) {
	return (lhs + rhs);
}

uint64_t NOverflow::WithOverflow(int64_t lhs, int64_t rhs) {
	return (std::abs(lhs - rhs));
}

int NLoop::SumInRange(const int lhs, const int rhs) {
	return((lhs + rhs - 1) * (rhs - lhs) / 2);
}

int NLoop::CountFixedBitsInRange(const int from, const int to, const int bitsCnt) {
	int k = 0;
	for (int n = from; n <= to; n++) {
		int s = 0;
		while (n > 0) {
			if (n % 2 == 1) {
				s += 1;
			}
			n = n / 2;
		}
		if (s == bitsCnt) {
			k++;
		}
	}
	return k;
}

double NMath::ComputeMathFormula(const double arg) {
	return (std::abs((sin(arg) / 2 + cos(arg)) * (sin(arg) / 2 + cos(arg)) + tan(arg) * atan(arg)));
}

bool NMath::IsPositive(int arg) {
	bool r = (arg > 0);
	return (r);
}

int NRecursion::CalculateFibonacci(const int arg) {
	std::vector <int> a(arg);
	a[1] = 1;
	a[2] = 1;
	for (int i = 3; i <= arg; ++i) {
		a[i] = a[i - 1] + a[i - 2];
	}
<<<<<<< HEAD
	f1 += 100;
	return f2;
=======
	return (a[arg]);
>>>>>>> 39c4e8d (Last part of first homework)
}
