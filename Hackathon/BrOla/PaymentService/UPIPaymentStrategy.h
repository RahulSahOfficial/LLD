#ifndef UPI_PAYMENT_STRATEGY
#define UPI_PAYMENT_STRATEGY
#include<bits/stdc++.h>
#include "../Types.h"
#include "./PaymentStrategy.h"
#include "../NotificationService/SMSNotification.h"
using namespace std;
class UPIPaymentStrategy:public PaymentStrategy{
    public:
    UPIPaymentStrategy(string phoneNumber,double amount):PaymentStrategy(phoneNumber,amount){};
    bool pay() override{
        cout<<"Amount "<<amount<<" Paid via UPI "<<phoneNumber<<endl;
        NotificationService *notificationService=new SMSNotification(phoneNumber,"Amount "+to_string(amount)+"paid via UPI");
        notificationService->notify();
        return true;
    }
};
#endif