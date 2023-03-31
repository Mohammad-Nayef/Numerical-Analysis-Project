#include <iostream>
#include <cmath>
using namespace std;

//This is the given function f(x)
double f(double x) {
	return (pow(x, 3) + cbrt(x) - 1) / (2 - x);
}

int main() {
	// (a) is the first guess, (b) is the second guess,
	// (c) is the bisector, (E) is the tolerance
	double a = 0, b = 1, c, E = 0.001, iterations = 0;

	while (f(a) * f(b) < 0) {
		iterations++;

		c = (a + b) / 2;

		if (fabs(f(c)) < E)
			break;

		if (f(a) * f(c) < 0)
			b = c;

		else a = c;
	}

	cout << "Number of iterations = " << iterations << endl;
	cout << "The solution c = " << c << endl;
}
