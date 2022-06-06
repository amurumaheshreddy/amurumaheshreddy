#include <iostream>
#define SIZE 100
using namespace std;
int main()
{
  int matrix[SIZE][SIZE];
  int m,n;
  int sum_left =0, sum_right = 0;
    cout<<"\n 2D array of size: ";
    cin>>n;
    
   cout<<"\nEnter all the values between 0-10"<<endl;
  //Taking input into the Matrix and 
  //Adding if they are diagonal elements
  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
      cin >> matrix[i][j];
      if(i==j)
        sum_left += matrix[i][j];
      if((i+j) == SIZE-1)
        sum_right += matrix[i][j];
    }
  }
  cout << "Sum of Left Diagonal: "<< sum_left << endl;
  cout << "Sum of Right Diagonal: "<< sum_right << endl;
  return 0;
}