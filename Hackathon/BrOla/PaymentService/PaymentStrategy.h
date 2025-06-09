#ifndef PAYMENT_STRATEGY_H
#define PAYMENT_STRATEGY_H
#include<bits/stdc++.h>
using namespace std;
class PaymentStrategy{
    public:
    string phoneNumber;
    double amount;
    PaymentStrategy(string phoneNumber,double amount){
        this->phoneNumber=phoneNumber;
        this->amount=amount;
    }
    virtual bool pay()=0;
};
#endif