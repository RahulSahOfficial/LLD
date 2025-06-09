#ifndef RIDE_H
#define RIDE_H
#include<bits/stdc++.h>
#include "../Utils/Location.h"
#include "../Types/Types.h"
#include "./Driver.h"
#include "./Rider.h"
#include "../PricingService/PricingService.h"
#include "../PaymentService/PaymentStrategyFactory.h"
#include "../OtpService/OtpService.h"
using namespace std;
class Ride{
    public:
    Driver *driver;
    Rider *rider;
    Location *source;
    Location *destination;
    string vehicleType;
    string otp;
    double price;
    RideStatus status;
    bool isPeakHour;
    PaymentStrategy *paymentStrategy;
    bool paymentCompleted;
    Ride(Rider *rider,Location *source,Location *destination,string vehicleType,bool isPeakHour,PaymentStrategyType paymentStrategyType){
        this->driver=nullptr;
        this->rider=rider;
        this->source=source;
        this->vehicleType=vehicleType;
        this->destination=destination;
        this->isPeakHour=isPeakHour;
        this->paymentCompleted=false;
        this->status=RideStatus::AssigningRider;
        this->otp=OtpService::generateOtp(4);
        this->price=calculatePrice();
        this->paymentStrategy=PaymentStrategyFactory::create(paymentStrategyType,rider->phoneNumber,price);
    }
    double calculatePrice(){
        double distance=source->getDistance(destination);
        FareCalculator *calc=new BaseFareCalculator();
        if(isPeakHour)
            calc=new SurgeDecorator(calc);
        return calc->calculatePrice(distance,vehicleType);
    }
    void print(){
        cout<<"Ride : "<<endl;
        cout<<"Driver : "<<driver<<endl;
        cout<<"Rider : "<<rider<<endl;
        cout<<"Source : "<<endl;
        source->print();
        cout<<"Destination : "<<endl;
        destination->print();
        cout<<"Vehicle Type : "<<vehicleType<<endl;
        cout<<"OTP : "<<otp<<endl;
        cout<<"Price : "<<price<<endl;
        cout<<"status : "<<rideStatusToString(status)<<endl;
        cout<<"isPeakHour : "<<isPeakHour<<endl;
        cout<<"Payment Completed : "<<paymentCompleted<<endl;
    }
};
#endif