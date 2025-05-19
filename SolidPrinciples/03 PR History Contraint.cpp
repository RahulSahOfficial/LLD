#include<bits/stdc++.h>
using namespace std;
class Account{
    protected:
    int balance;
    public:
    Account(int newBalance){
        balance=newBalance;
    }
    // Withdraw should only decrease the balance
    virtual int withdraw(int amount){
        balance-=amount;
    }
    int getBalance(){
        return balance;
    }
};
class CheatAccount:public Account{
    public:
    CheatAccount(int newBalance):Account(newBalance){
        balance=newBalance;
    }
    // Breaking History constraint as withdraw is increasing the balance
    int withdraw(int amount) override {
        balance+=amount;
    }
};
int main(){
    Account *newAcc=new CheatAccount(200);
    try{
        newAcc->withdraw(700);
    }
    catch (exception &e){
        cout<<e.what()<<endl;
    }
    cout<<"Balance : "<<newAcc->getBalance()<<endl;
    return 0;
}