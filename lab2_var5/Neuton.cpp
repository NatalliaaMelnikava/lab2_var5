#include "Library.h"

void Neuton(vector<double>&x,double M,double eps, vector<double>& x_k) {
	double del1;
	double del2;
	int k = 0;
	vector<vector<double>>Jak(2, vector<double>(2));
	x_k=x;
	vector<double> b(2);
	vector<double> dx(2);
	do {
		if (k >= 100) {
			cout << "IER = 2" << endl;
			break;
		}
		if (M == 0) {
			Jakobian(x, Jak);
		}
		else {
			Jakob2method(x, Jak, M);
		}
		b[0] = -func1(x[0], x[1]);
		b[1] = -func2(x[0], x[1]);
		dx = gauss(Jak, b);

		x_k[0] += dx[0];
		x_k[1] += dx[1];
		cout << "xd= " << dx[0] << dx[1] << endl;

		del1 = delta1(x);
		del2 = delta2(x, x_k);

		x = x_k;
		k++;
		cout << setprecision(8) << "del1 " << del1 << " del2 " << del2 << endl;
	} while (del1 >= eps || del2 >= eps);
	cout << setprecision(8) << "y= " << x[1] << " x=" << x[0] << " k= " << k <<" M="<<M << endl;
 }