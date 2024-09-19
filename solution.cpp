#include "head.h"
#define EPS 1e-32

void solution(int n, double** a, double* b, double* x) {

	std::pair<double, double> fi;
	int k, j, i;
	double r;

	for (k = 0; k < n-1; k++) { //приводим k-й столбик
		r = abs(a[k][k]);

		for (j = k+1; j < n; j++) { //согласно лемме есть n-k матриц...
			r += abs(a[k][j]);
			if (r < EPS) continue; //тогда и поворачивать не нужно...

			fi = angle(a[k][k], a[k][j]);
			rotate(j, k, fi.first, fi.second, b);
			rotate_matrix(j, k, fi.first, fi.second, n, a);
		}
		//output(n, n, n, a);
	}

	for (i = n-2; i >= 0; i--) {
		x[i] = b[i];
		for ( j = i+1; j < n; j++) {
			x[i] -= a[j][i]*x[j];
		}
		if (abs(a[i][i])< EPS) throw MyException("solution.cpp::solution: division by zero error\n", EC_ZERO);
		x[i] = x[i]/a[i][i];
	}

	if (abs(a[n-1][n-1])< EPS) throw MyException("solution.cpp::solution: division by zero error\n", EC_ZERO);
	x[n-1] = b[n-1]/a[n-1][n-1];
}
