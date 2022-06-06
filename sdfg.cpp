#include<iostream>
#define SIZE 100
using namespace std;
 
int main()
{
int a[SIZE][SIZE],d1sum=0,d2sum=0,m,i,j;
 cout<<"\n 2D array of size: ";
cin>>m;
cout<<"\nEnter all the values between 0-10"<<endl;
for(i=0;i<m;i++)
for(j=0;j<m;++j)
cin>>a[i][j];
for(i=0;i<m;++i)
for(j=0;j<m;++j)
{
if(i==j)
d1sum+=a[i][j];
if(i+j==(m-1))
d2sum+=a[i][j];
}
cout << "Sum of Left Diagonal: "<< d1sum << endl;
  cout << "Sum of Right Diagonal: "<< d2sum << endl;
 
return 0;
}