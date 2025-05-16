#include<bits/stdc++.h>
using namespace std;
class NonWithdrawableAccount{
    public:
    int accNo;
    int balance;
    static int totalAccount;
    NonWithdrawableAccount(){
        totalAccount++;
        accNo=totalAccount;
        balance=0;
    }
    void display(){
        cout<<accNo<<" "<<balance<<endl<<endl;
    }
    virtual void deposit(int)=0;
};
class WithdrawableAccount : public NonWithdrawableAccount{
    public:
    virtual void withdraw(int)=0;
};
class SavingAccount:public WithdrawableAccount{
    public:
    void deposit(int amt){
        balance+=amt;
        cout<<"Deposit"<<endl;
        display();
    }
    void withdraw(int amt){
        balance-=amt;
        cout<<"Withdraw"<<endl;
        display();
    }
    void display(){
        cout<<"Saving Account"<<endl;
        WithdrawableAccount::display();
    }
};
class CurrentAccount:public WithdrawableAccount{
    public:
    void deposit(int amt){
        balance+=amt;
        cout<<"Deposit"<<endl;
        display();
    }
    void withdraw(int amt){
        balance-=amt;
        cout<<"Withdraw"<<endl;
        display();
    }
    void display(){
        cout<<"Current Account"<<endl;
        WithdrawableAccount::display();
    }
};
class FDAccount:public NonWithdrawableAccount{
    public:
    void deposit(int amt){
        balance+=amt;
        cout<<"Deposit Done"<<endl;
        display();
    }
    void display(){
        cout<<"FD Account"<<endl;
        NonWithdrawableAccount::display();
    }
};
int NonWithdrawableAccount::totalAccount=0;
int main(){
    vector<WithdrawableAccount *> withdrawableAccounts;
    vector<NonWithdrawableAccount *> nonWithdrawableAccounts;
    withdrawableAccounts.push_back(new SavingAccount());
    withdrawableAccounts.push_back(new CurrentAccount());
    withdrawableAccounts.push_back(new SavingAccount());
    nonWithdrawableAccounts.push_back(new FDAccount());
    nonWithdrawableAccounts.push_back(new FDAccount());
    for(auto each:withdrawableAccounts){
        each->deposit(1000);
        each->withdraw(500);
    }
    for(auto each:nonWithdrawableAccounts){
        each->deposit(1000);
    }

    return 0;
}