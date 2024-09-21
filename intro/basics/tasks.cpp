#include "tasks.h"

#include <cmath>

int NOuter::NInner::DoSomething(int lhs, int rhs) {
	return lhs + rhs;
}

int NOuter::DoSomething(int lhs, int rhs) {
	return lhs - rhs;
}

int NOverload::ProcessTwoArgs(int lhs, int rhs) {
	return lhs + rhs;
}

char NOverload::ProcessTwoArgs(char lhs, char rhs) {
	return (lhs > rhs? lhs : rhs);
}

int NOverload::ProcessTwoArgs(int lhs, char rhs) {
	return lhs - rhs;
}

unsigned int NOverflow::WithOverflow(int lhs, int rhs) {
	return (unsigned int)lhs + (unsigned int)rhs;
}

uint64_t NOverflow::WithOverflow(int64_t lhs, int64_t rhs) {
	return (uint64_t)lhs - (uint64_t) rhs;
}

int NLoop::SumInRange(const int lhs, const int rhs) {
	int sm = 0;
	for (int i = lhs; i < rhs; ++i) {
		sm += i;
	}
	return sm;
}

int NLoop::CountFixedBitsInRange(const int from, const int to, const int bitsCnt) {
	int cnt = 0;
	for (int i = from; i <= to; ++i) {
		int cnt_bits = 0;
		for (int j = 0; j < 31; ++j) {
			if ((1 << j) & i) {
				cnt_bits++;
			}
		}
		if (cnt_bits == bitsCnt) {
				cnt++;
		}
	}
	return cnt;
}

double NMath::ComputeMathFormula(const double arg) {
	return std::abs((std::sin(arg) / 2.0 + std::cos(arg)) * (std::sin(arg) / 2.0 + std::cos(arg)) + std::tan(arg) * std::atan(arg));
}

bool NMath::IsPositive(int arg) {
	return arg > 0;
}

int NRecursion::CalculateFibonacci(const int arg) {
	int f1 = 1, f2 = 1;
	for (int i = 3; i <= arg; ++i) {
		int sm = f1 + f2;
		f1 = f2;
		f2 = sm;
	}
	return f2;
}
