#pragma once
#include <iostream>
#include <vector>
#include <math.h>
#include <iomanip>
using namespace std;

const double eps = 1e-9;
const int NIT = 2;

vector<double> gauss(vector<vector<double>>&, vector<double>&);
void Neuton(vector<double>&, double,double, vector<double>&);
double func1(const double&, const double&);
double func2(const double&, const double&);
void Jakobian(vector<double>&, vector<vector<double>>&);
double delta1(vector<double>&);
double delta2(const vector<double>&,const vector<double>&);
void Jakob2method(const vector<double>&, vector<vector<double>>&,const double);