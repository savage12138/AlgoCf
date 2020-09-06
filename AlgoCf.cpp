/*
	Author: Yida Wang
	Last Date Modified: January 27th, 2020
	Description:
	This program will implement and analyze 
	two different code segments for initializing 
	an [NxN] matrix (indexed as A[0][0] to A[N-1][N-1]).
	Compute the actual running times for matrices of various sizes.
*/

#include <iostream>
#include <stdio.h>      
#include <time.h>       
using namespace std;

int main()
{
	// variable declaration
	int row = 0;
	int col = 0;
	int k = 0;
	int testCases = 10000;
	int N = 0;
	float T;

	// set number precision
	cout.precision(10);

	// user input
	cout << " Enter the size of matrix:";
	cin >> N;
	cout << " For a " << N << "x" << N << " matrix" << endl;

	// initalize matrix NxN
	float** A = new float*[N];
	for (int row = 0; row < N; row++)
	{
		A[row] = new float[N];
	}

	// Code Option A
	// initialize clock for Option A;
	clock_t s;
	s = clock();
	for (k = 0; k < testCases; k++)
	{
		float value = 0.5;
		for (row = 0; row < N; row++)
		{
			for (col = 0; col < N; col++)
			{
				A[row][col] = value;
				value = value + 1.0;
			}
		}
		for (row = 0; row < N; row++)
		{
			A[row][row] = 0.0;
		}
	}

	// compute execution time for Option A
	s = clock() - s;
	T = ((float)s / CLOCKS_PER_SEC) / testCases;
	cout << fixed;
	cout << " Execution time for Code Option A took " << T << " seconds." << endl;

	// Code Option B
	// initialize clock for Option B;
	clock_t t;
	t = clock();
	for (k = 0; k < testCases; k++)
	{
		for (row = 0; row < N; row++)
		{
			for (col = 0; col < N; col++)
			{
				if (row == col)
				{
					A[row][col] = 0.0;
				}
				else
				{
					A[row][col] = (float)((N * row) + col) + 0.5;
				}
			}
		}
	}

	// compute execution time for Option B
	t = clock() - t;
	T = ((float)t / CLOCKS_PER_SEC)/testCases;
	cout << fixed;
	cout << " Execution time for Code Option B took " << T << " seconds." << endl;

	// delete pointer to free heap
	delete [] A;
}