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
	return max(lhs, rhs);
}

int NOverload::ProcessTwoArgs(int lhs, char rhs) {
	return lhs - rhs;
}

unsigned int NOverflow::WithOverflow(int lhs, int rhs) {
	return (unsigned int)lhs + (unsigned int)rhs;
}

uint64_t NOverflow::WithOverflow(int64_t lhs, int64_t rhs) {
	return (uint64_t) lhs - rhs;
}

int NLoop::SumInRange(const int lhs, const int rhs) {
	int sm = 0;
	for (int i = lhs; i < rhs; ++i) {
		sm += i;
	}
	return sm;
}

int NLoop::CountFixedBitsInRange(const int from, const int to, const int bitsCnt) {
}

double NMath::ComputeMathFormula(const double arg) {
}

bool NMath::IsPositive(int arg) {
}

int NRecursion::CalculateFibonacci(const int arg) {
}
