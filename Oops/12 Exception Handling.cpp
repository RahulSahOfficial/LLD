#include<bits/stdc++.h>
using namespace std;
class InvalidAmountError: public runtime_error{
    public:
    InvalidAmountError():runtime_error("Insufficient Fund !!"){};
};
class Customer{
    string name;
    int accountNumber;
    double accountBalance;
    bool isActive;
    public:
    Customer(const string name,const int accountNumber): accountNumber(accountNumber),name(name),accountBalance(0),isActive(true){
        cout<<"Constructor"<<endl;
    }
    void deposit(double amount){
        this->accountBalance+=amount;
    }
    bool withdraw(double amount){
        if(this->accountBalance<amount){
            throw InvalidAmountError();
            // cout<<"Insufficient Fund !!"<<endl;
            return false;
        }
        this->accountBalance-=amount;
        return true;
    }
    bool transfer(double amount,Customer &receipient){
        if(this->accountBalance<amount){
            throw InvalidAmountError();
            // cout<<"Insufficient Fund !!"<<endl;
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
    ~Customer(){
        cout<<"Destructor"<<endl;
    }
};
int main(){
    Customer c1("Sah",123),c2("Dwivedi",234);
    try{
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
    }
    catch (const InvalidAmountError &e){
        cout<<"Error -  "<<e.what()<<endl;
    }
    return 0;
}
// 
// int main(){
//     int a,b;
//     cin>>a>>b;
//     try {
//     throw std::runtime_error("Runtime error!");
// } catch (const std::exception& e) {
//     std::cout << "Caught an exception of type std::exception: " << e.what() << std::endl;
// } catch (const std::runtime_error& e) {
//     std::cout << "Caught a runtime_error: " << e.what() << std::endl;
// } catch (const std::exception& e) {
//     std::cout << "This will not be executed." << std::endl;
// }

//     return 0;
// }