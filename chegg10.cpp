#include <iostream>
#include <fstream>
using namespace std;
//function to calculate average
void calculate(float &p,float &q,float &r,float a[],float b[],float c[],int x,int y,int z)
{
    int s1=0,s2=0,s3=0;
    for(int i=0;i<x;i++)
    s1 += a[i];
    for(int i=0;i<y;i++)
    s2 += b[i];
    for(int i=0;i<z;i++)
    s3 += c[i];

    p = ((float)s1/(x*20))*100.0;
    q = ((float)s2/(y*10))*100.0;
    r = ((float)s3/(x*20))*100.0;
}
//driver function
int main()
{
    float labs[10],quiz[10],assignment[10];
    float practice,mid_marks,final_marks;
    ifstream f("marks.txt");
    char c;
    float marks;
    int x=0,y=0,z=0;
    while(f>>c>>marks)
    {
        if(c=='L')
        {
            labs[x] = marks;
            x++;
        }
        else if(c=='Q')
        {
            quiz[y] = marks;
            y++;
        }
        else if(c=='A')
        {
            assignment[z] = marks;
            z++;
        }
        else if(c=='P')
        practice = marks;
        else
        mid_marks = marks;

    }
    f.close();
    labs[x] = practice/5.0;
    float av1,av2,av3;
    calculate(av1,av2,av3,labs,quiz,assignment,x,y,z);
    cout<<"Enter a grade for the final: ";
    cin>>final_marks;
    cout<<"Labs : "<<av1<<"\n";
    cout<<"Quizzes : "<<av2<<"\n";
    cout<<"Assignments : "<<av3<<"\n";
    cout<<"Midterm exam  : "<<mid_marks<<"\n";
    cout<<"Final exam  : "<<final_marks<<"\n";
    av1 = av1*.10;
    av2 = av2*.05;
    av3 = av3*.10;
    mid_marks = mid_marks*.35;
    final_marks = final_marks*.40;
     float current_grade = av1 + av2 + av3 + mid_marks + final_marks;
     cout<<"Current grade : "<<current_grade<<"\n";
}
