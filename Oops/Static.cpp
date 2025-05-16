#include<bits/stdc++.h>
using namespace std;
class Customer{
    int accNo;
    int balance;
    
    public:
    static int customerCnt;
    static int totalBalance;
    Customer(const int accNo,const int balance){
        this->accNo=accNo;
        this->balance=balance;
        customerCnt++;
        totalBalance+=balance;
    }
    void add(int amt) const{
        cout<<"Called add"<<endl;
    }
    ~Customer(){
        customerCnt--;
        totalBalance-=this->balance;
        cout<<customerCnt<<" "<<totalBalance<<endl;
    }
};
int Customer::customerCnt=0;
int Customer::totalBalance=0;
int main(){
    const Customer c1(123,500),c2(234,7888);
    c1.add(50);
    cout<<Customer::customerCnt<<endl;
    cout<<Customer::totalBalance<<endl;
    Customer c3(879,800);
    cout<<Customer::customerCnt<<endl;
    cout<<Customer::totalBalance<<endl;
    return 0;
}