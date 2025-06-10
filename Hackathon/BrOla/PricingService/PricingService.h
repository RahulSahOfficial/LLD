#ifndef PRICING_SERVICE_H
#define PRICING_SERVICE_H
#include<bits/stdc++.h>
#include "../VehiclePricingService/VehiclePricingService.h"
using namespace std;
class FareCalculator{
    public:
    virtual double calculatePrice(double,string)=0;
};
class BaseFareCalculator:public FareCalculator{
    double basePrice;
    public:
    BaseFareCalculator(){
        basePrice=49;
    }
    double calculatePrice(double distance,string vehicleType) override {
        double pricePerKm=VehiclePricingService::getInstance()->getPricePerKm(vehicleType);
        double price=basePrice+distance*pricePerKm;
        return price;
    }
};
// Decorator 
class PriceDecorator:public FareCalculator{
    public:
    FareCalculator *fc;
    PriceDecorator(FareCalculator *fc){
        this->fc=fc;
    }
};
// Surge Price Decorator
class SurgeDecorator:public PriceDecorator{
    double surgeMultiplier;
    public:
    SurgeDecorator(FareCalculator *fc):PriceDecorator(fc){
        surgeMultiplier=1.05;    
    };
    double calculatePrice(double distance,string vehicleType) override{
        return fc->calculatePrice(distance,vehicleType)*surgeMultiplier;
    }
};
#endif