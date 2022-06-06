#include <omp.h>
#include <iostream>
#define N 100
using namespace std;
int main(int argc, char *argv)
{
omp_set_num_threads(8); //set number of threads here
int i, j, k; 
double sum;
double start, end;  // used for timing
double A[N][N], B[N][N], C[N][N];
for (i = 0; i < N; i++)
{
for (j = 0; j < N; j++) 
{ 
A[i][j] = j*1;
B[i][j] = i*j+2;
C[i][j] = j-i*2; 
 }
}
start = omp_get_wtime(); //start time measurement
for (i = 0; i < N; i++)
{
for (j = 0; j < N; j++)
 { 
sum = 0;
for (k=0; k < N; k++)
{ 
sum += A[i][k]*B[k][j]; 
} 
C[i][j] = sum;
}
} 
end = omp_get_wtime(); //end time measurement
cout<<"Time of computation:" <<end-start<<" seconds\n";
return(0);
}