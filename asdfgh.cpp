#include <bits/stdc++.h>
using namespace std;
string cardNo = "856649548";
string password = "1234";
int main() {
    // Write C++ code here
    int balance = 2500;
    cout<<"………………………………………………………………………………………………\n";
    cout<<"NBO ATM System Simulator\n";
    cout<<"………………………………………………………………………………………………\n";
    while(true){
        string inputCardNo;
        cout<<"\nEnter Card No:";
        cin>>inputCardNo;
        if(cardNo == inputCardNo){
            break;
        }
        cout<<"Wrong Account No. Please try again...\n";
    }
    while(true){
        string inputPassword;
        cout<<"\nEnter Pin:";
        cin>>inputPassword;
        if(inputPassword == password){
            break;
        }
        cout<<"Wrong Pin. Please try again...";
    }
    while(true){
        cout<<"\nMain Menu Transactions"<<endl;
        cout<<"\n[1] Withdraw\n[2] Deposit\n[3] Balance\n[4] Exit\n";
        cout<<"______________________________________________________________________\n";
        cout<<"\nEnter your choice:1/2/3/4\n";
        int choice;
        cin>>choice;
        if(choice == 1){
            cout<<"Withdraw"<<endl;
            cout<<"………………………………………………………………………………………………\n";
            cout<<"Withdraw Transaction\n";
            cout<<"………………………………………………………………………………………………\n";
            cout<<"AVAILABLE BALANCE(OMR): "<<(int)balance<<endl;
            int amount;
            while(true){
                cout<<"Enter the amount\n";
                cin>>amount;
                if(amount > balance || amount <= 0){
                    cout<<"Enter correct amount...";
                }else{
                    break;
                }
            }
            balance -= amount;
            cout<<"Your remaining balance (OMR) is "<<balance<<endl;
            cout<<"|||||||||||||||||||||||||||||||||||||||\n";
            cout<<"PRINTING RECEIPT"<<endl;
            cout<<"|||||||||||||||||||||||||||||||||||||||\n";
            cout<<"ATM TRANSACTION RECORD"<<endl;
            time_t now = time(0);
            char* date_time = ctime(&now);
            cout<<"DATE: "<< date_time<<endl;
            cout<<"Location: MUSCAT"<<endl;
            cout<<"Transaction: Withdraw"<<endl;
            cout<<"Amount: "<<amount<<endl;
            cout<<"CURRENT BAL(OMR): "<<balance<<endl;
            cout<<"AVAILABLE BAL(OMR): "<<balance<<endl;
            cout<<"|||||||||||||||||||||||||||||||||||||||";
        }else if(choice == 2){
            cout<<"Deposit"<<endl;
            cout<<"………………………………………………………………………………………………\n";
            cout<<"Deposit Transaction\n";
            cout<<"………………………………………………………………………………………………\n";
            cout<<"CURRENT BAL(OMR): "<<balance<<endl;
            int amount;
             while(true){
                cout<<"Enter the amount\n";
                cin>>amount;
                if(amount <= 0){
                    cout<<"Enter correct amount...";
                }else{
                    break;
                }
            }
            balance += amount;
            cout<<"Your new available balance (OMR) is "<<balance<<endl;
        }else if(choice == 3){
            cout<<"Balance"<<endl;
            cout<<"………………………………………………………………………………………………\n";
            cout<<"Balance Transaction\n";
            cout<<"………………………………………………………………………………………………\n";
            cout<<"CURRENT BAL(OMR): "<<balance<<endl;
        }else if(choice == 4){
            cout<<"Thank you for visiting..."<<endl;
            break;
        }else{
            cout<<"Wrong Input. Please try again..."<<endl;
        }
    }
    return 0;
}