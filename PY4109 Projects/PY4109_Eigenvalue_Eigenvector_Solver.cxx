// This Program find eigenvalues and eigenvectors for a tridiagonal matrix

#include <iostream>
#include <string>
#include <stdio.h>
#include <unistd.h>
#include <math.h>
using namespace std;
#include <stdlib.h>
#include <stdarg.h>
#include <assert.h>
#include <complex.h>
#define complex _Complex
#include "gnuplot.cxx"
#include "num_recipes_tridiagonal.cxx"


const double pi = M_PI;

// Constants (max. size of matrix)
const int max_matrix = 10000;

// Input (will de distroyed during calculation of eigenvalues and eigenvectors)
double trimatrix_diag [max_matrix];
double trimatrix_subdiag [max_matrix];

// Output
double trimatrix_eigenvalue [max_matrix];
double trimatrix_eigenvector [max_matrix][max_matrix];

// only used during calculation of eigenvalues and eigenvectors
double trimatrix_result[max_matrix][max_matrix];
double* pointer_matrix [max_matrix];


// calculates eigenvalues and eigenvectors based on tqli funtion (num. recipes)
// (unsure how the tqli function works, just know how to implement it)

void eigenvalues_and_eigenvectors_tridiagonal_matrix (int nn)
{
	int n, m;
	for (n=0; n<nn; n++)
	{
		for (m=0; m<nn; m++)
		{
			if (n==m)
				trimatrix_result [n][m] = 1.0;
			else
				trimatrix_result [n][m] = 0.0;
		}
	}
	for (n=0; n<nn; n++)
		pointer_matrix [n] = &(trimatrix_result[n][0]);
	tqli (trimatrix_diag, trimatrix_subdiag, nn, pointer_matrix);
	for (n=0; n<nn; n++)
	{
		trimatrix_eigenvalue [n] = trimatrix_diag[n];
		for (m=0; m<nn; m++)
			trimatrix_eigenvector [n][m] = trimatrix_result[m][n];
	}
}


// Main Function: User enters double diagonal elements, eigenvalues
// and eigenvectors are computed


int main ()
{
	int nn, i, j;
	
	cout << "Please enter the size of the matrix: ";
	cin >> nn; // nn = number_steps
	
	cout << "Now enter the diagonal elements of that matrix ";
	for (i = 0; i < nn; i++)
	{
		cin >> trimatrix_diag [i];
	}
	for (i = 0; i < nn; i++)
	{
		trimatrix_subdiag [i] = 1.0; // Assigning subdiagonal values
	}
	
	eigenvalues_and_eigenvectors_tridiagonal_matrix (nn);
	
	for (i = 0; i < nn; i++)
	{
		cout << "Eigenvalue " << i + 1 << ": " << trimatrix_eigenvalue[i] << "\n";
		cout << "Corresponding eigenvector:\n";
		for (j = 0; j < nn; j++)
			cout << trimatrix_eigenvector [i][j] << "\n";
		cout << "\n";
	}
	
	return 0;
}
