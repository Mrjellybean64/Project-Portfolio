// This program is a Matrix-Vector multiplier

#include <iostream>
#include <string>
#include <stdio.h>
#include <unistd.h>
#include <math.h>
using namespace std;
#include <stdlib.h>
#include <stdarg.h>
#include <assert.h>
#include "gnuplot.cxx"

int n;

int main ()
{

cout << "Please enter a positive integer number n: ";
cin >> n;

// Defining n length vectors and nxn matrix
double vector[n];
double matrix[n][n];
double Mv_product[n]; // Solution vector

cout << "Now enter n vector elements: ";
for (int i = 0; i < n; i++)
{
	cin >> vector[i];
}

cout << "Now enter a nxn matrix 'M': ";
for (int j = 0; j < n; j++)
{
	for (int k = 0; k < n; k++) // Enter each row of numbers
	{
		cout << "\n" << "matrix element M_" << j+1 << "," << k+1 << ": ";
		cin >> matrix[j][k];
	}
}

for (int j = 0; j < n; j++)
{
	double x = 0; // Reset x for each row being multiplied
	for (int k = 0; k < n; k++)
	{
		x = x + matrix[j][k] * vector[k]; // Matrix - Vector multiplication
	}
	Mv_product[j] = x;
	cout << "\n" << Mv_product[j];
}

return 0;
}
