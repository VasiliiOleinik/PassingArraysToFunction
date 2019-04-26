// HelloFuncsArray.cpp: Passing arrays to a function
//

#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include <Windows.h>

using std::cin;
using std::cout;
using std::setw;

int rnd(int a, int b);
double rnd(double a, double b);

void init();

// One-dimensional arrays
// type NameF (..., type name [], ...); - function declaration
//
// When calling
// type name1 [Size]
// NameF (..., name1, ...);
//
// In function definition
// type NameF (..., type name [], ...)
// {
// ... ...
//)

void Fill(double z[], int n, double a = -12., double b = 23.);
void Show(double z[], int n, char s[] = "������ z:\n");
double Summa(double z[], int n);

// Declaration of functions
double MinLocMax(double z[], int n); // Array35
double MaxNormal(double z[], int n); // Array36

// Transfer Matrices
// type Namef (..., type name [] [N], int rows, ...);
//					! columns		! lines are arbitrary
// Transfer four-dimensional arrays
// type NameF (..., type name [] [] [] [N], int s0, int s1, int s2, ...);

const int M = 5;
const int NN = 7;
void Fill(double x[][NN], int m = M, double a = -12., double b = 23.);
void Show(double x[][NN], int m = M, char s[] = "������� x:\n");
double Summa(double x[][NN], int m = M);

void array();
void matrix();

int _tmain(int argc, _TCHAR *argv[])
{
	init(); // Preparation of the application for work

	array(); // processing of one-dimensional arrays

	matrix(); // matrix processing

	return 0;
} // _tmain

// Returns a random number of type int with a range of values from a to b
int rnd(int a, int b)
{
	return (a + rand() % (b - a + 1));
} // rnd

// Returns a random number of type double with a range of values from a to b
double rnd(double a, double b)
{
	return (a + (b - a) * rand() / (RAND_MAX + 1));
} // rnd

// Preparing the application for work
void init()
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	srand(GetTickCount());
} // init

// Work with one-dimensional arrays
void array()
{
	const int N = 8;
	double e[N];

	Fill(e, N);
	Show(e, N);

	double s;
	s = Summa(e, N);
	cout << "Sum of array elements: " << s << "\n";

	s = MinLocMax(e, N);
	cout << "Minimum of local maxima " << s << "\n";

	s = MaxNormal(e, N);
	cout << "Maximum of non-lok items. max / lok min: " << s << "\n";

	cout << "\n\n--------------------------------------------------\n\n";
} // array

// Work with multidimensional matrix arrays
void matrix()
{
	double z[M][NN];
	double s;

	Fill(z);
	Show(z, M);
	s = Summa(z);
	cout << "The sum of the elements of the matrix: " << s << "\n";
} // matrix

// Fill the array with random numbers
void Fill(double z[], int n, double a, double b)
{
	for (int i = 0; i < n; i++)
	{
		z[i] = rnd(a, b);
	} // for i
} // Fill

// Display array on screen
void Show(double z[], int n, char s[])
{
	cout << s;
	for (int i = 0; i < n; i++)
	{
		cout << setw(10) << z[i];
		if ((i + 1) % 7 == 0)
			cout << "\n";
	} // for i
	if (n % 7 != 0)
		cout << "\n";
} // Fill

// Sum of array elements
double Summa(double z[], int n)
{
	double sum = 0.;
	for (int i = 0; i < n; i++)
	{
		sum += z[i];
	} // for i

	return sum;
} // Summa

// Array 35 - minimum local maximum
double MinLocMax(double z[], int n)
{
	double minLocMax = DBL_MAX;

	for (int i = 1; i < n - 1; i++)
	{
		if (z[i] > z[i - 1] && z[i] > z[i + 1])
		{
			if (z[i] < minLocMax)
				minLocMax = z[i];
		} // if
	}	 // for

	return minLocMax;
} // MinLocMax

// Array 36 - the maximum of the elements that are not local
// maximum, no local minimum
double MaxNormal(double z[], int n)
{
	double maxNormal = z[0];

	for (int i = 1; i < n - 1; i++)
	{
		if ((z[i] > z[i - 1] && z[i] > z[i + 1]) ||
			(z[i] < z[i - 1] && z[i] < z[i + 1]))
			continue;
		if (z[i] > maxNormal)
			maxNormal = z[i];
	} // for
	if (z[n - 1] > maxNormal)
		maxNormal = z[n - 1];

	return maxNormal;
} // MinLocMax

// Filling the matrix with random numbers
void Fill(double x[][NN], int m, double a, double b)
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < NN; j++)
		{
			x[i][j] = rnd(a, b);
		} // for j
	}	 // for i
} // Fill

// Display the matrix on the screen
void Show(double x[][NN], int m, char s[])
{
	cout << s; // ����� ���������
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < NN; j++)
		{
			cout << setw(10) << x[i][j];
		} // for j
		cout << "\n";
	} // for i
	cout << "\n";
} // Show

// Summation of matrix elements
double Summa(double x[][NN], int m)
{
	double r = 0.;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < NN; j++)
		{
			r += x[i][j];
		} // for j
	}	 // for i

	return r;
} // Summa