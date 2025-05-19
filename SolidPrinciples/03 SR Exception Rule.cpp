#include<bits/stdc++.h>
using namespace std;
class LowBalance:public runtime_error{
    public:
    LowBalance():runtime_error("Low Balance"){};
};
class Parent{
    public:
    virtual void withdraw (int balance,int amt){
        if(amt>balance)
            throw runtime_error("Runtime Error");
        else
            cout<<"Can Withdraw!"<<endl;
    }
};
class Child:public Parent{
    public:
    void withdraw (int balance,int amt) override{
        if(amt>balance)
            throw LowBalance();
        else
            cout<<"Can Withdraw!"<<endl;
    }
};
int main(){
    Parent *obj=new Child();
    try{
        obj->withdraw(300,500);
    }
    catch(runtime_error &e){
        cout<<e.what();
    }
    return 0;
}