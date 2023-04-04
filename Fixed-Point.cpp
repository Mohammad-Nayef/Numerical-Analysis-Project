#include <iostream>
#include <cmath>
using namespace std;

//This is the given function f(x)
double f(double x) {
	return (pow(x, 3) + cbrt(x) - 1) / (2 - x);
}

double g(double x) {
	return cbrt(1 - cbrt(x));
}

int main() {
	// (E) is the tolerance, P is the current answer (Pn)
	double E = 0.001, P = 0.5, iterations = 0;

	while (fabs(P - g(P)) > E) { // |P - g(P)| > E ?
		iterations++;

		P = g(P);
	}

	cout << "Number of iterations = " << iterations << endl;
	cout << "The solution P = " << P << endl;
}
