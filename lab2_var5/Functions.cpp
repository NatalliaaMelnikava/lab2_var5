#include "Library.h"

double func1(const double & x1, const double & x2) {
	return(pow(x1, 3) + pow(x2, 3) - 6 * x1 + 3);
}

double func2(const double &x1, const double &x2) {
	return(pow(x1, 3) - pow(x2, 3) - 6 * x2 + 2);
}

void Jakobian(vector<double>& x,vector<vector<double>>&Jak) {
	Jak[0][0] = pow(x[0], 2) * 3 - 6;
	Jak[0][1] = pow(x[1], 2) * 3;
	Jak[1][0] = pow(x[0], 2) * 3;
	Jak[1][1] = -3 * pow(x[1], 2) - 6;
	//Jak = { {Jak11,Jak12},{Jak21,Jak22} };
}

void Jakob2method(const vector<double>& x, vector<vector<double>>& Jak,const double M) {
	Jak[0][0] = (func1(x[0] + x[0] * M, x[1]) - func1(x[0], x[1])) / M * x[0];
	Jak[0][1] = (func1(x[0], x[1] + x[1] * M) - func1(x[0], x[1])) / M * x[1];
	Jak[1][0] = (func2(x[0] + x[0] * M, x[1]) - func2(x[0], x[1])) / M * x[0];
	Jak[1][1] = (func2(x[0], x[1] + x[1] * M) - func2(x[0], x[1])) / M * x[1];
}

double delta1(vector<double>& x) {
	double max1=fabs(func1(x[0], x[1]));
	double max2 = fabs(func2(x[0], x[1]));
	if (max1 > max2) {
		return max1;
	}
	else
		return max2;
}

double delta2(const vector<double>& x,const vector<double>& x_k){
	double m = 0;
	for (int i = 0; i < x.size(); i++) {
		if (fabs(x_k[i]) < 1) {
			if (fabs(x_k[i] - x[i]) > m) {
				m = fabs(x_k[i] - x[i]);
			}
		}
		else {
			if (fabs((x_k[i] - x[i]) / x_k[i]) > m) {
				m = fabs((x_k[i] - x[i]) / x_k[i]);
			}
		}
	}
	return m;
}