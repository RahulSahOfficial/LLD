// 1. Bank Customer Class:
// Challenge: Design a Customer class for a bank system that manages customer information and basic operations.
// Attributes:
// name: String containing the customer's full name.
// accountNumber: Unique integer identifying the customer's account.
// accountBalance: Double representing the current balance in the account.
// isActive: Boolean indicating whether the account is active.
// Methods:
// deposit(amount): Adds the specified amount to the account balance.
// withdraw(amount): Deducts the specified amount from the account balance (check for sufficient funds).
// transfer(amount, targetAccount): Transfers the specified amount to another customer's account (within the system).
// printDetails(): Prints the customer's name, account number, and current balance.


#include<bits/stdc++.h>
using namespace std;
class Customer{
    string name;
    int accountNumber;
    double accountBalance;
    bool isActive;
    public:
    Customer(const string name,const int accountNumber): accountNumber(accountNumber),name(name),accountBalance(0),isActive(true){}
    void deposit(double amount){
        this->accountBalance+=amount;
    }
    bool withdraw(double amount){
        if(this->accountBalance<amount){
            cout<<"Insufficient Fund !!"<<endl;
            return false;
        }
        this->accountBalance-=amount;
        return true;
    }
    bool transfer(double amount,Customer &receipient){
        if(this->accountBalance<amount){
            cout<<"Insufficient Fund !!"<<endl;
            return false;
        }
        this->accountBalance-=amount;
        receipient.accountBalance+=amount;
        return true;
    }
    void printDetails(){
        cout<<"Customer Name : "<<this->name<<endl;
        cout<<"Account Number : "<<this->accountNumber<<endl;
        cout<<"Account Balance: "<<this->accountBalance<<endl;
        cout<<endl;
    }
};
int main(){
    Customer c1("Sah",123),c2("Dwivedi",234);
    c1.printDetails();
    c1.deposit(100);
    c1.printDetails();
    c1.withdraw(50);
    c1.printDetails();
    c1.withdraw(100);
    c1.printDetails();
    c1.deposit(5000);
    c1.transfer(500,c2);
    c1.printDetails();
    c2.printDetails();
    return 0;
}