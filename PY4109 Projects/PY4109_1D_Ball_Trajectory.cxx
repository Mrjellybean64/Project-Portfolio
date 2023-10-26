/* 
User enters initial values, final time and number of plot 
points, and the program creates the plot of the trajectory of the
ball and finds it maximal height (in 1 dimension)
*/

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

const double g = 9.81;
const int t_0 = 0;
double t_f, dt, v_0, x_0, x_m; // Initial conditions, final time and time step
int N; // Number of plot points

int main ()
{

cout << "Please enter the number of plot points N: ";
cin >> N;
cout << "Please enter the initial position x_0: ";
cin >> x_0;
cout << "Please enter the initial velocity v_0: ";
cin >> v_0;
cout << "Please enter the final time t_f: ";
cin >> t_f;

dt = t_f / (N-1); // Timestep created
double x[N]; // Position
double t[N]; // Time
x[0] = x_0;
x_m = x_0 + (1.0/2.0) * v_0 * (v_0 / g); // This can be proven analytically
cout << "\nThe maximum height of the projectile is: " << x_m << "\n\n";

for (int i = 0; i < N; i++)
{
	t[i] = i * dt; // Time increases in steps of dt
	x[i] = x_0 + (v_0 * t[i]) - ((1.0/2.0) * g * t[i] * t[i]); // Formula for x(t)
}

// Gnuplot is a program that generates plots of data sets
gnuplot_one_function ("Position versus Time","linespoints", "Time", "Position", t, x, N);

return 0;
}
