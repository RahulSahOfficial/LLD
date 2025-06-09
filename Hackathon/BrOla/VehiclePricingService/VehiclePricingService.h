#ifndef VEHICLE_PRICING_SERVICE_H
#define VEHICLE_PRICING_SERVICE_H
#include<bits/stdc++.h>
using namespace std;
class VehiclePricingService{
    unordered_map<string,double> vehicleTypeToPrice;
    static VehiclePricingService* instance;
    VehiclePricingService(){
        vehicleTypeToPrice["Bike"]=5;
        vehicleTypeToPrice["Sedan"]=6;
        vehicleTypeToPrice["SUV"]=6;
        vehicleTypeToPrice["AutoRikshaw"]=6;
    };
public:
    static VehiclePricingService* getInstance(){
        if(!instance)
            instance=new VehiclePricingService();
        return instance;
    }
    double getPricePerKm(const string& vehicleType){
        return vehicleTypeToPrice[vehicleType];
    }
};
VehiclePricingService* VehiclePricingService::instance=nullptr; 
#endif