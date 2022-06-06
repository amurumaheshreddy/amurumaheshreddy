#include <iostream>
using namespace std;

//member function of matrix class
class matrix{

public:


matrix();
matrix(int m,int n);

int getRow();
int getCol();

double& operator()(int, int);

//the operator used in the matrix class which are (addition operator, multiplication operator,substraction operator, and divide operator).
friend ostream& operator<<(ostream& os, matrix& m);
matrix operator + (matrix&);
matrix operator * (matrix&);
matrix operator - (matrix&);
matrix operator / (matrix&);

private:
void init(int, int);
int nrows,ncols;
double *data;
};

matrix::matrix(){
init(1,1);
}

matrix::matrix(int m, int n){
init(m,n);
}

//destructor to delete the used dynamic memory.
void matrix::init(int m, int n){
nrows=m;
ncols=n;
data= new double[m*n];
for(int i=0; i<m*n; i++)
data[i]=0;
}

int matrix::getRow() { return nrows;}

int matrix::getCol() { return ncols;}

double& matrix::operator ()(int r, int c){
if (r <0 || r> nrows){
cout<<"Illegal row index";
return data[0];
}
else if (c <0 || c > ncols){
cout<<"Illegal Column Index:";
return data[0];
}
else return data[r*ncols+c];
}


ostream& operator<<(ostream& os, matrix &m){
int mval=m.getRow();
int nval=m.getCol();
for(int i=0; i<mval; i++){
for(int j=0; j < nval; j++)
os<<m(i,j)<<" ";
os<<endl;
}
return os;
}

//To compute the summation
matrix matrix::operator+(matrix& a){
matrix sum(nrows, ncols);
for (int i=0; i<nrows; i++)
for(int j=0; j<ncols; j++)
sum(i,j) = (i,j) + a(i,j);
return sum;
}
//To compute the multiplication
matrix matrix::operator*(matrix& a){
matrix product(nrows, ncols);
for (int i=0; i<nrows; i++)
for(int j=0; j<ncols; j++)
product(i,j) = (i,j) * a(i,j);
return product;
}

//To compute the substraction
matrix matrix::operator-(matrix& a){
matrix difference(nrows, ncols);
for (int i=0; i<nrows; i++)
for(int j=0; j<ncols; j++)
difference(i,j) = (i,j) - a(i,j);
return difference;
}

//To compute the division
matrix matrix::operator/(matrix& a){
matrix divide(nrows, ncols);
for (int i=0; i<nrows; i++)
for(int j=0; j<ncols; j++)
divide(i,j) = (i,j) / a(i,j);
return divide;
}


int main(){

//the array of matrix a
matrix a(2,2);
a(1,1)=5.0;
a(0,0)=6.0;
a(0,1)=7.0;
a(1,0)=8.0;


cout<<"matrix a\n";
cout<<a<<endl;

//the array of matrix b
matrix b(2,2);
b(0,0) = 5.0;
b(0,1) = 5.0;
b(1,0) = 5.0;
b(1,1) = 5.0;
cout<<"matrix b\n";
cout<<b<<endl;

matrix c,d,e,f;

//to compute the operation of the matrix (addition, multiplication, substraction and division).
c=a+b;
d=a*b;
e=a-b;
f=a/b;


//to Display the result operation of the matrix (addition, multiplication, substraction and division).
cout<<"matrix a+b \n";
cout<<c<<endl;
cout <<"\n\n";
cout<<"matrix a*b\n";
cout<<d<<endl;
cout<<"matrix a-b\n";
cout<<e<<endl;
cout <<"\n\n";
cout<<"matrix a/b\n";
cout<<f<<endl;


system("pause");
return 0;
}