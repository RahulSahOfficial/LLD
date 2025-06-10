#ifndef UPI_PAYMENT_STRATEGY
#define UPI_PAYMENT_STRATEGY
#include<bits/stdc++.h>
#include "./PaymentService.h"
#include "../NotificationService/NotificationService.h"
using namespace std;
class UPIPaymentStrategy:public PaymentService{
    public:
    UPIPaymentStrategy(string phoneNumber,double amount):PaymentService(phoneNumber,amount){};
    bool pay() override{
        //Proecessed Payment Here...
        NotificationService::sendUPIPaymentStatus(phoneNumber,amount,NotificationType::SMS);
        return true;
    }
};
#endif