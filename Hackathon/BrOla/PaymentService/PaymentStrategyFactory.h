#ifndef PAYMENT_STRATEGY_FACTORY_H
#define PAYMENT_STRATEGY_FACTORY_H
#include<bits/stdc++.h>
#include "./PaymentStrategy.h"
#include "./UPIPaymentStrategy.h"
#include "./CODPaymentStrategy.h"
#include "../Types.h"
using namespace std;
class PaymentStrategyFactory {
public:
    static PaymentStrategy* create(PaymentStrategyType paymentStratergyType,string phoneNumber,double price) {
        if(paymentStratergyType==PaymentStrategyType::UPI)
            return new UPIPaymentStrategy(phoneNumber,price);
        else if(paymentStratergyType==PaymentStrategyType::COD)
            return new CODPaymentStrategy(phoneNumber,price);
        return nullptr;
    }
};
#endif