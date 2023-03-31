#include <iostream>
#include <cmath>
using namespace std;

//This is the given function f(x)
double f(double x) {
	return (pow(x, 3) + cbrt(x) - 1) / (2 - x);
}

//This is the derivative of the funciton f(x)
double fPrime(double x) {
	return ((3 * pow(x, 2) + 1.0 / 3.0 * pow(x, -2.0 / 3.0)) * (2 - x)
		+ pow(x, 3) + cbrt(x) - 1) / pow((2 - x), 2);
}

int main() {
	// (E) is the tolerance, P is the current answer (Pn)
	// previousP is the previous answer (Pn-1)
	double E = 0.001, P = 0.5, previousP, iterations = 0;

	while (fabs(f(P)) > E) { // |f(P)| > E ?
		iterations++;
		previousP = P;

		P = previousP - f(previousP) / fPrime(previousP);
	}

	cout << "Number of iterations = " << iterations << endl;
	cout << "The solution P = " << P << endl;
}
