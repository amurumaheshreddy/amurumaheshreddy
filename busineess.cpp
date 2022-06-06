#include <iostream>
#include <iomanip>

using namespace std;


int channel_count()
{
    int preChannel;
    cout<<"Enter number of premium channels: ";
    cin>>preChannel;
    return preChannel;
}

double personal()
{
    int preChannel= channel_count();
    float cost;
    cost = 2.00 + 5.00 + (5.00 * preChannel);
    return cost;
}
double residential()
{
    int preChannel= channel_count();
    float cost;
    cost = 8.00 + 25.50 + (10.50 * preChannel);
    return cost;
    
}
double business()
{
    int preChannel= channel_count();
    float cost;
    cost = 20.00 + 30.00 + (25.50 * preChannel);
    return cost;
}

int main()
{
    char ch;
    int accNumber;
    double amount;
    cout<<"\n**************** Cable Bill Program ****************"<<endl;
    
    cout<<"Enter account number: ";
    cin>>accNumber;
    
    cout<<"Customer code: R or r (residentail), B or b (business) ";
    cin>>ch;
    
    if(ch=='R' || ch =='r')
    {
        ch = 'R';
        amount = residential();
    }
    else if(ch=='B' || ch == 'b')
    {
        ch = 'B';
        amount = business();
    }
    else if(ch=='P' || ch == 'p')
    {
        ch = 'P';
        amount = personal();
    }
    else
    {
        cout<<"Invalid choice";
    }

    cout<<"Account Number: "<<ch<<accNumber<<endl;
    cout<<"Amount due: $"<<fixed<<setprecision(2)<<amount<<endl;
    return 0;
}