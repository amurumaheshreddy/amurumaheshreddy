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
printf("Enter No. of customers: ");
scanf("%d",&n);
printf("Enter Customer Details: ");
for(int i=0;i<n;i++)
{
      scanf("%d",&acno);
        scanf("%s",name);
      scanf("%d",&balance);

data[i].acno = acno;
strcpy(data[i].name,name);
data[i].balance = balance;
}
printf("\n Enter your account number :");
scanf("%d",&acno);
printf("\n Enter  1. for deposit 0. for withdrawl :");
scanf("%d",&p);
printf("\n Enter amount to withdraw :");
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
printf("\n The balance is insufficient for specified withdrawl");
}
}
printballes100(data,n);
                    // comment this if u r using linux.
return 0;
}

void printballes100(struct bankinfo d[],int size)
{
int i;
printf("\n All members with account balances less than 100 are the following \n");

for(i=0; i<size; i++)

if(d[i].balance<100)
printf("Name: %s \n Account Number: %d \n",d[i].name,d[i].acno);
}
