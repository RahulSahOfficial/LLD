#ifndef COD_PAYMENT_STRATEGY_H
#define COD_PAYMENT_STRATEGY_H
#include<bits/stdc++.h>
#include "./PaymentStrategy.h"
#include "../NotificationService/SMSNotification.h"
using namespace std;
class CODPaymentStrategy:public PaymentStrategy{
    public:
    CODPaymentStrategy(string phoneNumber,double amount):PaymentStrategy(phoneNumber,amount){};
    bool pay() override{
        cout<<"Amount "<<amount<<" Paid via CASH "<<endl;
        NotificationService *notificationService=new SMSNotification(phoneNumber,"Amount "+to_string(amount)+" paid via COD");
        notificationService->notify();
        return true;
    }
};
#endif