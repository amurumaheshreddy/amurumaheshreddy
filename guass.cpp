// C++ Implementation for Gauss-Jordan
// Elimination Method
#include <bits/stdc++.h>
using namespace std;
#define M 3
// Function to print the matrix
void PrintMat(float a[][M], int n)
{
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= n; j++)
		cout << a[i][j] << " ";
		cout << endl;
	}
}

// function to reduce matrix to reduced
// row echelon form.
int Operation(float a[][M], int n)
{
	int i, j, k = 0, c, flag = 0, m = 0;
	float pro = 0;
	
	// Performing elementary operations
	for (i = 0; i < n; i++)
	{
		if (a[i][i] == 0)
		{
			c = 1;
			while ((i + c) < n && a[i + c][i] == 0)
				c++;		
			if ((i + c) == n) {
				flag = 1;
				break;
			}
			for (j = i, k = 0; k <= n; k++)
				swap(a[j][k], a[j+c][k]);
		}

		for (j = 0; j < n; j++) {
			
			// Excluding all i == j
			if (i != j) {
				
				// Converting Matrix to reduced row
				// echelon form(diagonal matrix)
				float pro = a[j][i] / a[i][i];

				for (k = 0; k <= n; k++)				
					a[j][k] = a[j][k] - (a[i][k]) * pro;			
			}
		}
	}
	return flag;
}

// Function to print the desired result
// if unique solutions exists, otherwise
// prints no solution or infinite solutions
// depending upon the input given.
void PrintResult(float a[][M], int n, int flag)
{
	cout << "Result is : ";

	if (flag == 2)	
	cout << "Infinite Solutions Exists" << endl;
	else if (flag == 3)	
	cout << "No Solution Exists" << endl;
	
	
	// Printing the solution by dividing constants by
	// their respective diagonal elements
	else {
		for (int i = 0; i < n; i++)		
			cout << a[i][n] / a[i][i] << " ";	
	}
}

// To check whether infinite solutions
// exists or no solution exists
int Consistency(float a[][M], int n, int flag)
{
	int i, j;
	float sum;
	
	// flag == 2 for infinite solution
	// flag == 3 for No solution
	flag = 3;
	for (i = 0; i < n; i++)
	{
		sum = 0;
		for (j = 0; j < n; j++)	
			sum = sum + a[i][j];
		if (sum == a[i][j])
			flag = 2;	
	}
	return flag;
}

// Driver code
int main()
{  
int a[M][M];

cout << "Enter the augmented matrix: " << endl;
for (int i = 0; i < M; i++)
{
for (int j = 0; j < M; j++)
{
cin >> a[i][j];
}
}
	// Order of Matrix(n)
	int n = 3, flag = 0;
	
	// Performing Matrix transformation
	flag = Operation(a, n);
	
	if (flag == 1)	
		flag = Consistency(a, n, flag);

	// Printing Final Matrix
	cout << "Final Augmented Matrix is : " << endl;
	PrintMat(a, n);
	cout << endl;
	
	// Printing Solutions(if exist)
	PrintResult(a, n, flag);

	return 0;
}
