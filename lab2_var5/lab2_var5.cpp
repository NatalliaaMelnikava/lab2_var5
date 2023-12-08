

#include "Library.h"

int main()
{
	vector<double>M = { 0,0.01,0.05,0.1 };
	double eps = 1e-9;
	vector<vector<double>> x;
	vector<double> x_k;
	x.push_back({ 1,1 });
	x.push_back({ 2,1.5 });
	x.push_back({ -3,-1.5 });

	for (int i = 0; i < M.size(); i++) {
		Neuton(x[2], M[i],eps,x_k);
		cout << "______________________________" << endl;
	}
}

