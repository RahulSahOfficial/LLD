#include<bits/stdc++.h>
using namespace std;
class User{
    public:
    string password;
    // PreCondition Password Length >=8
    virtual void setPassword(string password){
        if(password.length()<8)
            throw runtime_error("Password cannot be less than 8 characters");
        this->password=password;
        cout<<"User Password Set!"<<endl;
    }
};
class Admin:public User{
    public:
    string password;
    // PreCondition Password Length >=6
    void setPassword(string password) override {
        if(password.length()<6)
            throw runtime_error("Password cannot be less than 8 characters");
        this->password=password;
        cout<<"Admin Password Set!"<<endl;
    }
};
int main(){
    try{
        User *u=new User();
        u->setPassword("12345678");
        User *a=new Admin();
        a->setPassword("123456");

    }
    catch (exception &e){
        cout<<e.what()<<endl;
    }

    return 0;
}