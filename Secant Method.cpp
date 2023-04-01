#include <iostream>
#include <cmath>
using namespace std;

//This is the given function f(x)
double f(double x) {
	return (pow(x, 3) + cbrt(x) - 1) / (2 - x);
}

int main() {
	// (E) is the tolerance, P is the current answer (Pn)
	// P0 and P1 are the first two values of P
	double E = 0.001, P, P0 = 0.5, P1 = 0.75, iterations = 0;

	do {
		iterations++;

		// P0 is considered as Pn-2 and P1 as Pn-1
		P = P1 - (f(P1) * (P1 - P0)) / (f(P1) - f(P0));

		// Update the values of P0 and P1
		P0 = P1;
		P1 = P;

	} while (fabs(f(P)) > E); // |f(P)| > E ?

	cout << "Number of iterations = " << iterations << endl;
	cout << "The solution P = " << P << endl;
}