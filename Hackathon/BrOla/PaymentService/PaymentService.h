#ifndef PAYMENT_SERVICE_H
#define PAYMENT_SERVICE_H
#include<bits/stdc++.h>
using namespace std;
class PaymentService{
    public:
    string phoneNumber;
    double amount;
    PaymentService(string phoneNumber,double amount){
        this->phoneNumber=phoneNumber;
        this->amount=amount;
    }
    virtual bool pay()=0;
};
#endif