#ifndef PAYMENT_SERVICE_FACTORY_H
#define PAYMENT_SERVICE_FACTORY_H
#include<bits/stdc++.h>
#include "./PaymentService.h"
#include "./UPIPaymentStrategy.h"
#include "./CODPaymentStrategy.h"
#include "../Types/Types.h"
using namespace std;
class PaymentServiceFactory {
public:
    static PaymentService* create(PaymentStrategyType paymentStratergyType,string phoneNumber,double price) {
        if(paymentStratergyType==PaymentStrategyType::UPI)
            return new UPIPaymentStrategy(phoneNumber,price);
        else if(paymentStratergyType==PaymentStrategyType::COD)
            return new CODPaymentStrategy(phoneNumber,price);
        return nullptr;
    }
};
#endif