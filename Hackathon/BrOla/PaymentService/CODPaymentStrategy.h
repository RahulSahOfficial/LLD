#ifndef COD_PAYMENT_STRATEGY_H
#define COD_PAYMENT_STRATEGY_H
#include<bits/stdc++.h>
#include "./PaymentService.h"
#include "../NotificationService/NotificationService.h"
using namespace std;
class CODPaymentStrategy:public PaymentService{
    public:
    CODPaymentStrategy(string phoneNumber,double amount):PaymentService(phoneNumber,amount){};
    bool pay() override{
        // Processed Payment Here..
        NotificationService::sendCODPaymentStatus(phoneNumber,amount,NotificationType::SMS);
        return true;
    }
};
#endif