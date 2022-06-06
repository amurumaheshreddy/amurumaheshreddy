#include<stdio.h>
#include<string.h>
#include<conio.h>          // comment this if u r using linux.
struct bankinfo{
int acno;
char name[30];
int balance;
}data[200];
void printballes100(struct bankinfo d[],int);
int main()

{
int i,p,acno,money,n;
char name[30];
int balance;
printf("Enter No. of customers");
scanf("%d",&n);
printf("Enter Customer Details:");
for(int i=0;i<n;i++)
{
      scanf("%d",&acno);
      scanf("%c",&name);
      scanf("%d",&balance);

data[i].acno = acno;
strcpy(data[i].name,name);
data[i].balance = balance;
}
printballes100(data,5);

printf("\n Enter your choice 1. for deposit 0. for withdrawl :");
scanf("%d",&p);
printf("\n enter a/c no :");
scanf("%d",&acno);
printf("\n enter money for transaction:");
scanf("%d",&money);
if(p==1)
{
for(i=0; i<5; i++)
{
if(data[i].acno == acno)
{
data[i].balance+=money;
printf("\nMoney Deposited to %d account",acno);
}
}
}
else if (p==0)
{
for(i=0; i<5; i++)
{
if(data[i].acno == acno)
if(data[i].balance<100)
printf("\n The Balance is insufficient for specified withdrawl");
}
}
                    // comment this if u r using linux.
return 0;
}

void printballes100(struct bankinfo d[],int size)
{
int i;
printf("\n Accounts having balances less than 100 are \n");
printf("\na/c no \t name \t balance \n");
for(i=0; i<size; i++)
if(d[i].balance<100)
printf("%d \t %s \t %d \n",d[i].acno,d[i].name,d[i].balance);
}