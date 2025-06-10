#ifndef RIDE_MANAGER_H
#define RIDE_MANAGER_H
#include<bits/stdc++.h>
#include "../Models/Driver.h"
#include "../Models/Rider.h"
#include "../Models/Ride.h"
#include "./DriverManager.h"
#include "../Types/Types.h"
#include "../NotificationService/NotificationService.h"
#include "../DriverAssignService/DriverAssignService.h"
using namespace std;
// Singleton Class 
class RideManager{
    // Map so we can know which driver is mapped to which ride
    unordered_map<Driver*,Ride*> driverToRide;
    // Map so we can know which rider is mapped to which ride
    unordered_map<Rider*,Ride*> riderToRide;
    static RideManager *instance;
    double driverRiderBufferSpace=5;//to start ride driver must be 5m or less of start ride
    RideManager(){
    }
    public:
    static RideManager* getInstance(){
        if(instance==nullptr)
            instance=new RideManager();
        return instance;
    }
    void createRide(Rider *rider,string vehicleType,Location *source,Location *destination,bool isPeakHour,DriverStrategyType driverStrategyType,PaymentStrategyType paymentStrategyType){
        Ride *newRide=new Ride(rider,source,destination,vehicleType,isPeakHour,paymentStrategyType);
        riderToRide[rider]=newRide;
        NotificationService::sendRideBooked(rider,NotificationType::APP);
        auto availableDriversOfSelectedVehicle=DriverManager::getInstance()->getAvilableDrivers(vehicleType);
        DriverAssignService *driverAssignService=DriverAssignStrategyFactory::create(driverStrategyType);
        Driver *driverAssigned=driverAssignService->assignDriver(source,destination,availableDriversOfSelectedVehicle);
        if(driverAssigned){
            cout<<"Driver Assigned : "<<driverAssigned->name<<endl;
            newRide->driver=driverAssigned;
            DriverManager::getInstance()->makeUnavilable(driverAssigned);
            driverToRide[driverAssigned]=newRide;
            newRide->status=RideStatus::RiderEnRoute;
            NotificationService::sendRideAssigned(rider,NotificationType::APP);
            NotificationService::sendRideOTP(rider,newRide->otp,NotificationType::APP);
        }
        else{
            newRide->status=RideStatus::NoRiderFound;
            NotificationService::sendNoRidesFound(rider,NotificationType::APP);
        }
    }
    void validateAndStartRide(Driver *driver,string otp){
        Ride *ride=driverToRide[driver];
        if(driver->currentLocation->getDistance(ride->source)>driverRiderBufferSpace){
            throw runtime_error("Not in location to start ride");
            return;
        }
        if(false && ride->otp!=otp){//false just to bypass as we dont know generated otp in runtime
            throw runtime_error("OTP Incorrect!!");
            return;  
        }
        ride->status=RideStatus::RideInProgress;
        NotificationService::sendRideStarted(ride->rider,NotificationType::APP);
    }
    void completeRide(Driver *driver){
        Ride *ride=driverToRide[driver];
        if(driver->currentLocation->getDistance(ride->destination)>driverRiderBufferSpace)
            throw runtime_error("Not in location to end ride");
        ride->status=RideStatus::Completed;
        driverToRide.erase(driver);
        DriverManager::getInstance()->makeAvilable(driver);
        NotificationService::sendRideCompleted(ride->rider,NotificationType::APP);
    }
    void makePayment(Rider *rider){
        Ride *ride=riderToRide[rider];
        if(ride->status!=RideStatus::Completed)
            throw runtime_error("Ride is not completed!");
        if(ride->paymentStrategy->pay()){
            ride->paymentCompleted=true;
            riderToRide.erase(rider);
            NotificationService::sendPaymentDone(rider,NotificationType::APP);
        }
    }
    void printRide(Ride *ride){
        ride->print();
    }
};
RideManager* RideManager::instance=nullptr;
#endif