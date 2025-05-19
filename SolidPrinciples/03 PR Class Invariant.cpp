#include<bits/stdc++.h>
using namespace std;
// Invariant : Balance Cannnot be negative 
class Account{
    protected:
    int balance;
    public:
    Account(int newBalance){
        balance=newBalance;
    }
    virtual int withdraw(int amount){
        if(balance<amount)
            throw runtime_error("Not Enough Balance");
        balance-=amount;
    }
    int getBalance(){
        return balance;
    }
};
//Breaking the invariant in derived class
class CheatAccount:public Account{
    public:
    CheatAccount(int newBalance):Account(newBalance){
        balance=newBalance;
    }
    int withdraw(int amount) override {
        balance-=amount;
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