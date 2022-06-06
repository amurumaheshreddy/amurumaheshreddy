// include libraries
#include <iostream>
#include <array>
using namespace std;

// Main Function Program start from here
int main()
{   
    // define array of size 10
    array<int,10> arr{};
    
    //int variable for input and conition
    int n,x;
    cout<<"Enter 10 Integers between 10 and 100 :\n";
    
    //loop for input array from user
    for(int i=0;i<10;i++)
    {   
        // input array element
        cout<<"Enter a number :";
        cin>>n;
        
        //check if entered number is less than 10 than give error
        if(n<10)
        {
            cout<<"Invalid Number. Please enter a number between 10 and 100.\n\n";
            i--;
        }
        
        //else check the value is duplicate or not
        else
        {
        for(int j=0;j<=i;j++)
        {   
            //if value is duplicate than give error
            if(arr[j]==n)
            {
                cout<<"Duplicate Number.\n\n";
                x=1;
                break;
            }
            else
            {
                x=0;
            }
        }
        
        // enter data to array
        if(x==0)
        arr[i]=n;
        }
    }
    
    // print array 
    cout<<"\nThe nonduplicates Value are:\n";
    for(int i=0;i<10;i++)
    {   
        // duplicate values is enteres as 0 so skip that
        if(arr[i]>0)
        cout<<arr[i]<<" ";
    }

    return 0;
}